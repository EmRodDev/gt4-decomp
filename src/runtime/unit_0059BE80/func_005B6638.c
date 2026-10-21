/* compiler: ee-gcc2.9-991111 */
struct Buf { int size,result; char name[252]; char args[252]; };
extern struct Buf D_00889C80;
extern int D_00889E80;
int func_005B6268(void),func_005B6368(void);
void *func_005A4724(void *,const void *,unsigned int);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_005B6638(int buffer,int arglen,const void *args,int *result) {
    if(func_005B6268()<0) return -0x10000;
    if(func_005B6368()) return -0x10004;
    D_00889C80.size=buffer;
    if(args) {
        if(arglen>252) {
            __builtin_memcpy(D_00889C80.args,args,252);
            D_00889C80.result=252;
        } else {
            func_005A4724(D_00889C80.args,args,arglen);
            D_00889C80.result=arglen;
        }
    } else {
        D_00889C80.result=0;
    }
    if(func_005B19B0(&D_00889E80,7,0,&D_00889C80,512,&D_00889C80,8,0,0)<0) return -0x10001;
    { int ret=D_00889C80.size;
    *result=D_00889C80.result;
    return ret; }
}
