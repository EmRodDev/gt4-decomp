/* Resets the photo-mode object: its floats b and c (after pad68) become 0.5, and the camera sub-object (+0xE70 from the accessor at
 * vtable +0x4B0) gets float a stored at +8, floored at 0.01 (0x1.47ae14p-7). Purpose unknown. */
struct Entry{short delta,index;char*(*fn)(void*);};struct Obj{char pad[0x64];Entry*vt;char pad68[0x1E65C-0x68];float a,b,c;};extern "C" Obj*func_00192E20(void*);
extern "C" void func_001952D0(void*,void*modeArg){Obj*photoMode=func_00192E20(modeArg);Entry*entry=(Entry*)((char*)photoMode->vt+0x4B0);char*camera=entry->fn((char*)photoMode+entry->delta)+0xE70;float half=0.5f;float value=photoMode->a;float low=0x1.47ae14p-7f;photoMode->b=half;photoMode->c=half;if(value<=low)value=low;*(float*)(camera+8)=value;}
