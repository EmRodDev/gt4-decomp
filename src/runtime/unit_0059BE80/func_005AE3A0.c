/* compiler: ee-gcc2.9-991111 */
/* Adjust the shared heap break under interrupt exclusion. The upper limit is
 * queried from the kernel; failure sets errno to ENOMEM and retains the break. */
extern unsigned D_006582A4;
extern unsigned func_005ADC80(void);
extern int *func_005A3130(void);
static inline unsigned cpu_status(void) {
    unsigned value;
    __asm__ volatile("mfc0 %0, $12" : "=r"(value));
    return value;
}
static inline void disable_interrupts(void) { __asm__ volatile("di" ::: "memory"); }
static inline void synchronize_pipeline(void) { __asm__ volatile("sync.p" ::: "memory"); }
static inline void enable_interrupts(void) { __asm__ volatile("ei" ::: "memory"); }
void *func_005AE3A0(int increment) {
    unsigned enabled;
    unsigned next;
    __asm__ volatile("mfc0 %0, $12" : "=r"(enabled));
    enabled&=0x10000;
    if(enabled) {
        do {
            disable_interrupts();
            synchronize_pipeline();
        } while(cpu_status()&0x10000);
    }
    next=D_006582A4+increment;
    if(func_005ADC80()<next) {
        *func_005A3130()=12;
        if(enabled) enable_interrupts();
        return (void *)-1;
    } else {
        void *previous=(void *)D_006582A4;
        D_006582A4=next;
        if(enabled) enable_interrupts();
        return previous;
    }
}
