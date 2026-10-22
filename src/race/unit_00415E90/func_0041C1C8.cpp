/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sets a settings-like block to default values: floats 0, 0.5 and 1.0 into the fields at +0x50..+0x80, the vector
 * (0, 1, 0) at +0x90, the flags at +0xA8..+0xD4 to 1 or 0, and then a two-iteration loop that writes 0.5 or 0 into
 * pairs of fields at offsets 0, 0x10, 0x20, 0x30 and 0x40, and 0 and 1 at 0xA0 and 0xB0 (the pair is at +0 and +8
 * from the base, stepping 4 per iteration). What the block is is unknown; the first 0x50 bytes are a 5x4 float
 * table. All fields are volatile, so every store is issued as written; the zero is loaded back from the first
 * field after storing 0 into it, which is the form that matched. */
struct V3 { volatile float x,y,z; };
struct S {
 volatile float m[5][4];
 volatile float f50,f54,f58,f5C,f60,f64,f68,f6C,f70,f74,f78,f7C,f80;
 char pad84[12]; V3 v90; int pad9C;
 int n0[2],pA8,pAC,n1[2],pB8,pBC,pC0,pC4,pC8,pCC,pD0,pD4;
};
extern "C" void func_0041C1C8(S *block) {
 *(int *)&block->f50=0;
 float zeroValue=block->f50;
 block->f54=zeroValue; block->f58=zeroValue; block->f5C=zeroValue;
 block->f60=0.5f; block->f64=zeroValue; block->f68=1.0f; block->f6C=zeroValue;
 block->f70=1.0f; block->f74=1.0f; block->f78=zeroValue; block->f7C=zeroValue; block->f80=zeroValue;
 V3 *v=&block->v90; v->z=zeroValue; v->y=1.0f; v->x=zeroValue;
 block->pA8=1; block->pAC=0; block->pB8=1; block->pBC=1; block->pC0=1; block->pC4=1;
 block->pC8=0; block->pCC=0; block->pD0=0; block->pD4=0;
 int one=1;
 char *pb=(char *)block+8, *pa=(char *)block;
 for (int i=0;i<2;i++,pa+=4,pb+=4) {
  *(volatile float *)(pa+0)=0.5f; *(volatile float *)(pb+0)=0.5f;
  *(volatile int *)(pa+0x10)=0; *(volatile int *)(pb+0x10)=0;
  *(volatile float *)(pa+0x20)=0.5f; *(volatile int *)(pb+0x20)=0;
  *(volatile float *)(pa+0x30)=0.5f; *(volatile int *)(pb+0x30)=0;
  *(volatile int *)(pa+0x40)=0; *(volatile int *)(pb+0x40)=0;
  *(volatile int *)(pa+0xA0)=0; *(volatile int *)(pa+0xB0)=one;
 }
}
