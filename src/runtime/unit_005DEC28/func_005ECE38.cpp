/* compiler: ee-gcc2.96-stl */
struct RefObject;
extern "C" void func_003285A8(RefObject*),func_003285F8(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_00309360");~Value() __asm__("func_00309378");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_003285A8(next);if(p)func_003285F8(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
template<class I>inline Value*value_type(const I&){return 0;}
template<class I>inline int*distance_type(const I&){return 0;}
extern "C" void func_005ED248(Value*first,Value*last,Compare compare);
extern "C" void func_005ED3C0(Value*first,Value*last,Compare compare,Value*,int*);
extern "C" void func_005ED480(Value*first,int hole,int length,Value value,Compare compare);
static inline void make_heap(Value*first,Value*last,Compare compare){
    func_005ED3C0(first,last,compare,value_type(first),distance_type(first));
}
static inline void pop_inner(Value*first,Value*last,Value*result,Value value,Compare compare,int*){
    *result=*first;
    func_005ED480(first,0,last-first,value,compare);
}
extern "C" void func_005ECE38(Value*first,Value*middle,Value*last,Value*,Compare compare){
    { make_heap(first,middle,compare); }
    for(Value*i=middle;i<last;++i)
        if(compare(*i,*first))
            pop_inner(first,middle,i,Value(*i),compare,distance_type(first));
    func_005ED248(first,middle,compare);
}
