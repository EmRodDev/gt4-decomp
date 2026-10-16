struct S {signed char *data;int limit,byte,bit,pad,error;};
extern "C" unsigned func_00567B38(S *s,int n){unsigned result=0;if(s->limit<s->byte*8+s->bit+n)s->error=1;if(s->error)return 0;while(n){result<<=1;result|=(s->data[s->byte]>>(7-s->bit))&1;if(++s->bit==8){s->bit=0;++s->byte;}--n;}return result;}
