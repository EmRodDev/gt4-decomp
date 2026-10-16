struct Object;struct Record{Object*object;float key;};
typedef int(*Compare)(const Record*,const Record*);
template<class I>inline Record*value_type(const I&){return 0;}
template<class I>inline int*distance_type(const I&){return 0;}
extern "C" void func_005F4538(Record*,Record*,Compare,Record*,int*);
extern "C" void func_005F4460(Record*,Record*,Compare);
extern "C" void func_005F45E0(Record*,int,int,Record,Compare);
static inline void make_heap(Record*first,Record*last,Compare compare){func_005F4538(first,last,compare,value_type(first),distance_type(first));}
static inline void pop_inner(Record*first,Record*last,Record*result,Record value,Compare compare,int*){*result=*first;func_005F45E0(first,0,last-first,value,compare);}
extern "C" void func_005F41E8(Record*first,Record*middle,Record*last,Record*,Compare compare){make_heap(first,middle,compare);for(Record*i=middle;i<last;++i)if(compare(i,first))pop_inner(first,middle,i,Record(*i),compare,distance_type(first));func_005F4460(first,middle,compare);}
