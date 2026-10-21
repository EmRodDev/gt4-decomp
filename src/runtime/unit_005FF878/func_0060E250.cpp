/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_tree.h) instantiated by tools/stl.py:
   _Rb_tree<Str2, pair<const Str2, Str2>, _Select1st, less<Str2>, GameAlloc>::_M_erase */
#define private public
#define protected public
#include <stl_tree.h>

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p);


struct Rep {
    int len;
    int cap;
    int ref;
    int sel;
};

struct HeapName {
    const char *name;
};

extern "C" int func_00608D98(const void *self, const void *other, unsigned int pos, unsigned int n) throw();
extern "C" char *strobe__toUpper(Rep *rep) throw();


/* the game's string: libstdc++ v2 basic_string (knowledge/runtime-types.md); the pointer is read and
   written as an int so the representation's counters can alias it */
struct Str2 {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    static char *grab(Rep *const r) {
        if (r->sel) return strobe__toUpper(r);
        ++r->ref;
        return (char *)(r + 1);
    }
    Str2(const Str2 &o) : p(grab(o.rep())) {}
    ~Str2() {
        Rep *r = (Rep *)(*(int *)&p - 0x10);
        if (--r->ref == 0) {
            int size = r->cap + 0x10;
            free(r);
        }
    }
    bool operator<(const Str2 &o) const { return func_00608D98(this, &o, 0, (unsigned int)-1) < 0; }
};


/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() of the types this source allocates, without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

/* the game's allocator: every block is tagged with the name of its type */
template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef Str2 Key;
typedef pair<const Str2, Str2> Value;
typedef _Rb_tree_node<Value> Node;


typedef _Rb_tree<Key, Value, _Select1st<Value>, less<Key>, GameAlloc<Value> > Tree;

extern "C" Tree::iterator func_0060E250(Tree *const t, _Rb_tree_node_base *__x_, _Rb_tree_node_base *__y_, const Value &__v)
{
  Tree::_Link_type __x = (Tree::_Link_type) __x_;
  Tree::_Link_type __y = (Tree::_Link_type) __y_;
  Tree::_Link_type __z;

  if (__y == t->_M_header || __x != 0 || 
      t->_M_key_compare(_Select1st<Value>()(__v), Tree::_S_key(__y))) {
    __z = t->_M_create_node(__v);
    Tree::_S_left(__y) = __z;               // also makes t->_M_leftmost() = __z 
                                      //    when __y == t->_M_header
    if (__y == t->_M_header) {
      t->_M_root() = __z;
      t->_M_rightmost() = __z;
    }
    else if (__y == t->_M_leftmost())
      t->_M_leftmost() = __z;   // maintain t->_M_leftmost() pointing to min node
  }
  else {
    __z = t->_M_create_node(__v);
    Tree::_S_right(__y) = __z;
    if (__y == t->_M_rightmost())
      t->_M_rightmost() = __z;  // maintain t->_M_rightmost() pointing to max node
  }
  Tree::_S_parent(__z) = __y;
  Tree::_S_left(__z) = 0;
  Tree::_S_right(__z) = 0;
  _Rb_tree_rebalance(__z, t->_M_header->_M_parent);
  ++t->_M_node_count;
  return Tree::iterator(__z);
}
