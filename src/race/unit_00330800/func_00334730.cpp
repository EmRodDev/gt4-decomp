/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Renders one screen tile (arg5 = tile index into the table at +0x48, 16 bytes per entry) of a larger image: a
 * parameter var_f24 = tile/tileCount * f120 (zero when +0x124 is clear) is fed to the camera object's virtual calls
 * (+0x10, +0x50, +0x58, +0x68; far distance is the +0x68 result times 1000), the tile's offset inside the full
 * frame (arg3/arg4 over width/height, centred on 0.5) goes into func_00332550 as the sub-window shift, the resulting
 * projection matrix is combined (func_00489FD8) and stored at +0xE36C of the renderer, the scene is drawn through
 * func_0033E368 with the flag at +0xE334 cleared, then the stored matrix is reset to identity.
 * Inferred from the argument flow: a tiled or supersampled capture. Game meaning of the leftover fields is purpose
 * unknown. */
typedef int s32; typedef short s16; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
struct VP { s16 delta,index; char *(*fn)(void *,int); };
struct VF1 { s16 delta,index; f32 (*fn)(void *,f32); };
struct VF0 { s16 delta,index; f32 (*fn)(void *); };
extern "C" void func_00332550(f32,f32,f32,f32,f32,f32,f32,f32,f32) throw();
extern "C" void func_00334C98(void *,s32);
extern "C" void func_0033E368(void *,s32,s32,s32,f32);
extern "C" void func_00343170(void *,s32);
extern "C" void func_00489FD8(void *,void *);
extern "C" void func_004A7454();
extern "C" void func_004A7550(void *);
extern "C" void func_004A7774(void *);
static inline void copy(f32 *d,f32 *s) {
    d[0]=s[0];
    d[4]=s[4];
    d[8]=s[8];
    d[12]=s[12];
    d[1]=s[1];
    d[5]=s[5];
    d[9]=s[9];
    d[13]=s[13];
    d[2]=s[2];
    d[6]=s[6];
    d[10]=s[10];
    d[14]=s[14];
    d[3]=s[3];
    d[7]=s[7];
    d[11]=s[11];
    d[15]=s[15];
}
extern "C" void func_00334730(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct { f32 sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C; char sp50[64]; } sp;
    f32 sourceWidth;
    f32 sourceHeight;
    f32 tileV;
    f32 tileU;
    f32 value58;
    f32 value50;
    f32 tileParam;
    char *camera;
    char *temp_a2;
    char *tileEntry;
    char *temp_v0_5;
    char *temp_v0_6;
    char *temp_v0_7;
    char *temp_v0_8;
    char *temp_v1;

    tileParam = 0x0.0p+0f;
    if (M2C_FIELD(arg0, s32 *, 0x124) != 0) {
        tileParam = ((f32) arg5 / (f32) M2C_FIELD(arg0, s32 *, 0x118)) * M2C_FIELD(arg0, f32 *, 0x120);
    }
    temp_a2 = M2C_FIELD(arg0, char **, 0);
    tileEntry = M2C_FIELD(arg0, char **, 0x48) + (arg5 * 0x10);
    temp_v1 = M2C_FIELD(temp_a2, char **, 0x64);
    tileU=M2C_FIELD(tileEntry,f32 *,8);
    tileU += (f32)arg3;
    f32 width=(f32)M2C_FIELD(arg0,s32 *,0xC);
    tileV=M2C_FIELD(tileEntry,f32 *,0xC);
    tileV += (f32)arg4;
    f32 height=(f32)M2C_FIELD(arg0,s32 *,0x10);
    tileV /= height;
    tileV -= 0.5f;
    tileV = -tileV;
    tileU /= width;
    tileU -= 0.5f;
    VP *cameraEntry = (VP *)(temp_v1 + 0xD0);
    camera = cameraEntry->fn(temp_a2 + cameraEntry->delta, 0);
    func_004A7454();
    VF1 *e10=(VF1 *)(M2C_FIELD(camera,char **,0)+0x10);
    e10->fn(camera+e10->delta,tileParam);
    f32 *matrix=&sp.sp10;
    func_004A7550(matrix);
    VF1 *e50=(VF1 *)(M2C_FIELD(camera,char **,0)+0x50);
    value50=e50->fn(camera+e50->delta,tileParam);
    VF0 *e58=(VF0 *)(M2C_FIELD(camera,char **,0)+0x58);
    value58=e58->fn(camera+e58->delta);
    VF0 *e68=(VF0 *)(M2C_FIELD(camera,char **,0)+0x68);
    f32 far=e68->fn(camera+e68->delta)*1000.0f;
    sourceWidth = (f32) M2C_FIELD(arg0, s32 *, 4);
    sourceHeight = (f32) M2C_FIELD(arg0, s32 *, 8);
    tileV /= sourceHeight;
    func_00332550(value50, value58, far, M2C_FIELD(arg0, f32 *, 0x14), sourceWidth / sourceHeight, M2C_FIELD(tileEntry, f32 *, 0), M2C_FIELD(tileEntry, f32 *, 4), tileU / sourceWidth, tileV);
    func_00489FD8(&sp.sp50, matrix);
    func_004A7774(&sp.sp50);
    func_004A7550(matrix);
    temp_v0_5 = M2C_FIELD(arg0, char **, 0);
    temp_v0_6 = temp_v0_5 + 0xE36C;
    copy((f32 *)temp_v0_6, matrix);
    func_00343170(M2C_FIELD(arg0, char **, 0), 0);
    M2C_FIELD(M2C_FIELD(arg0, char **, 0), s32 *, 0xE334) = 0;
    func_0033E368(M2C_FIELD(arg0, char **, 0), arg1, arg2, 0, tileParam);
    M2C_FIELD(M2C_FIELD(arg0, char **, 0), s32 *, 0xE334) = 1;
    func_00343170(M2C_FIELD(arg0, char **, 0), 1);
    func_00334C98(arg0, arg1);
    *matrix=1.0f;
    sp.sp18=sp.sp44=sp.sp34=sp.sp14=sp.sp40=sp.sp30=sp.sp28=sp.sp20=0.0f;
    sp.sp24=1.0f;
    sp.sp3C=sp.sp2C=sp.sp1C=sp.sp48=0.0f;
    sp.sp38=1.0f;
    sp.sp4C=1.0f;
    temp_v0_7 = M2C_FIELD(arg0, char **, 0);
    temp_v0_8 = temp_v0_7 + 0xE36C;
    copy((f32 *)temp_v0_8, matrix);

}
