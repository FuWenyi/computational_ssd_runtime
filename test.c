#include <stdio.h>
#include <stdint.h>
#include "pcb.h"

//extern pcb_t* fwyfwy_pcb[MAX_PCB_SIZE];
//extern pcb_t* cur_pcb;

void ftl() {
    //TODO:适配ftl
    while(1) {
        ;
    }
}

void app1() {
    printf("I am a disciplined app! I will not read other apps addr space!!!\n");
    uintptr_t addr_low = cur_pcb->access_addr_low;
    uintptr_t addr_hign = cur_pcb->access_addr_high;
    uintptr_t access_addr = addr_low;
    *(int *)access_addr = 0x0;
    int data = *(int *)access_addr;
    printf("look!!! It all right!!!\n");
}

void malware() {
    printf("My role is to destory the world! I will read app1's data hhhhhhh\n");
    uintptr_t addr_low = pcb[1]->access_addr_low;
    uintptr_t addr_hign = pcb[1]->access_addr_high;
    uintptr_t access_addr = addr_low;
    *(int *)access_addr = 0x0;
    int data = *(int *)access_addr;
    printf("hhhhhh I am the king of the world!!!\n");
}