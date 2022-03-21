#define NAME_MAX_LENGTH 30
#define MAX_PCB_SIZE 5

#define bool int
#define true 1
#define false 0

#define APP1_ADDR_LOW  0x81000000
#define APP1_ADDR_HIGH 0x81800000
#define APP2_ADDR_LOW  0x81800000
#define APP2_ADDR_HIGH 0x82000000

typedef struct {
    int pid;                            //pcd id
    char* name;         //application name
    bool priority;                      //true for ftl, false for app
    uintptr_t access_addr_low;          //low bound for phy addr
    uintptr_t access_addr_high;         //high bound for phy addr
    int pmpcfg_idx;                     //the corresponding pmpcfg index
    void* app_entry;                    //the entry address of this app
    uintptr_t mepc;                      //restore epc
} pcb_t;

extern pcb_t* pcb[MAX_PCB_SIZE];
extern pcb_t* cur_pcb;
extern int total_pcb_num;