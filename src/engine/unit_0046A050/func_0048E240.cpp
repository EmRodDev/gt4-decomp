/* Subtracts one float from each of the 16 floats of a 4x4 matrix. All sixteen differences are computed first and
 * stored afterwards; the odd extra pointer locals and the do-while(0) block reproduce the store order and the
 * register use of the matched code. Why a scalar is subtracted from a matrix is unknown (purpose unknown). */

typedef float f32;
struct func_0048E240_arg0
{
  f32 m[16];
};
extern void func_0048E240(struct func_0048E240_arg0 *matrix, f32 amount)
{
  f32 t0 = matrix->m[0] - amount;
  f32 t1 = matrix->m[1] - amount;
  struct func_0048E240_arg0 *new_var2;
  f32 t2 = matrix->m[2] - amount;
  f32 t3 = matrix->m[3] - amount;
  f32 new_var;
  f32 t4 = matrix->m[4] - amount;
  f32 t5 = matrix->m[5] - amount;
  f32 t6 = matrix->m[6] - amount;
  struct func_0048E240_arg0 *new_var3;
  f32 t7 = matrix->m[7] - amount;
  f32 t8 = matrix->m[8] - amount;
  f32 t9 = matrix->m[9] - amount;
  f32 tA = matrix->m[10] - amount;
  f32 tB = matrix->m[11] - amount;
  f32 tC = matrix->m[12] - amount;
  f32 tD = matrix->m[13] - amount;
  f32 tE = matrix->m[14] - amount;
  f32 tF = matrix->m[15] - amount;
  matrix->m[0] = t0;
  matrix->m[1] = t1;
  matrix->m[2] = t2;
  matrix->m[3] = t3;
 do { matrix->m[4] = t4; matrix->m[15] = tF; matrix->m[5] = t5; new_var2 = matrix; matrix->m[6] = t6; matrix->m[7] = t7; matrix->m[8] = t8; new_var = t9; new_var3 = new_var2; new_var2->m[9] = new_var; new_var3->m[10] = tA; new_var3->m[11] = tB; new_var3->m[12] = tC; } while (0);
  new_var3->m[13] = tD;
  new_var3->m[14] = tE;
}
