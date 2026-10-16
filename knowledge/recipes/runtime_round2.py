#!/usr/bin/env python3
"""Recreate Round 2 public-source adaptations without compiling or modifying src/."""
from pathlib import Path
import argparse

parser=argparse.ArgumentParser()
parser.add_argument('--root',type=Path,default=Path(__file__).resolve().parents[2])
parser.add_argument('--gcc-tree',type=Path,default=Path('/mnt/e/PROJECTS/gcc-20001003'))
parser.add_argument('--newlib-tree',type=Path,default=Path('/home/ghost/gt4-thirdparty/newlib-1.9.0'))
parser.add_argument('--output',type=Path,default=Path(__file__).resolve().parents[2]/'build/swarm/round2-runtime/reproduced')
a=parser.parse_args();a.output.mkdir(parents=True,exist_ok=True)
base=a.root/'src/runtime/unit_0059BE80'
s=(base/'__umoddi3.c').read_text();g=(a.gcc_tree/'gcc/libgcc2.c').read_text()
s=s.replace('__umoddi3 from _umoddi3.c, placed at 0x005bb380','__moddi3 from libgcc2.c (L_moddi3), placed at 0x005ba770').replace('L_umoddi3','L_moddi3').replace('#define __clz_tab D_006D2D28','#define __clz_tab D_006D2B28')
start=s.rindex('#ifdef L_moddi3\nUDWtype');end=s.index('#endif',start)+6
mstart=g.index('#ifdef L_moddi3\nDWtype');mend=g.index('#endif',mstart)+6
mod=g[mstart:mend].replace('__moddi3 (','func_005BA770 (')
neg='static inline\nDWtype\n'+g[g.index('__negdi2 (DWtype u)'):g.index('\n#endif',g.index('__negdi2 (DWtype u)'))]
s=s[:start]+neg+'\n'+mod+s[end:]
(a.output/'005ba770.c').write_text(s)
s=(base/'func_005A75D0.c').read_text().replace('0x005a75d0','0x005a8340').replace('#define vfprintf func_005A75D0','#define vfprintf func_005A8340').replace('#define _vfprintf_r func_005A7648','#define _vfprintf_r func_005A83B8')
(a.output/'005a8340.c').write_text(s)
s=(base/'func_005A7518.c').read_text().replace('0x005a7518','0x005a8288').replace('#define __sbprintf func_005A7518','#define __sbprintf func_005A8288').replace('#define vfiprintf func_005A75D0','#define vfiprintf func_005A8340').replace('__sbprintf from vfiprintf.c','__sbprintf from vfprintf.c (VFPRINTF=vfprintf)')
(a.output/'005a8288.c').write_text(s)
s=(base/'func_005A36F8.c').read_text();cut=s.rindex('#ifdef _HAVE_STDC')
public=(a.newlib_tree/'newlib/libc/stdio/fprintf.c').read_text();public=public[public.index('#ifdef _HAVE_STDC'):]
shim=s[s.rindex("/* gt4: stand-in for gcc's <stdarg.h>"):s.index('extern int __svfscanf ();',cut)]
public=public.replace('#include <stdarg.h>',shim);s=s[:cut]+public
s=s.replace('fscanf from fscanf.c, placed at 0x005a36f8','fprintf from fprintf.c, placed at 0x005a3858').replace(' * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin. */',' * tools/libmatch.py public-source context, adapted from the verified stdio sibling.\n * licence: newlib (BSD-style per file, see THIRD_PARTY.md) */',1)
i=s.index('*/')+2;s=s[:i]+'\n#define fprintf func_005A3858\n#define vfprintf func_005A8340\n'+s[i:]
(a.output/'005a3858.c').write_text(s)

# Record the sibling adaptation separately from the initial public-source extraction.
for target in ('005ba770', '005a8288', '005a8340', '005a3858'):
    path = a.output / (target + '.c')
    text = path.read_text()
    text = text.replace(' * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.',
        ' * Public-source context extracted by tools/libmatch.py; sibling adaptation reproduced by\n * knowledge/recipes/runtime_round2.py. See THIRD_PARTY.md for license and origin.', 1)
    text = text.replace(' * tools/libmatch.py public-source context, adapted from the verified stdio sibling.',
        ' * Public-source context extracted by tools/libmatch.py; sibling adaptation reproduced by\n * knowledge/recipes/runtime_round2.py. See THIRD_PARTY.md for license and origin.', 1)
    path.write_text(text)
