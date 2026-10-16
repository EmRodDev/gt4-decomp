/* licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* Subroutines needed for unwinding DWARF 2 format stack frame info
   for exception handling.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997, 1998, 1999, 2000 Free Software Foundation, Inc.
   Contributed by Jason Merrill <jason@cygnus.com>.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

extern "C" {
struct dwarf_fde { unsigned int length; int CIE_delta; void *pc_begin; unsigned int pc_range; };
typedef dwarf_fde fde;
struct object { void *pc_begin; void *pc_end; fde *fde_begin; fde **fde_array; unsigned int count; object *next; };
extern object *objects;
extern int object_mutex;
int func_005ADCE0(int);
int func_005ADCC0(int);
void frame_init(object *) throw();
fde *search_fdes(fde *, void *);
}
#define objects objects
#define object_mutex object_mutex
#define frame_init frame_init
#define search_fdes search_fdes
typedef unsigned int size_t;
inline void init_object_mutex_once() {}
inline int __gthread_mutex_lock(int *p) { return func_005ADCE0(*p); }
inline int __gthread_mutex_unlock(int *p) { return func_005ADCC0(*p); }
extern "C" {
fde *
find_fde (void *pc)
{
  struct object *ob;
  size_t lo, hi;

  init_object_mutex_once ();
  __gthread_mutex_lock (&object_mutex);

  /* Linear search through the objects, to find the one containing the pc. */
  for (ob = objects; ob; ob = ob->next)
    {
      if (ob->pc_begin == 0)
	frame_init (ob);
      if (pc >= ob->pc_begin && pc < ob->pc_end)
	break;
    }

  if (ob == 0)
    {
      __gthread_mutex_unlock (&object_mutex);
      return 0;
    }

  if (!ob->fde_array || (void *)ob->fde_array == (void *)ob->fde_begin)
    frame_init (ob);

  if (ob->fde_array && (void *)ob->fde_array != (void *)ob->fde_begin)
    {
      __gthread_mutex_unlock (&object_mutex);
      
      /* Standard binary search algorithm.  */
      for (lo = 0, hi = ob->count; lo < hi; )
	{
	  size_t i = (lo + hi) / 2;
	  fde *f = ob->fde_array[i];

	  if (pc < f->pc_begin)
	    hi = i;
	  else if (pc >= (char *)f->pc_begin + f->pc_range)
	    lo = i + 1;
	  else
	    return f;
	}
    }
  else
    {
      /* Long slow labourious linear search, cos we've no memory. */
      fde *f;
      
      if (ob->fde_array)
	{
	  fde **p = ob->fde_array;
	  
	  do
	    {
	      f = search_fdes (*p, pc);
	      if (f)
		break;
	      p++;
	    }
	  while (*p);
	}
      else
	f = search_fdes (ob->fde_begin, pc);
      __gthread_mutex_unlock (&object_mutex);
      return f;
    }
  return 0;
}


}
