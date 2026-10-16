/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,selfish; char *data(){return (char *)(this+1);} char *grab(); void release(); };
extern Rep D_00659E20;
extern char D_006C01F8[], D_006C0200[];
extern const char *D_00645428[];
extern int D_006C0228[];
struct Str;
struct Obj;
extern "C" void func_00575DA0(void *) throw();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" long func_005A7170(const char *,char **,int) throw();
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *strobe__Any__setMember(Str *,u32,u32,const char *,u32);
extern "C" Str *func_0060DC18(Str *,u32,u32,const Str *,u32,u32);
extern "C" int func_00608D98(const Str *,const Str *,u32,u32);
extern "C" u32 func_0060E700(const Str *,char,u32);
extern "C" void func_004EBC68(Obj *,const Str &) throw();
inline char *Rep::grab(){if(selfish)return strobe__toUpper(this);++ref;return data();}
inline void Rep::release(){if(--ref==0)func_00575DA0(this);}
struct Str {
 char *dat;
 Rep *rep() const {return (Rep *)dat-1;}
 u32 length() const {return rep()->len;}
 Str():dat(D_00659E20.grab()){}
 Str(const Str &s):dat(s.rep()->grab()){}
 Str(const char *s):dat(D_00659E20.grab()){u32 n=func_0057F260(s);strobe__Any__setMember(this,0,(u32)-1,s,n);}
 Str(const Str &s,u32 pos,u32 n):dat(D_00659E20.grab()){func_0060DC18(this,0,(u32)-1,&s,pos,n);}
 ~Str(){rep()->release();}
 Str &operator=(const Str &s){if(&s!=this){rep()->release();dat=s.rep()->grab();}return *this;}
 char operator[](u32 i) const {if(i==length())return 0;return dat[i];}
 Str substr(u32 pos,u32 n=(u32)-1)const{return Str(*this,pos,n);}
 u32 find(char c,u32 pos=0)const{return func_0060E700(this,c,pos);}
 int compare(const Str &s,u32 pos,u32 n)const{return func_00608D98(this,&s,pos,n);}
 const char *c_str(){if(length()==0)return D_006C0200;dat[length()]=0;return dat;}
};
static inline int operator==(const Str &a,const Str &b){return a.compare(b,0,(u32)-1)==0;}
struct Obj { int kind; Str user,password,host; int port; Str path; };
extern "C" int func_004EC078(Obj *o,const Str *url){
 int ok=1;
 u32 len=url->length();
 u32 pos=url->find(':');
 if(pos!=(u32)-1){
  Str scheme(*url,0,pos);
  int i;
  for(i=0;i<2;i++){
   if(scheme==Str(D_00645428[i])){o->kind=i;break;}
  }
  ok=i!=2;
  pos++;
 }else pos=0;
 if(pos==len)return 0;
 if((*url)[pos]=='/'){
  pos++;
  if(pos==len || (*url)[pos]!='/'){
   func_004EBC68(o,Str(*url,pos-1,(u32)-1));
  }else{
   pos++;
   Str host;
   u32 end=url->find('/',pos);
   if(end!=(u32)-1){
    func_004EBC68(o,Str(*url,end,(u32)-1));
    host=url->substr(pos,end-pos);
   }else{
    ok=0;
    func_004EBC68(o,Str(D_006C01F8));
    host=url->substr(pos);
   }
   pos=host.find('@');
   if(pos!=(u32)-1){
    u32 colon=host.find(':');
    if(colon==(u32)-1 || pos<colon){
     o->user=host.substr(0,pos);
    }else{
     o->user=host.substr(0,colon);
     o->password=host.substr(colon+1,pos-colon-1);
    }
    host=host.substr(pos+1);
   }
   pos=host.find(':');
   if(pos!=(u32)-1){
    Str port=host.substr(pos+1);
    o->host=host.substr(0,pos);
    o->port=(int)func_005A7170(port.c_str(),0,10);
   }else{
    o->host=host;
    o->port=D_006C0228[o->kind];
   }
  }
 }else{
  func_004EBC68(o,Str(*url,pos,(u32)-1));
 }
 return ok;
}
