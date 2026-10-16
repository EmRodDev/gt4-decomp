struct RefObject;
extern "C" void func_003285A8(RefObject*),func_003285F8(RefObject*);
struct Value{RefObject*p;Value(const Value&) __asm__("func_00309360");~Value() __asm__("func_00309378");Value&operator=(const Value&other){if(this!=&other){RefObject*next=other.p;if(next)func_003285A8(next);if(p)func_003285F8(p);p=next;}return *this;}};
struct Entry{short delta,index;int(*call)(void*,const Value*,const Value*);};
struct CompareObject{Entry*table;};
template<class A,class B,class R>struct BinaryFunction{typedef A first_argument_type;typedef B second_argument_type;typedef R result_type;};
struct Compare:BinaryFunction<Value,Value,int>{CompareObject*object;int operator()(const Value&a,const Value&b)const{CompareObject*o=object;Entry*e=o->table+2;return e->call((char*)o+e->delta,&a,&b);}};
struct BidirectionalTag{};
extern "C" void func_005ECBF8(Value*,Value*,BidirectionalTag);
template<class T>inline void swap(T&a,T&b){T temp=a;a=b;b=temp;}
extern "C" Value*func_005EC4A0(Value*first,Value*middle,Value*last,int*,BidirectionalTag){if(first==middle)return last;if(last==middle)return first;func_005ECBF8(first,middle,BidirectionalTag());func_005ECBF8(middle,last,BidirectionalTag());while(first!=middle&&middle!=last)swap(*first++,*--last);if(first==middle){func_005ECBF8(middle,last,BidirectionalTag());return last;}else{func_005ECBF8(first,middle,BidirectionalTag());return first;}}
