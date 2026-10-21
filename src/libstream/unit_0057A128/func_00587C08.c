/* compiler: ee-gcc2.9-991111 */
struct Request {
    unsigned char mode;
    char pad[3];
    int id, thread;
    char *path;
    int x10,x14,x18,x1c;
    int argc;
    void *argv;
    int *result;
    int status;
    int x30,x34;
    unsigned int newargc;
    void *newargv;
};
struct Module { int x0,x4,x8,id; };
extern struct { int a,b; } D_0087E180;
extern struct Module *func_00589678(struct Request *, int *);
extern struct Module *func_0058B210(int);
extern int func_00587F88(struct Module *, char *, int, void *, int *);
extern int func_00588468(struct Module *, int, int, void *, int *);
extern int func_00588878(struct Module *);
extern int func_0057F260(const char *);
extern char *func_005A609C(char *,const char *);
extern void *func_005A4724(void *,const void *,unsigned);
extern void func_005ADB30(int,int);
extern void func_005ADAF0(int);
extern void func_005ADAB0(int);
int func_00587C08(struct Request *p) {
    struct Request copy;
    int err;
    struct Module *m;
    switch(p->mode) {
    case 0: case 1: case 2: case 3:
        m=func_00589678(p,&err);
        func_005ADB30(D_0087E180.a,D_0087E180.b);
        if(err) p->status=err;
        else {
            p->status=m->id;
            if(p->mode==2 || p->mode==3) {
                err=func_00587F88(m,p->path,p->argc,p->argv,p->result);
                if(err) { p->status=err; func_00588878(m); }
            }
        }
        break;
    case 4:
        m=func_0058B210(p->id);
        if(m) {
            p->status=m->id;
            err=func_00587F88(m,p->path,p->argc,p->argv,p->result);
            if(err) p->status=err;
        } else p->status=0x8105902d;
        break;
    case 5: case 6: case 7: case 8: case 9:
        m=func_0058B210(p->id);
        if(!m) { p->status=0x8105902d; break; }
        if(p->mode==9) {
            copy=*p;
            copy.path=__builtin_alloca(func_0057F260(p->path)+1);
            func_005A609C(copy.path,p->path);
            copy.newargv=__builtin_alloca(p->newargc);
            func_005A4724(copy.newargv,p->newargv,p->newargc);
        }
        p->status=m->id;
        if(p->mode==5 || p->mode==7 || p->mode==8 || p->mode==9) {
            err=func_00588468(m,p->mode,p->argc,p->argv,p->result);
            if(err) p->status=err;
        }
        if(p->mode>=6 && p->mode<=9 && p->status>=0) {
            err=func_00588878(m);
            if(err) p->status=err;
            if((p->mode==8 || p->mode==9) && p->status>=0) {
                int thread=p->thread;
                func_005ADB30(D_0087E180.a,D_0087E180.b);
                func_005ADAF0(thread);
                func_005ADAB0(thread);
                if(copy.mode==9) {
                    do {
                        m=func_00589678(&copy,&err);
                        if(err==0) {
                            err=func_00587F88(m,copy.path,copy.newargc,copy.newargv,0);
                            if(err) func_00588878(m);
                        }
                    } while(err);
                }
                return 1;
            }
        }
        break;
    default: for(;;) {}
    }
    return 0;
}
