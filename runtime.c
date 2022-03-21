#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "encoding.h"
#include "pcb.h"
#include "clint.h"
#include "test.h"

void wr_mtime(uintptr_t mtime) {
    *(volatile uint64_t *)(CLINT_BASE + MTIME_OFF) = mtime;
}

void wr_mtimecmp(uintptr_t mtimecmp) {
    *(volatile uint64_t *)(CLINT_BASE + MTIMECMP_OFF) = mtimecmp;
}

static void init_satp() {
    //STAP_MODE_OFF禁用virtual memory
#if __riscv_xlen == 64
    uintptr_t vm_choice = SATP_MODE_OFF;
#else
    uintptr_t vm_choice = SATP_MODE_OFF;
#endif
    //SATP_MODE:0xF000000000000000 & ~(SATP_MODE<<1) 0x1fffffffffffffff = 0x1000 0000 0000 0000
    write_csr(sptbr, vm_choice * (SATP_MODE & ~(SATP_MODE<<1)));
}

//extern pcb_t* fwyfwy_pcb[MAX_PCB_SIZE];
//extern pcb_t* fwy_cur_pcb;
//int fwy_total_pcb_num;

static void init_pcb() {
    pcb_t* temp_pcb;
    pcb_t mem_pcb[3];
    for (int i = 0; i < 3; i ++) {
        //temp_pcb = (pcb_t *)malloc(sizeof(pcb_t));
        temp_pcb = (pcb_t *)&mem_pcb[i];
        temp_pcb->pid = i;
        pcb[i] = temp_pcb; 
    }

    //init_ftl
    temp_pcb = pcb[0];
    char ftl1[4] = "ftl";
    temp_pcb->name = ftl1;
    temp_pcb->priority = true;
    temp_pcb->access_addr_low = 0x0;
    temp_pcb->access_addr_high = 0xffffffff;
    temp_pcb->pmpcfg_idx = 0;
    temp_pcb->app_entry = ftl;
    temp_pcb->mepc = (uintptr_t)ftl;

    //init app1
    temp_pcb = pcb[1];
    char app1[5] = "app1";
    temp_pcb->name = app1;
    temp_pcb->priority = false;
    temp_pcb->access_addr_low = APP1_ADDR_LOW;
    temp_pcb->access_addr_high = APP1_ADDR_HIGH;
    temp_pcb->pmpcfg_idx = 3;
    temp_pcb->app_entry = app1;
    temp_pcb->mepc = (uintptr_t)app1;

    //init app2
    temp_pcb = pcb[1];
    char malware[8] = "malware";
    temp_pcb->name = malware;
    temp_pcb->priority = false;
    temp_pcb->access_addr_low = APP2_ADDR_LOW;
    temp_pcb->access_addr_high = APP2_ADDR_HIGH;
    temp_pcb->pmpcfg_idx = 4;
    temp_pcb->app_entry = malware;
    temp_pcb->mepc = (uintptr_t)malware;

    cur_pcb = pcb[0];
    total_pcb_num = 3;
}

static void init_pmp() {
    //pmpcfg1 pmpaddr0 pmpaddr1 reserved for ftl mapping table
    write_csr(pmpcfg0, 0);
    write_csr(pmpcfg2, 0);
#if __riscv_xlen == 32
    write_csr(pmpcfg1, 0);
    write_csr(pmpcfg3, 0);
#endif

    uintptr_t cfg;
    uintptr_t mask;
    int cfg_idx;

    //init app1 addr bound: pmpcfg3 pmpaddr2 pmpaddr3
    cfg = PMP_TOR | PMP_W | PMP_R;
    cfg_idx = pcb[1]->pmpcfg_idx;
    write_csr(pmpcfg0, cfg << (cfg_idx * 8));
    write_csr(pmpaddr2, APP1_ADDR_LOW >> PMP_SHIFT);
    write_csr(pmpaddr3, APP1_ADDR_HIGH >> PMP_SHIFT);

    //init app2 addr bound: pmpcfg4 pmpaddr3 pmpaddr4
    cfg_idx = pcb[2]->pmpcfg_idx;
    write_csr(pmpcfg0, cfg << (cfg_idx * 8));
    write_csr(pmpaddr3, APP2_ADDR_LOW >> PMP_SHIFT);
    write_csr(pmpaddr4, APP2_ADDR_HIGH >> PMP_SHIFT);
}

static void init_csr() {
    //mstatus.MIE开中断 MIE: machine mode global interrupt enable
    uintptr_t new_mstatus = read_csr(mstatus);
    new_mstatus |= MSTATUS_MIE;
    write_csr(mstatus, new_mstatus);

    //TODO:init_timer
    wr_mtimecmp(TIME_INTERVAL);
    wr_mtime(0);
}

static void init_into_entry() {
    //将ra寄存器的入口地址设为ftl
    uintptr_t entry_addr = (uintptr_t)ftl;
    asm volatile ("ld x1, (%0)" : "=r" (entry_addr));
    asm volatile ("ret");
}

int main() {
    // 1.disable virtual memory
    init_satp();   

    // 2.init pcb
    init_pcb();

    // 3.init pmp
    init_pmp();

    init_csr();

    init_into_entry();
    
    exit(0);
}