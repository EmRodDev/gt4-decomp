/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TextureState { char physicalPrefix[32];unsigned long clamp; };
struct Texture { char physicalPrefix[24];TextureState*state; };
extern "C" int func_00499728(Texture*);
extern "C" void func_0049CC48(TextureState*);
extern "C" void func_0042DD68(float,float,float,float,float,float,float,float) throw();
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void func_0042DE50(Texture*t,float x0,float y0,float x1,float y1){
 if(t){func_00499728(t);func_0049CC48(t->state);
 unsigned long bits=t->state->clamp;unsigned width=(bits>>14&1023)+1;unsigned height=(bits>>34&1023)+1;
 float u=(float)width/(float)extentPower(width);float v=(float)height/(float)extentPower(height);
 func_0042DD68(x0,y0,x1,y1,0,0,u,v);
 }
}
