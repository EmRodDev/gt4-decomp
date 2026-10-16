/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TextureState { unsigned long words[5]; };
struct Texture { char prefix[24]; TextureState *state; };
extern "C" int func_00499728(Texture*);
extern "C" void func_0049CC48(TextureState*);
extern "C" float func_003AFD18(float,float,unsigned);
extern "C" void func_003AF6E0(float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void func_003AF108(Texture*t,float x,float y,float w,float h,unsigned xf,unsigned yf){
 if(t){
 float left=func_003AFD18(x,w,xf);
 float right=left+w;
 y=func_003AFD18(y,h,yf);
 func_00499728(t);func_0049CC48(t->state);
 float bottom=y+h;
 unsigned long bits=t->state->words[4];
 unsigned width=(bits>>14&1023)+1,height=(bits>>34&1023)+1;
 float u=(float)width/(float)extentPower(width),v=(float)height/(float)extentPower(height);
 func_003AF6E0(left,y,right,bottom,0,0,u,v);
 }
}
