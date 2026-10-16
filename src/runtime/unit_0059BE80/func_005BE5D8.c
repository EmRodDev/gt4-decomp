/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): fde_merge and end_fde_sort (frame.c), with
 * fde_split and frame_heapsort inlined into end_fde_sort. fde_merge must be compiled first: a
 * call to a function already defined in the unit fills the heapsort loop branch without annulling.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef unsigned int size_t;
typedef unsigned int uword __attribute__ ((mode (SI)));
typedef int sword __attribute__ ((mode (SI)));
typedef int saddr __attribute__ ((mode (pointer)));

struct dwarf_fde {
  uword length;
  sword CIE_delta;
  void* pc_begin;
  uword pc_range;
};
typedef struct dwarf_fde fde;

typedef struct fde_vector
{
  fde **array;
  size_t count;
} fde_vector;

typedef struct fde_accumulator
{
  fde_vector linear;
  fde_vector erratic;
} fde_accumulator;

extern void func_005A2E68 (void) __attribute__ ((noreturn));
#define abort func_005A2E68
extern void free (void *);
#define free free

extern fde *D_0088D944;
#define marker D_0088D944

static inline saddr
fde_compare (fde *x, fde *y)
{
  return (saddr)x->pc_begin - (saddr)y->pc_begin;
}

static inline void
fde_split (fde_vector *linear, fde_vector *erratic)
{
  size_t count = linear->count;
  fde **chain_end = &marker;
  size_t i, j, k;

  if (sizeof (fde *) != sizeof (fde **))
    abort ();
  
  for (i = 0; i < count; i++)
    {
      fde **probe;
      
      for (probe = chain_end;
           probe != &marker && fde_compare (linear->array[i], *probe) < 0;
           probe = chain_end)
        {
          chain_end = (fde **)erratic->array[probe - linear->array];
          erratic->array[probe - linear->array] = 0;
        }
      erratic->array[i] = (fde *)chain_end;
      chain_end = &linear->array[i];
    }

  for (i = j = k = 0; i < count; i++)
    if (erratic->array[i])
      linear->array[j++] = linear->array[i];
    else
      erratic->array[k++] = linear->array[i];
  linear->count = j;
  erratic->count = k;
}

static inline void
frame_heapsort (fde_vector *erratic)
{
  fde ** a = erratic->array;
#define SWAP(x,y) do { fde * tmp = x; x = y; y = tmp; } while (0)
  size_t n = erratic->count;
  size_t m = n;
  size_t i;

  while (m > 0)
    {
      m--;
      for (i = m; 2*i+1 < n; )
        {
          if (2*i+2 < n
              && fde_compare (a[2*i+2], a[2*i+1]) > 0
              && fde_compare (a[2*i+2], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+2]);
              i = 2*i+2;
            }
          else if (fde_compare (a[2*i+1], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+1]);
              i = 2*i+1;
            }
          else
            break;
        }
    }
  while (n > 1)
    {
      n--;
      SWAP (a[0], a[n]);
      for (i = 0; 2*i+1 < n; )
        {
          if (2*i+2 < n
              && fde_compare (a[2*i+2], a[2*i+1]) > 0
              && fde_compare (a[2*i+2], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+2]);
              i = 2*i+2;
            }
          else if (fde_compare (a[2*i+1], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+1]);
              i = 2*i+1;
            }
          else
            break;
        }
    }
#undef SWAP
}

void
func_005BE5D8 (fde_vector *v1, fde_vector *v2)
{
  size_t i1, i2;
  fde * fde2;

  i2 = v2->count;
  if (i2)
    {
      i1 = v1->count;
      do {
        i2--;
        fde2 = v2->array[i2];
        while (i1 > 0 && fde_compare (v1->array[i1-1], fde2) > 0)
          {
            v1->array[i1+i2] = v1->array[i1-1];
            i1--;
          }
        v1->array[i1+i2] = fde2;
      } while (i2);
      v1->count += v2->count;
    }
}

fde **
func_005BE6D0 (fde_accumulator *accu, size_t count)
{
  if (accu->linear.array && accu->linear.count != count)
    abort ();
  if (accu->erratic.array)
    {
      fde_split (&accu->linear, &accu->erratic);
      if (accu->linear.count + accu->erratic.count != count)
	abort ();
      frame_heapsort (&accu->erratic);
      func_005BE5D8 (&accu->linear, &accu->erratic);
      free (accu->erratic.array);
    }
  else
    {
      frame_heapsort (&accu->linear);
    }
  return accu->linear.array;
}
