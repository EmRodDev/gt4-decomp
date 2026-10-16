/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec {int id;float weight,r,g,b,len;};
struct List {int n;Rec e[32];};
struct Output {int n;List l[6];};
struct Cars {int n,pad;char **a;};
struct Self {char pad[0x60];Cars *cars;};
extern "C" int SPEC_DATABASE__CarEquipments__getVariationOrder(void*);
extern "C" int func_00445828(void*);
extern "C" void func_0040A428(Rec*,void*,int) throw();
extern "C" void func_0040A5A0(List*) throw();
extern "C" float func_0040A338(Rec*,Rec*) throw();
extern "C" void func_0040A6F0(Self*self,Output*out){
int i=0;
int n=self->cars->n;
out->n=n;
if(i<n){
char *row=(char*)out;
do {
 List *l=(List*)(row+4);
 void *car=self->cars->a[i]+0x20;
 if(SPEC_DATABASE__CarEquipments__getVariationOrder(car)==-1){
  float decay=0.984375f;
  int m=func_00445828(car);
  float w=1.0f,total=0.0f;
  int j;
  l->n=m;
  for(j=0;j<m;j++){
   Rec *r=(Rec*)(row+8)+j;
   func_0040A428(r,car,j);
   r->weight=w; total+=w; w*=decay;
  }
  for(j=0;j<m;j++){float *w=&l->e[j].weight;*w/=total;}
 } else {
  l->n=1;
  func_0040A428(&l->e[0],car,SPEC_DATABASE__CarEquipments__getVariationOrder(car));
  l->e[0].weight=1.0f;
 }
i++;row+=sizeof(List);
}while(i<n);
}
i=0;
if(i<n){
char *row2=(char*)out;
do {
 List *l=(List*)(row2+4);
 float total=0.0f;
 int j=0;
 if(j<l->n){
 char *cur=(char*)l;
 do {
  Rec*r=(Rec*)(cur+4);
  float sum=1.0f;
  int k=0;
  if(k<n){
  char *otherrow=(char*)out;
  do {
   List *other=(List*)(otherrow+4);
   for(int t=0;t<other->n;t++){
    if(i!=k || j!=t){
     float f=func_0040A338(r,(Rec*)(otherrow+8)+t);
     if(other->n==1){for(int h=0;h<6;h++)f*=f; f*=10000.0f;}
     sum+=f;
    }
   }
   k++;otherrow+=sizeof(List);
  }while(k<n);
  }
  r->weight*=1.0f/sum;
  total+=r->weight;
 j++;cur+=sizeof(Rec);
 }while(j<l->n);
 }
 func_0040A5A0(l);
 for(j=0;j<l->n;j++){float *w=&l->e[j].weight;*w/=total;}
i++;row2+=sizeof(List);
}while(i<n);
}
}
