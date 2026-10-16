extern "C" short func_0056D2D8(int) throw() __attribute__((const));
extern "C" void func_0056D3B0(int src, short *out, int n, int mem) {
    mem += (-mem & 15);
    mem += n*2;
    int *last = 0;
    int half = n >> 1;
    short *coef = (short *)(mem - n*2);
    int j;
    for (j=0; j<n; j++) coef[j] = func_0056D2D8(*(short *)(src+j*2))*4;
    int count = half*4;
    mem += (-mem & 15);
    int *state = (int *)mem;
    int *p=state;
    if(count+1>=0) {
        j=count+2;
        do { j--; *p=0; p++; } while(j!=0);
    }
    int a=0x100000, b=0x100000;
    if(n>=0) {
    int i=n+1;
    short *dest=out;
    do {
        if(half>0) {
        short *c=coef;
        int *s=state;
        j=half;
        do {
            int x=s[0];
            j--;
            last=s+3;
            int y=s[2];
            int ca=c[0], cb=c[1];
            c+=2;
            int ax=ca*(x&0x3fff), by=cb*(y&0x3fff);
            int ah=ca*(x>>14), bh=cb*(y>>14);
            int oldb=last[0], olda=s[1];
            s[1]=x; last[0]=y;
            ah+=ax>>14; bh+=by>>14;
            ah=a-ah; bh=b-bh;
            s[0]=a; s[2]=b;
            b=bh+oldb; a=ah+olda;
            s+=4;
        } while(j!=0);
        }
        int v=a+last[1]+(b-last[2]);
        if(v>0x7ffe00) *dest=0x7fff;
        else if(v<(int)0xff800100) *dest=-0x8000;
        else *dest=(v+128)>>8;
        last[1]=a; last[2]=b;
        b=0; a=0;
        i--;
        dest++;
    } while(i!=0);
    }
}
