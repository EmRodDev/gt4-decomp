/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script method getEntryCarCode(entry): returns a two-element script array built from the 0x68-byte entry record number args[0] (virtual slot +0x58 gives the integer): element 0 is the code string stored at +0xE0 of the record, element 1 the number at +0x48 of the record at +0xD8 (the car code and some per-entry value; what the second one means is not determined). Result is assigned into *out. */
typedef int s32;
struct Rep { s32 len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Name { const char *name; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
extern Rep D_00659FA8;
extern "C" void func_0015F3E0(void *,void *) throw();
extern "C" void func_0015F388(void *,int) throw();
extern "C" void func_002EFC48(void *,int);
extern "C" s32 *HArray__operator_index(void *,int);
extern "C" void func_002ED5C0(void *,int);
extern "C" void func_002FC870(void *,int);
extern "C" void func_002FE278(void *,s32);
extern "C" void func_00312318(void *,int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(void *,int,int,const char *,int);
extern "C" Name *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline void assign(s32 *dst,s32 *src) {
    if(dst!=src) { s32 n=*src; if(n) func_003285A8(n); s32 o=*dst; if(o) func_003285F8(o); *dst=n; }
}
static inline void release(Str *s) {
    Rep *q=(Rep *)(s->p-16);
    if(--q->ref==0) { s32 size=q->cap+16; func_00326798(q,size,4,func_005C11A8()->name); }
}
extern "C" void MGame__getEntryCarCode(s32 *out,void *object,int argCount,Obj **args) {
    s32 array[4]; s32 element[4]; Str codeStr;
    if(argCount>0) {
        func_0015F3E0(array,object);
        Obj *entryArg=*args;
        VEntry *indexSlot=(VEntry *)(entryArg->vtbl+0x58);
        char *entryRecord=*(char **)((char *)array[0]+0x10);
        entryRecord+=indexSlot->fn((char *)entryArg+indexSlot->delta)*0x68;
        func_0015F388(array,2);
        func_002EFC48(array,2);
        char *entryHeader=entryRecord+0xD8;
        s32 *slot=HArray__operator_index(array,0);
        char *source=entryRecord+0xE0;
        Str *codeStrPtr=&codeStr;
        Rep *emptyRep=&D_00659FA8;
        char *chars;
        if(emptyRep->sel) chars=func_005C2560(emptyRep);
        else { chars=(char *)(emptyRep+1); emptyRep->ref++; }
        codeStrPtr->p=chars;
        func_005C2630(codeStrPtr,0,-1,source,func_0057F260(source));
        source=(char *)element;
        func_00314B20(source,codeStrPtr);
        assign(slot,(s32 *)source);
        func_00312318(source,2);
        release(codeStrPtr);
        slot=HArray__operator_index(array,1);
        func_002FE278(source,*(s32 *)(entryHeader+0x48));
        assign(slot,(s32 *)source);
        func_002FC870(source,2);
        assign(out,array);
        func_002ED5C0(array,2);
    }
}
