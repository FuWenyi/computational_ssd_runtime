#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "encoding.h"
#include "pcb.h"
#include "clint.h"

#define MACHINE_TIMER_INTERRUPT 0x8000000000000007

//extern pcb_t* fwyfwy_pcb[MAX_PCB_SIZE];
//extern pcb_t* fwy_cur_pcb;
//int fwy_total_pcb_num;
pcb_t* pcb[MAX_PCB_SIZE];
pcb_t mem_pcb[4];
pcb_t* cur_pcb;
int total_pcb_num;

void add_mtimecmp() {
    uint64_t mtimecmp = *(volatile uint64_t *)(CLINT_BASE + MTIMECMP_OFF);
    *(volatile uint64_t *)(CLINT_BASE + MTIMECMP_OFF) = mtimecmp + TIME_INTERVAL;
}

void scheduler() {
    int pid = cur_pcb->pid;
    int next_pid = ((pid + 1) == total_pcb_num) ? 0 : pid + 1; 
    cur_pcb = pcb[next_pid];    
}

static void handle_timer_interrupt() {
    //reserve the old epc, because it is interrupt, epc should point to next one
    cur_pcb->mepc = read_csr(mepc);

    //remove the old pmp R|W access
    if (!cur_pcb->priority) {
        uintptr_t pmpcfg = read_csr(pmpcfg0);
        uintptr_t cfg = PMP_NAPOT;
        uintptr_t cfg_idx = cur_pcb->data_pmpcfg_idx;
        uintptr_t mask = 0xff << (cfg_idx * 8);
        pmpcfg = (pmpcfg & ~mask) | ((cfg << (cfg_idx * 8)) & mask);
        write_csr(pmpcfg0, pmpcfg);
    }

    //schedule the thread
    scheduler();

    //enable the new app pmp R|W access
    if (!cur_pcb->priority) {
        uintptr_t pmpcfg = read_csr(pmpcfg0);
        uintptr_t cfg = PMP_NAPOT | PMP_W | PMP_R;
        uintptr_t cfg_idx = cur_pcb->data_pmpcfg_idx;
        uintptr_t mask = 0xff << (cfg_idx * 8);
        pmpcfg = (pmpcfg & ~mask) | ((cfg << (cfg_idx * 8)) & mask);
        write_csr(pmpcfg0, pmpcfg);
    }

    //need to rearrange new mepc
    write_csr(mepc, cur_pcb->mepc);

    //TODO: handle mtime mtimecmp
    add_mtimecmp();
}

static void handle_access_fault(uintptr_t cause) {
    switch (cause) {
        case CAUSE_FETCH_ACCESS: exit(2);
        case CAUSE_LOAD_ACCESS:  exit(3);
        case CAUSE_STORE_ACCESS: exit(4);
        default: exit(5);
    }
}

uintptr_t handle_trap(uintptr_t cause, uintptr_t epc, uintptr_t regs[32]) {
    switch (cause) {
        case MACHINE_TIMER_INTERRUPT: handle_timer_interrupt(); break;
        case CAUSE_FETCH_ACCESS: 
        case CAUSE_LOAD_ACCESS:
        case CAUSE_STORE_ACCESS: handle_access_fault(cause); break;
        default: exit(1);
    }
}
