/* newlib-mprec 1.9.0: _Balloc, _Bfree, _multadd, _s2b, _hi0bits, _lo0bits, _i2b, _multiply, _pow5mult, _lshift, __mcmp, __mdiff from mprec.c, placed at 0x005ac4d8 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: newlib (BSD-style per file, see THIRD_PARTY.md) */
#define _Balloc func_005AC4D8
#define _Bfree func_005AC580
#define __mcmp func_005ACDC8
#define __mdiff func_005ACE30
#define __mprec_bigtens D_006D22E8
#define __mprec_tens D_006D2220
#define __mprec_tinytens D_006D2310
#define _b2d func_005AD090
#define _calloc_r D_00575F70
#define _d2b func_005AD228
#define _hi0bits func_005AC7E8
#define _i2b func_005AC928
#define _lo0bits func_005AC868
#define _lshift func_005ACC70
#define _mprec_log10 func_005AD480
#define _multadd func_005AC5B0
#define _multiply func_005AC960
#define _pow5mult func_005ACB70
#define _s2b func_005AC6B8
#define memcpy D_005A4724

/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef unsigned int size_t;
typedef int ptrdiff_t;

typedef int wchar_t;

typedef unsigned int wint_t;

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;

typedef unsigned short ushort;
typedef unsigned int uint;

typedef unsigned long  clock_t;

typedef long  time_t;

struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};

typedef long daddr_t;
typedef char * caddr_t;

typedef unsigned short ino_t;

typedef short dev_t;

typedef long off_t;

typedef unsigned short uid_t;
typedef unsigned short gid_t;
typedef int pid_t;
typedef long key_t;
typedef long ssize_t;

typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));

typedef unsigned short nlink_t;

typedef long fd_mask;

typedef struct _types_fd_set {
        fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8 ) )-1))/((sizeof (fd_mask) * 8 ) ))];
} _types_fd_set;

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);

char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);

size_t strftime (char *_s, size_t _maxsize, const char *_fmt, const struct tm *_t);

char *asctime_r (const struct tm *, char *);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *, struct tm *);
struct tm *localtime_r (const time_t *, struct tm *);

typedef __uint32_t __ULong;

struct _glue
{
  struct _glue *_next;
  int _niobs;
  struct __sFILE *_iobs;
};

struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};

struct _atexit {
        struct _atexit *_next;
        int _ind;
        void (*_fns[32 ])(void);
};

struct __sbuf {
        unsigned char *_base;
        int _size;
};

typedef long _fpos_t;

struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;

  void * _cookie;

  int (*_read) (void * _cookie, char *_buf, int _n);
  int (*_write) (void * _cookie, const char *_buf, int _n);
  _fpos_t (*_seek) (void * _cookie, _fpos_t _offset, int _whence);
  int (*_close) (void * _cookie);

  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;

  unsigned char _ubuf[3];
  unsigned char _nbuf[1];

  struct __sbuf _lb;

  int _blksize;
  int _offset;

  struct _reent *_data;
};

struct _reent
{

  int _errno;

  struct __sFILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];

  int _current_category;
  const char *_current_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);

  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;

  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;

        } _reent;

      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;

  struct _atexit *_atexit;
  struct _atexit _atexit0;

  void (**(_sig_func))(int);

  struct _glue __sglue;
  struct __sFILE __sf[3];
};


void _reclaim_reent (struct _reent *);

typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);

float atoff (const char *__nptr);

int atoi (const char *__nptr);
long atol (const char *__nptr);
void * bsearch (const void * __key,

                       const void * __base,

                       size_t __nmemb,

                       size_t __size,

                       int (* _compar) (const void *, const void *));
void * calloc (size_t __nmemb, size_t __size);
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *);
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);
long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size);
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, int *);
int mbtowc (wchar_t *, const char *, size_t);
int _mbtowc_r (struct _reent *, wchar_t *, const char *, size_t, int *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, int *);
size_t mbstowcs (wchar_t *, const char *, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *, const char *, size_t, int *);
size_t wcstombs (char *, const wchar_t *, size_t);
size_t _wcstombs_r (struct _reent *, char *, const wchar_t *, size_t, int *);

int mkstemp (char *);
char * mktemp (char *);

void qsort (void * __base, size_t __nmemb, size_t __size, int(*_compar)(const void *, const void *));
int rand (void);
void * realloc (void * __r, size_t __size);
void srand (unsigned __seed);
double strtod (const char *__n, char **_end_PTR);

float strtodf (const char *__n, char **_end_PTR);

long strtol (const char *__n, char **_end_PTR, int __base);
unsigned long strtoul (const char *_n_PTR, char **_end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *_n_PTR, char **_end_PTR, int __base);
int system (const char *__string);

int putenv (const char *__string);
int _putenv_r (struct _reent *, const char *__string);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);

char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);

void cfree (void *);

char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);
void * _malloc_r (struct _reent *, size_t);
void * _calloc_r (struct _reent *, size_t, size_t);
void _free_r (struct _reent *, void *);
void * _realloc_r (struct _reent *, void *, size_t);
void _mstats_r (struct _reent *, char *);
int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);

void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *, const void *, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *, const char *);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *, const char *);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *, const char *, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *, const char *, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);

char *strtok (char *, const char *);

size_t strxfrm (char *, const char *, size_t);

char *strtok_r (char *, const char *, char **);

int bcmp (const char *, const char *, size_t);
void bcopy (const char *, char *, size_t);
void bzero (char *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void *, const void *, int, size_t);
char *rindex (const char *, int);
int strcasecmp (const char *, const char *);
char *strdup (const char *);
char *_strdup_r (struct _reent *, const char *);
int strncasecmp (const char *, const char *, size_t);
char *strsep (char **, const char *);
char *strlwr (char *);
char *strupr (char *);

typedef long _off_t;
typedef long _ssize_t;

struct stat;
struct tms;
struct timeval;
struct timezone;



/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

typedef union
{
  double value;
  struct
  {

    unsigned int fraction1:32;
    unsigned int fraction0:20;

    unsigned int exponent :11;
    unsigned int sign : 1;
  } number;
  struct
  {

    unsigned int function1:32;
    unsigned int function0:19;

    unsigned int quiet:1;
    unsigned int exponent: 11;
    unsigned int sign : 1;
  } nan;
  struct
  {
    unsigned long lsw;
    unsigned long msw;
  } parts;

  long aslong[2];

} __ieee_double_shape_type;

typedef union
{
  float value;
  struct
  {
    unsigned int fraction0: 7;
    unsigned int fraction1: 16;
    unsigned int exponent: 8;
    unsigned int sign : 1;
  } number;
  struct
  {
    unsigned int function1:16;
    unsigned int function0:6;
    unsigned int quiet:1;
    unsigned int exponent:8;
    unsigned int sign:1;
  } nan;
  long p1;

} __ieee_float_shape_type;

typedef int fp_rnd;

fp_rnd fpgetround (void);
fp_rnd fpsetround (fp_rnd);

typedef int fp_except;

fp_except fpgetmask (void);
fp_except fpsetmask (fp_except);
fp_except fpgetsticky (void);
fp_except fpsetsticky (fp_except);

typedef int fp_rdi;

fp_rdi fpgetroundtoi (void);
fp_rdi fpsetroundtoi (fp_rdi);

int isnan (double);
int isinf (double);
int finite (double);

int isnanf (float);
int isinff (float);
int finitef (float);

union __dmath
{
  __uint32_t i[2];
  double d;
};




extern double nan (void);
extern int isnan (double);
extern int isinf (double);
extern int finite (double);








extern int isnanf (float);
extern int isinff (float);
extern int finitef (float);






struct exception

{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};


enum __fdlibm_version
{
  __fdlibm_ieee = -1,
  __fdlibm_svid,
  __fdlibm_xopen,
  __fdlibm_posix
};




union double_union
{
  double d;
  __uint32_t i[2];
};

typedef struct _Bigint _Bigint;

struct _reent ;
double _ulp (double x);
double _b2d (_Bigint *a , int *e);
_Bigint * _Balloc (struct _reent *p, int k);
void _Bfree (struct _reent *p, _Bigint *v);
_Bigint * _multadd (struct _reent *p, _Bigint *, int, int);
_Bigint * _s2b (struct _reent *, const char*, int, int, __ULong);
_Bigint * _i2b (struct _reent *,int);
_Bigint * _multiply (struct _reent *, _Bigint *, _Bigint *);
_Bigint * _pow5mult (struct _reent *, _Bigint *, int k);
int _hi0bits (__ULong);
int _lo0bits (__ULong *);
_Bigint * _d2b (struct _reent *p, double d, int *e, int *bits);
_Bigint * _lshift (struct _reent *p, _Bigint *b, int k);
_Bigint * __mdiff (struct _reent *p, _Bigint *a, _Bigint *b);
int __mcmp (_Bigint *a, _Bigint *b);

double _ratio (_Bigint *a, _Bigint *b);

extern const double __mprec_tinytens[];
extern const double __mprec_bigtens[];
extern const double __mprec_tens[];

double _mprec_log10 (int);

_Bigint *
_Balloc(struct _reent *ptr , int k)

{
  int x;
  _Bigint *rv ;

  if (ptr->_freelist == ((void *)0))
    {

      ptr->_freelist = (struct _Bigint **) _calloc_r (ptr,
                                                      sizeof (struct _Bigint *),
                                                      15 + 1);
      if (ptr->_freelist == ((void *)0))
        {
          return ((void *)0);
        }
    }

  if ((rv = ptr->_freelist[k]) != 0)
    {
      ptr->_freelist[k] = rv->_next;
    }
  else
    {
      x = 1 << k;

      rv = (_Bigint *) _calloc_r (ptr,
                                  1,
                                  sizeof (_Bigint) +
                                  (x-1) * sizeof(rv->_x));
      if (rv == ((void *)0)) return ((void *)0);
      rv->_k = k;
      rv->_maxwds = x;
    }
  rv->_sign = rv->_wds = 0;
  return rv;
}

void
_Bfree(struct _reent *ptr , _Bigint * v)

{
  if (v)
    {
      v->_next = ptr->_freelist[v->_k];
      ptr->_freelist[v->_k] = v;
    }
}

_Bigint *

_multadd(struct _reent *ptr ,

        _Bigint * b ,

        int m ,

        int a)

{
  int i, wds;
  __ULong *x, y;

  __ULong xi, z;

  _Bigint *b1;

  wds = b->_wds;
  x = b->_x;
  i = 0;
  do
    {

      xi = *x;
      y = (xi & 0xffff) * m + a;
      z = (xi >> 16) * m + (y >> 16);
      a = (int) (z >> 16);
      *x++ = (z << 16) + (y & 0xffff);

    }
  while (++i < wds);
  if (a)
    {
      if (wds >= b->_maxwds)
        {
          b1 = _Balloc (ptr, b->_k + 1);
          memcpy((char *)&b1->_sign, (char *)&b->_sign, b->_wds*sizeof(__int32_t) + 2*sizeof(int));
          _Bfree (ptr, b);
          b = b1;
        }
      b->_x[wds++] = a;
      b->_wds = wds;
    }
  return b;
}

_Bigint *

_s2b(struct _reent * ptr ,

        const char *s ,

        int nd0 ,

        int nd ,

        __ULong y9)

{
  _Bigint *b;
  int i, k;
  __int32_t x, y;

  x = (nd + 8) / 9;
  for (k = 0, y = 1; x > y; y <<= 1, k++);

  b = _Balloc (ptr, k);
  b->_x[0] = y9;
  b->_wds = 1;

  i = 9;
  if (9 < nd0)
    {
      s += 9;
      do
        b = _multadd (ptr, b, 10, *s++ - '0');
      while (++i < nd0);
      s++;
    }
  else
    s += 10;
  for (; i < nd; i++)
    b = _multadd (ptr, b, 10, *s++ - '0');
  return b;
}

int

_hi0bits(register __ULong x)

{
  register int k = 0;

  if (!(x & 0xffff0000))
    {
      k = 16;
      x <<= 16;
    }
  if (!(x & 0xff000000))
    {
      k += 8;
      x <<= 8;
    }
  if (!(x & 0xf0000000))
    {
      k += 4;
      x <<= 4;
    }
  if (!(x & 0xc0000000))
    {
      k += 2;
      x <<= 2;
    }
  if (!(x & 0x80000000))
    {
      k++;
      if (!(x & 0x40000000))
        return 32;
    }
  return k;
}

int
_lo0bits(__ULong *y)

{
  register int k;
  register __ULong x = *y;

  if (x & 7)
    {
      if (x & 1)
        return 0;
      if (x & 2)
        {
          *y = x >> 1;
          return 1;
        }
      *y = x >> 2;
      return 2;
    }
  k = 0;
  if (!(x & 0xffff))
    {
      k = 16;
      x >>= 16;
    }
  if (!(x & 0xff))
    {
      k += 8;
      x >>= 8;
    }
  if (!(x & 0xf))
    {
      k += 4;
      x >>= 4;
    }
  if (!(x & 0x3))
    {
      k += 2;
      x >>= 2;
    }
  if (!(x & 1))
    {
      k++;
      x >>= 1;
      if (!x & 1)
        return 32;
    }
  *y = x;
  return k;
}

_Bigint *
_i2b(struct _reent * ptr , int i)

{
  _Bigint *b;

  b = _Balloc (ptr, 1);
  b->_x[0] = i;
  b->_wds = 1;
  return b;
}

_Bigint *
_multiply(struct _reent * ptr , _Bigint * a , _Bigint * b)

{
  _Bigint *c;
  int k, wa, wb, wc;
  __ULong carry, y, z;
  __ULong *x, *xa, *xae, *xb, *xbe, *xc, *xc0;

  __ULong z2;

  if (a->_wds < b->_wds)
    {
      c = a;
      a = b;
      b = c;
    }
  k = a->_k;
  wa = a->_wds;
  wb = b->_wds;
  wc = wa + wb;
  if (wc > a->_maxwds)
    k++;
  c = _Balloc (ptr, k);
  for (x = c->_x, xa = x + wc; x < xa; x++)
    *x = 0;
  xa = a->_x;
  xae = xa + wa;
  xb = b->_x;
  xbe = xb + wb;
  xc0 = c->_x;

  for (; xb < xbe; xb++, xc0++)
    {
      if ((y = *xb & 0xffff) != 0)
        {
          x = xa;
          xc = xc0;
          carry = 0;
          do
            {
              z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
              carry = z >> 16;
              z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
              carry = z2 >> 16;
              (((unsigned short *)xc)[1] = (unsigned short)z2, ((unsigned short *)xc)[0] = (unsigned short)z, xc++);
            }
          while (x < xae);
          *xc = carry;
        }
      if ((y = *xb >> 16) != 0)
        {
          x = xa;
          xc = xc0;
          carry = 0;
          z2 = *xc;
          do
            {
              z = (*x & 0xffff) * y + (*xc >> 16) + carry;
              carry = z >> 16;
              (((unsigned short *)xc)[1] = (unsigned short)z, ((unsigned short *)xc)[0] = (unsigned short)z2, xc++);
              z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
              carry = z2 >> 16;
            }
          while (x < xae);
          *xc = z2;
        }
    }

  for (xc0 = c->_x, xc = xc0 + wc; wc > 0 && !*--xc; --wc);
  c->_wds = wc;
  return c;
}

_Bigint *

_pow5mult(struct _reent * ptr , _Bigint * b , int k)

{
  _Bigint *b1, *p5, *p51;
  int i;

#define p05 D_006D2210
extern const int p05[3];

  if ((i = k & 3) != 0)
    b = _multadd (ptr, b, p05[i - 1], 0);

  if (!(k >>= 2))
    return b;
  if (!(p5 = ptr->_p5s))
    {

      p5 = ptr->_p5s = _i2b (ptr, 625);
      p5->_next = 0;
    }
  for (;;)
    {
      if (k & 1)
        {
          b1 = _multiply (ptr, b, p5);
          _Bfree (ptr, b);
          b = b1;
        }
      if (!(k >>= 1))
        break;
      if (!(p51 = p5->_next))
        {
          p51 = p5->_next = _multiply (ptr, p5, p5);
          p51->_next = 0;
        }
      p5 = p51;
    }
  return b;
}

_Bigint *
_lshift(struct _reent * ptr , _Bigint * b , int k)

{
  int i, k1, n, n1;
  _Bigint *b1;
  __ULong *x, *x1, *xe, z;

  n = k >> 5;

  k1 = b->_k;
  n1 = n + b->_wds + 1;
  for (i = b->_maxwds; n1 > i; i <<= 1)
    k1++;
  b1 = _Balloc (ptr, k1);
  x1 = b1->_x;
  for (i = 0; i < n; i++)
    *x1++ = 0;
  x = b->_x;
  xe = x + b->_wds;

  if (k &= 0x1f)
    {
      k1 = 32 - k;
      z = 0;
      do
        {
          *x1++ = *x << k | z;
          z = *x++ >> k1;
        }
      while (x < xe);
      if ((*x1 = z) != 0)
        ++n1;
    }

  else
    do
      *x1++ = *x++;
    while (x < xe);
  b1->_wds = n1 - 1;
  _Bfree (ptr, b);
  return b1;
}

int
__mcmp(_Bigint * a , _Bigint * b)

{
  __ULong *xa, *xa0, *xb, *xb0;
  int i, j;

  i = a->_wds;
  j = b->_wds;

  if (i -= j)
    return i;
  xa0 = a->_x;
  xa = xa0 + j;
  xb0 = b->_x;
  xb = xb0 + j;
  for (;;)
    {
      if (*--xa != *--xb)
        return *xa < *xb ? -1 : 1;
      if (xa <= xa0)
        break;
    }
  return 0;
}

_Bigint *

__mdiff(struct _reent * ptr ,

        _Bigint * a , _Bigint * b)

{
  _Bigint *c;
  int i, wa, wb;
  __int32_t borrow, y;
  __ULong *xa, *xae, *xb, *xbe, *xc;

  __int32_t z;

  i = __mcmp (a, b);
  if (!i)
    {
      c = _Balloc (ptr, 0);
      c->_wds = 1;
      c->_x[0] = 0;
      return c;
    }
  if (i < 0)
    {
      c = a;
      a = b;
      b = c;
      i = 1;
    }
  else
    i = 0;
  c = _Balloc (ptr, a->_k);
  c->_sign = i;
  wa = a->_wds;
  xa = a->_x;
  xae = xa + wa;
  wb = b->_wds;
  xb = b->_x;
  xbe = xb + wb;
  xc = c->_x;
  borrow = 0;

  do
    {
      y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
      borrow = y >> 16;
      ;
      z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
      borrow = z >> 16;
      ;
      (((unsigned short *)xc)[1] = (unsigned short)z, ((unsigned short *)xc)[0] = (unsigned short)y, xc++);
    }
  while (xb < xbe);
  while (xa < xae)
    {
      y = (*xa & 0xffff) + borrow;
      borrow = y >> 16;
      ;
      z = (*xa++ >> 16) + borrow;
      borrow = z >> 16;
      ;
      (((unsigned short *)xc)[1] = (unsigned short)z, ((unsigned short *)xc)[0] = (unsigned short)y, xc++);
    }

  while (!*--xc)
    wa--;
  c->_wds = wa;
  return c;
}

double
_ulp(double _x);

double

_b2d(_Bigint * a , int *e);

_Bigint *

_d2b(struct _reent * ptr ,

        double _d ,

        int *e ,

        int *bits);

double
_ratio(_Bigint * a , _Bigint * b);

extern const double
  __mprec_tens[25];

extern const double __mprec_bigtens[5];

extern const double __mprec_tinytens[5];

double

_mprec_log10(int dig);
