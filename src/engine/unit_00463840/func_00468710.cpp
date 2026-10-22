/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Fills a 32-entry u16 table (the first 0x40 bytes of table are cleared by func_005A48D8 first). Rows 0..2 (first
 * 24 entries) copy 8 values each from the array returned by func_004683A8, reading base[column + row*64 + col*8];
 * column comes from func_00468418(level) (a float to int conversion; marked const so the compiler may drop
 * repeats), and when column is 0 the last value of each row is skipped (left as 0). Then a record is looked up
 * with func_00433C10 in the table at D_00622F4C + 0x14A30 using the key (through func_00468690); if it exists, two
 * rows of four bytes from record+0x228 go into entries 24..31, shifted left by 8. What the table is used for is
 * unknown. */
typedef unsigned short u16;
typedef unsigned char u8;
extern char *D_00622F4C;
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" u16 *func_004683A8() throw();
extern "C" int func_00468418(float) throw() __attribute__((const));
extern "C" void *func_00468690(void *, void *) throw();
extern "C" char *func_00433C10(void *, void *);
static inline void copy_row(u16 *table, u16 *base, int column, int row) {
    for (int col = 0; col < 8; col++) {
        if (column != 0 || col != 7) table[row * 8 + col] = base[column + row * 64 + col * 8];
    }
}
static inline void copy_tail_row(u16 *table, u8 *extra, int row) {
    for (int col = 0; col < 4; col++) {
        table[24 + row * 4 + col] = extra[row * 4 + col] << 8;
    }
}
extern "C" void func_00468710(u16 *table, void *key, float level) {
    char keyScratch[16];
    func_005A48D8(table, 0, 0x40);
    u16 *base = func_004683A8();
    int column = func_00468418(level);
    int row = 0;
    do {
        copy_row(table, base, column, row);
        row++;
    } while (row < 3);
    char *record = func_00433C10(D_00622F4C + 0x14a30, func_00468690(keyScratch, key));
    if (record) {
        u8 *extra = (u8 *)record + 0x228;
        for (row = 0; row < 2; row++) {
            copy_tail_row(table, extra, row);
        }
    }
}
