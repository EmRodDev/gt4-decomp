/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004C5208(const unsigned short *,unsigned char *) throw();
extern "C" int func_004C58A8(unsigned char *) throw();
extern "C" int func_004C5958(const unsigned short *text,int len,unsigned char *out) {
unsigned char step;
int pos,special=0;
unsigned char *cursor=out+16;
for(pos=16;pos>=0;pos--)*cursor--=0;
int col=0,row=0,count=0;
for(pos=0;pos<len;) {
 int token=func_004C5208(text+pos,&step);
 if(token>0) {
  count++;
  if((unsigned int)(token-1)<9) {
   unsigned char old=out[col+row];
   if(old!=0 && old!=32 && old!=33)
    return func_004C58A8(out)!=-1?pos:0;
   if(special==1 && token!=3)
    return func_004C58A8(out)!=-1?pos-2:0;
   out[col+row]=token+48;
   special=0;
  } else if((unsigned int)(token-101)<4) {
   if(token==104) {token=103;special=1;}
   if(col>=token-100)return func_004C58A8(out)!=-1?pos:0;
   col=token-100;
   if(out[col+row]==0)out[col+row]=33;
   else return func_004C58A8(out)!=-1?pos:0;
  } else {
   if(pos+step==len)return func_004C58A8(out)!=-1?pos:0;
   if(row>=token-1000)return func_004C58A8(out)!=-1?pos:0;
   row=token-1000;
   col=0;
   if(out[row]==0)out[row]=32;
   else return func_004C58A8(out)!=-1?pos:0;
  }
  if(count>=32)break;
  pos+=step;
 } else {
  if(special==1)return 0;
  return func_004C58A8(out)!=-1?pos:0;
 }
}
if(special)pos-=2;
return func_004C58A8(out)!=-1?pos:0;
}
