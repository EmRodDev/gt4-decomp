extern char D_00617AB0[], D_00617BB0[], D_00617AA8[], D_0068BB98[], D_0068BBA8[];
extern const int D_0068BB24;
extern "C" void func_004ACAB0(void *,int);
extern "C" void func_004ACC28(void *,int,int,void *,void *,int);
static inline bool is_mode0(int mode) { return mode==0; }
extern "C" void func_00100D10(int mode,int key) {
 if(key==0xffff && mode==1) func_004ACC28(D_00617AB0,0,D_0068BB24,D_0068BB98,0,1);
 if(key==0xffff && mode==1) func_004ACC28(D_00617BB0,1,D_0068BB24,D_0068BBA8,D_00617AA8,0);
 if(key==0xffff && is_mode0(mode)) func_004ACAB0(D_00617BB0,2);
 if(key==0xffff && mode==0) func_004ACAB0(D_00617AB0,2);
}
