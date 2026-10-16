struct Block { char b[48]; };
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" int func_005ADBA0(int,Block *);
extern "C" int func_005205B0(int handle,Block *out,unsigned int size,int *written) {
    int r=2;
    if (!written) return r;
    *written=0;
    if (!out) return r;
    if (size<48) return r;
    Block b;
    func_005A48D8(&b,0,48);
    if (func_005ADBA0(handle,&b)!=-1) {
        *out=b;
        *written=48;
    }
    return 0;
}
