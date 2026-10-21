typedef unsigned short u16;
typedef unsigned char u8;
extern "C" void func_004C3288(int unused, int base, u8 *data, u16 *out) {
    int count = data[2] & 15;
    int v = 1;
    unsigned off = ((data[2] & 0xf0) << 12) | (data[0] << 8) | data[v];
    int skip = data[4] >> 6;
    int n = count - skip;
    u16 *src = (u16 *)(base + ((off >> v) * 2));
    u16 *dst = out + skip;
    if(n > 0) do {
        u16 val = *src++;
        --n;
        *dst++ = val;
    } while(n != 0);
    src = (u16 *)(base + ((off >> v) * 2));
    if(skip > 0) {
        while(!(*src & 0x8000)) --src;
        dst = out;
        for(n=0; n<skip; n++) *dst++ = *src++;
    }
    dst = out;
    if(count) {
        n=count;
        do {
            u16 val = *dst;
            if ((val & 0x7f00) == 0x1000) {
                *dst = val & 0xff;
                --n;
            } else {
                *dst = val | 0x8000;
                --n;
            }
            ++dst;
        }while(n!=0);
    }
    *dst = 0;
}
