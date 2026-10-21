/* Initialises a race-setup screen object from the global block D_00622F4C: base set-up func_003BB440 with the block at +0x44, then
 * through virtual calls (slot +0x98 returns an object whose byte at +62 is a count) it sets slot +0x50 to min(global count at +0xC4,
 * that count), slot +0x20 to a 64-bit key made by func_00447C78 from the string at block+4, and finally copies the block at +0xD8 into the
 * member with func_003D63A8. The inline helpers mirror the vtable entries so each call compiles like the original. Meaning of the
 * slots is unknown. */
struct R { char pad[62];unsigned char count; };
struct V { short delta,index;void *fn; };
struct S { char pad[0x12C];V *table;char member[1]; };
struct G { char pad[0xC4];int count;char pad2[16];char member[1]; };
extern "C" G *D_00622F4C;
extern "C" void func_003BB440(S *,void *);
extern "C" long long func_00447C78(const char*);
extern "C" void func_003D63A8(void *,void *);
static inline R *get(S *self) { V *entry=(V*)((char*)self->table+0x98);return ((R*(*)(void*))entry->fn)((char*)self+entry->delta); }
static inline void set(S *self,int off,int value) { V *entry=(V*)((char*)self->table+off);((void(*)(void*,int))entry->fn)((char*)self+entry->delta,value); }
static inline void setKey(S*self,long long key){V*entry=(V*)((char*)self->table+0x20);((void(*)(void*,long long))entry->fn)((char*)self+entry->delta,key);}
extern "C" void func_001118B8(S *self) { func_003BB440(self,(char*)D_00622F4C+0x44);int count=D_00622F4C->count;if(get(self)->count<count)count=get(self)->count;set(self,0x50,count);setKey(self,func_00447C78((char*)D_00622F4C+4));func_003D63A8(self->member,(char*)D_00622F4C+0xD8); }
