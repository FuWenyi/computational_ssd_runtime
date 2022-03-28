#define HISTOGRAM_DATA_SIZE 0x100000
extern char scratch1[RISCV_PGSIZE / sizeof(char)];
extern int scratch2[HISTOGRAM_DATA_SIZE / sizeof(int)];
extern char scratch3[RISCV_PGSIZE / sizeof(char)];
void ftl();
void app1();
void app2();
void malware();