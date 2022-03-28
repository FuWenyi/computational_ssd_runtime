#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
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

//kmp test1: 大致大小 4KB
char scratch1[RISCV_PGSIZE / sizeof(char)] __attribute__((aligned(RISCV_PGSIZE))) = "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfy"
                                             "gyigduewidlgfwigfywigcsbhcbdvjskfufvfgfyh"
                                          ;

int kmp(const char *text, const char *find)  
{  
    if (text[0] == '\0' || find[0] == '\0')  
        return -1;  
    int find_len = strlen(find);  
    int text_len = strlen(text);  
    if (text_len < find_len)  
        return -1;  
    int map[find_len];  
    memset(map, 0, find_len*sizeof(int));  
    //initial the kmp base array: map  
    map[0] = 0;  
    map[1] = 0;  
    int i = 2;  
    int j = 0;  
    for (i=2; i<find_len; i++)  
    {  
        while (1)  
        {  
            if (find[i-1] == find[j])  
            {  
                j++;  
                if (find[i] == find[j])  
                {  
                    map[i] = map[j];  
                }  
                else  
                {  
                    map[i] = j;  
                }  
                break;  
            }  
            else  
            {  
                if (j == 0)  
                {  
                    map[i] = 0;  
                    break;  
                }  
                j = map[j];  
            }  
        }  
    }  
    i = 0;  
    j = 0;  
    for (i=0; i<text_len;)  
    {  
        if (text[i] == find[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            j = map[j];  
            if (j == 0)  
                i++;  
        }  
        if (j == (find_len))  
            return i-j;  
    }  
    return -1;  
}  

void test_one(uintptr_t addr, uintptr_t size)
{
  uintptr_t new_mstatus = (read_csr(mstatus) & ~MSTATUS_MPP) | (MSTATUS_MPP & MSTATUS_USER) | MSTATUS_MPRV;
  switch (size) {
    case 1: asm volatile ("csrrw %0, mstatus, %0; sb x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
    case 2: asm volatile ("csrrw %0, mstatus, %0; sh x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
    case 4: asm volatile ("csrrw %0, mstatus, %0; sw x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
#if __riscv_xlen >= 64
    case 8: asm volatile ("csrrw %0, mstatus, %0; sd x0, (%1); csrw mstatus, %0" : "+&r" (new_mstatus) : "r" (addr)); break;
#endif
    default: __builtin_unreachable();
  }
}

void M_to_UMode() {
    uintptr_t new_mstatus = (read_csr(mstatus) & ~MSTATUS_MPP) | (MSTATUS_MPP & MSTATUS_USER) | MSTATUS_MPRV;
    write_csr(mstatus, new_mstatus);
}

void app1() {
    //printf("I am a disciplined app! I will not read other apps addr space!!!\n");
    //come to user mode
    M_to_UMode();
    char find[] = "gfyh";
    int num = kmp(scratch1, find);
    if (num == 3997) {
        //进入摆烂死循环
        //exit(7);
        while (1) {
            ;
        } 
    } 
    else {
        exit(6);
    }

    //uintptr_t addr_low = pcb[1]->access_data_addr_base;
    //test_one(addr_low, 8);
    while(1){
        ;
    }
    //printf("look!!! It all right!!!\n");
}

void malware() {
    //printf("My role is to destory the world! I will read app1's data hhhhhhh\n");
    uintptr_t addr_low = pcb[1]->access_data_addr_base;
    uintptr_t addr_hign = pcb[1]->access_data_addr_base + pcb[1]->access_data_addr_size;
    uintptr_t access_addr = addr_low;
    test_one(access_addr, 8);
    //*(int *)access_addr = 0x0;
    //int data = *(int *)access_addr;
    while(1){
        ;
    }
    //printf("hhhhhh I am the king of the world!!!\n");
}