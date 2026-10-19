/* newlib-strict 1.9.0: quorem from dtoa.c, placed at 0x005aae08 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: newlib (BSD-style per file, see THIRD_PARTY.md) */
#define __mcmp D_005ACDC8
#define __sbprintf func_005A7518
#define __sfvwrite D_005A3FC8
#define __sinit D_005A3668
#define __smakebuf func_005A44F0
#define __sprint func_005A74D0
#define __sseek D_005A5C68
#define __swbuf D_005AAB30
#define _cleanup_r D_005A3628
#define _fstat_r D_005A3F68
#define _impure_ptr _impure_ptr
#define _malloc_r D_00575FB0
#define _putchar_r func_005A4A88
#define _vfiprintf_r func_005A7648
#define fflush fflush
#define isatty isatty
#define putchar func_005A4B30
#define quorem func_005AAE08
#define vfiprintf func_005A75D0

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

extern struct _reent *_impure_ptr;

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

typedef long _off_t;
typedef long _ssize_t;

struct stat;
struct tms;
struct timeval;
struct timezone;

extern int _fstat_r (struct _reent *, int, struct stat *);


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


double _mprec_log10 (int);

static int

quorem(_Bigint * b , _Bigint * S)

{
  int n;
  __int32_t borrow, y;
  __ULong carry, q, ys;
  __ULong *bx, *bxe, *sx, *sxe;

  __int32_t z;
  __ULong si, zs;

  n = S->_wds;

  if (b->_wds < n)
    return 0;
  sx = S->_x;
  sxe = sx + --n;
  bx = b->_x;
  bxe = bx + n;
  q = *bxe / (*sxe + 1);

  if (q)
    {
      borrow = 0;
      carry = 0;
      do
        {

          si = *sx++;
          ys = (si & 0xffff) * q + carry;
          zs = (si >> 16) * q + (ys >> 16);
          carry = zs >> 16;
          y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
          borrow = y >> 16;
          ;
          z = (*bx >> 16) - (zs & 0xffff) + borrow;
          borrow = z >> 16;
          ;
          (((unsigned short *)bx)[1] = (unsigned short)z, ((unsigned short *)bx)[0] = (unsigned short)y, bx++);

        }
      while (sx <= sxe);
      if (!*bxe)
        {
          bx = b->_x;
          while (--bxe > bx && !*bxe)
            --n;
          b->_wds = n;
        }
    }
  if (__mcmp (b, S) >= 0)
    {
      q++;
      borrow = 0;
      carry = 0;
      bx = b->_x;
      sx = S->_x;
      do
        {

          si = *sx++;
          ys = (si & 0xffff) + carry;
          zs = (si >> 16) + (ys >> 16);
          carry = zs >> 16;
          y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
          borrow = y >> 16;
          ;
          z = (*bx >> 16) - (zs & 0xffff) + borrow;
          borrow = z >> 16;
          ;
          (((unsigned short *)bx)[1] = (unsigned short)z, ((unsigned short *)bx)[0] = (unsigned short)y, bx++);

        }
      while (sx <= sxe);
      bx = b->_x;
      bxe = bx + n;
      if (!*bxe)
        {
          while (--bxe > bx && !*bxe)
            --n;
          b->_wds = n;
        }
    }
  return q;
}

char *

_dtoa_r(struct _reent *ptr ,

        double _d ,

        int mode ,

        int ndigits ,

        int *decpt ,

        int *sign ,

        char **rve);
