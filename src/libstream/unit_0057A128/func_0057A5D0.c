typedef unsigned char u8;
struct Buf { u8 *base; };
void func_0057A5D0(struct Buf *b, int off, int add) {
    u8 *p = b->base + off;
    add += (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24);
    p[0] = add;
    p[1] = add >> 8;
    p[2] = add >> 16;
    p[3] = add >> 24;
}
