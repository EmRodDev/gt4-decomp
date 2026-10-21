/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
typedef int s32;

struct Rep;
extern "C" char *func_005C2560(Rep *src) throw();
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char *data() { return (char *)(this + 1); }
    char *grab() {
        if (sel)
            return func_005C2560(this);
        ++ref;
        return data();
    }
};

struct Heap {
    const char *name;
};

extern "C" Heap *func_005C11A8(void) throw();
extern "C" char *func_005C2560(Rep *src) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    Str(const Str &o) : p(o.rep()->grab()) {}
    ~Str() {
        Rep *q = rep();
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    Str &operator=(const Str &o) {
        if (&o != this) {
            Rep *q = rep();
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
            p = o.rep()->grab();
        }
        return *this;
    }
};

struct Item {
    s32 id;
    Str s[4];
    s32 v[4];
};

extern "C" void *func_005E9730();
extern "C" void *func_00326750(unsigned int, int, const char *);
template<> Item *__uninitialized_copy_aux(Item *,Item *,Item *,__false_type) __asm__("func_005E94B8");
template<> Item *__uninitialized_fill_n_aux(Item *,unsigned int,const Item &,__false_type) __asm__("func_005E95C8");
template<> void fill(Item *,Item *,const Item &) __asm__("func_005E9368");
static inline const unsigned int &maxn(const unsigned int &a, const unsigned int &b) {return a < b ? b : a;}
struct Vec {
 int alloc; Item *start,*finish,*end;
 unsigned int size() const {return finish-start;}
 Item *allocate(unsigned int n) {return (Item *)func_00326750(n*sizeof(Item),4,*(const char **)func_005E9730());}
 void deallocate(Item *p,unsigned int n) {if(p)func_00326798(p,n*sizeof(Item),4,*(const char **)func_005E9730());}
};
extern "C" void func_005E8E40(Vec *v,Item *position,unsigned int n,const Item &x) {
 if(n!=0) {
  if((unsigned int)(v->end-v->finish)>=n) {
   Item x_copy=x;
   const unsigned int elems_after=v->finish-position;
   Item *old_finish=v->finish;
   if(elems_after>n) {
    uninitialized_copy(v->finish-n,v->finish,v->finish);
    v->finish+=n;
    copy_backward(position,old_finish-n,old_finish);
    fill(position,position+n,x_copy);
   } else {
    uninitialized_fill_n(v->finish,n-elems_after,x_copy);
    v->finish+=n-elems_after;
    uninitialized_copy(position,old_finish,v->finish);
    v->finish+=elems_after;
    fill(position,old_finish,x_copy);
   }
  } else {
   const unsigned int old_size=v->size();
   const unsigned int len=old_size+maxn(old_size,n);
   Item *new_start=v->allocate(len);
   Item *new_finish=new_start;
   new_finish=uninitialized_copy(v->start,position,new_start);
   new_finish=uninitialized_fill_n(new_finish,n,x);
   new_finish=uninitialized_copy(position,v->finish,new_finish);
   destroy(v->start,v->finish);
   v->deallocate(v->start,v->end-v->start);
   v->start=new_start; v->finish=new_finish; v->end=new_start+len;
  }
 }
}
