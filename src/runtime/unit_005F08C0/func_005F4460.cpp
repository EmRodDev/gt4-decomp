struct Object;struct Record{Object*object;float key;};
typedef int(*Compare)(const Record*,const Record*);
template<class I>inline Record*value_type(const I&){return 0;}
template<class I>inline int*distance_type(const I&){return 0;}
extern "C" void func_005F45E0(Record*,int,int,Record,Compare);
static inline void pop_inner(Record*first,Record*last,Record*result,Record value,Compare compare,int*){*result=*first;func_005F45E0(first,0,last-first,value,compare);}
static inline void pop_aux(Record*first,Record*last,Record*,Compare compare){pop_inner(first,last-1,last-1,Record(*(last-1)),compare,distance_type(first));}
static inline void pop_heap(Record*first,Record*last,Compare compare){pop_aux(first,last,value_type(first),compare);}
extern "C" void func_005F4460(Record*first,Record*last,Compare compare){while(last-first>1)pop_heap(first,last--,compare);}
