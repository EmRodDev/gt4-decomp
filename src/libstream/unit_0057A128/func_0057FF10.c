/* compiler: ee-gcc2.9-991111 */
extern volatile int D_00655F20;
extern volatile int D_00655F24, D_00655EF4;
extern volatile int D_00655EE8, D_00655EE0;
extern volatile int D_00655ED4, D_00874D80;
extern int func_005ADCD0(int);
void func_0057FF10(int *p) {
 D_00655F20 = *p;
 D_00655F24 = D_00655F20;
 if (D_00655F20 == 11) {
  D_00655F20 = 0;
  D_00655EF4 = 0;
  return;
 }
 func_005ADCD0(D_00655EE8);
 if (D_00655ED4 && D_00874D80) func_005ADCD0(D_00655EE0);
 else D_00655EF4 = 0;
 D_00655F20 = 0;
}
