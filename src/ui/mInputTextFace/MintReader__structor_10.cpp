/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

struct Reader {
    union { void *vtbl; s32 word; } u;
    void *dst;
    char pad8[8];
};

struct Obj {
    char pad0[0xB0];
    f32 padLeft;
    f32 padRight;
    f32 padTop;
    f32 padBottom;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
#define STR_BUILD(SRC) \
    { \
        const char *src = SRC; \
        Rep *r = &D_00659FA8; \
        char *d; \
        if (r->sel != 0) { \
            d = func_005C2560(r); \
        } else { \
            d = (char *)(r + 1); \
            r->ref++; \
        } \
        ps->p = d; \
        func_005C2630(ps, 0, -1, src, func_0057F260(src)); \
    }

#define STR_RELEASE() \
    { \
        Rep *q = (Rep *)(ps->p - 0x10); \
        if (--q->ref == 0) { \
            s32 cap = q->cap + 0x10; \
            func_00326798(q, cap, 4, func_005C11A8()->name); \
        } \
    }


extern "C" int mSlideShowFace__virtual_61(void *,void *);
extern "C" int MboolReader__structor_7(void *,void *);
extern "C" int func_002030A0(void *);
extern "C" void *func_002030E8(void *,void *);
extern "C" void func_00203118(void *,int);
extern "C" int MColorReader__structor_0(void *,void *);
extern "C" void MColorReader__structor_1(void *,int);
extern "C" int func_0020FD38(void *,Str *,Reader *);
extern "C" void MReaderBase__structor_0(void *,int);
extern "C" void func_002A6C98(void *,int) throw();
extern char MintReader__vtable[];
inline int readColor(void *node, Str *ps, Reader *pr, void *color) {
 MColorReader__structor_0(pr,color);
 int ok=func_0020FD38(node,ps,pr);
 MColorReader__structor_1(pr,2);
 return ok;
}
inline int readInt(void *node, Str *ps, Reader *pr, int *value) {
 pr->u.vtbl=MintReader__vtable; pr->dst=value;
 int ok=func_0020FD38(node,ps,pr);
 pr->u.vtbl=MintReader__vtable; MReaderBase__structor_0(pr,0);
 return ok;
}
extern "C" int MintReader__structor_10(char *self,void *node) {
 float color[4];
 Str s;
 Reader r1,r2,r3,r4;
 int value;
 Str *ps;
 if(mSlideShowFace__virtual_61(self,node)) return 1;
 if(MboolReader__structor_7(self+0xA0,node)) return 1;
 func_002030A0(color);
 ps=&s;
 {
 int ok; Reader *pr;
 STR_BUILD("inputting_color")
 pr=&r1;
 ok=readColor(node,ps,pr,color);
 STR_RELEASE()
 if(ok) {
 func_002030E8(self+0x104,color);
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("conversion_color")
 pr=&r2;
 ok=readColor(node,ps,pr,color);
 STR_RELEASE()
 if(ok) {
 func_002030E8(self+0x114,color);
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("selecting_color")
 pr=&r3;
 ok=readColor(node,ps,pr,color);
 STR_RELEASE()
 if(ok) {
 func_002030E8(self+0x124,color);
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("boxbg_color")
 pr=&r4;
 ok=readColor(node,ps,pr,color);
 STR_RELEASE()
 if(ok) {
 func_002030E8(self+0x134,color);
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("boxcursor_color")
 pr=&r1;
 ok=readColor(node,ps,pr,color);
 STR_RELEASE()
 if(ok) {
 func_002030E8(self+0x144,color);
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("error_color")
 pr=&r1;
 ok=readColor(node,ps,pr,color);
 STR_RELEASE()
 if(ok) {
 func_002030E8(self+0x154,color);
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("input_mode")
 pr=&r1;
 ok=readInt(node,ps,pr,&value);
 STR_RELEASE()
 if(ok) {
 *(int *)(self+0x164)=value;
 func_00203118(color,2); return 1;
 }
 }
 {
 int ok; Reader *pr;
 STR_BUILD("max_input_length")
 pr=&r1;
 ok=readInt(node,ps,pr,&value);
 STR_RELEASE()
 if(ok) {
 func_002A6C98(self,value);
 func_00203118(color,2); return 1;
 }
 }
func_00203118(color,2); return 0;
}
