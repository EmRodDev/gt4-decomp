extern signed char dwarf_reg_size_table[];

extern "C" int get_reg_addr(int ch, int a, int b);
extern "C" int memcpy(int a, int b, int c);

extern "C" int copy_reg(int ch, int a, int b) {
    int x = get_reg_addr(ch, a, 0);
    int y = get_reg_addr(ch, b, 0);
    return memcpy(y, x, dwarf_reg_size_table[ch]);
}
