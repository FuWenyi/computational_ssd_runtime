#include <stdio.h>
#include <stdint.h>
#include "pcb.h"
#include "encoding.h"

#define MSTATUS_USER 0

//extern pcb_t* fwyfwy_pcb[MAX_PCB_SIZE];
//extern pcb_t* cur_pcb;

void ftl() {
    //TODO:适配ftl
    while(1) {
        ;
    }
}

void test_one(uintptr_t addr, uintptr_t size)
{
  uintptr_t new_mstatus = (read_csr(mstatus) & ~MSTATUS_MPP) | (MSTATUS_MPP & MSTATUS_USER) | MSTATUS_MPRV;
  switch (size) {
    case 1: asm volatile ("csrrw %0, mstatus, %0; lb x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
    case 2: asm volatile ("csrrw %0, mstatus, %0; lh x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
    case 4: asm volatile ("csrrw %0, mstatus, %0; lw x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
#if __riscv_xlen >= 64
    case 8: asm volatile ("csrrw %0, mstatus, %0; ld x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
#endif
    default: __builtin_unreachable();
  }
}

void app1() {
    //printf("I am a disciplined app! I will not read other apps addr space!!!\n");
    uintptr_t addr_low = cur_pcb->access_addr_low;
    uintptr_t addr_hign = cur_pcb->access_addr_high;
    uintptr_t access_addr = addr_low;
    test_one(access_addr, 8);
    //*(int *)access_addr = 0x0;
    //int data = *(int *)access_addr;
    while(1){
        ;
    }
    //printf("look!!! It all right!!!\n");
}

void malware() {
    //printf("My role is to destory the world! I will read app1's data hhhhhhh\n");
    uintptr_t addr_low = pcb[1]->access_addr_low;
    uintptr_t addr_hign = pcb[1]->access_addr_high;
    uintptr_t access_addr = addr_low;
    test_one(access_addr, 8);
    //*(int *)access_addr = 0x0;
    //int data = *(int *)access_addr;
    while(1){
        ;
    }
    //printf("hhhhhh I am the king of the world!!!\n");
}