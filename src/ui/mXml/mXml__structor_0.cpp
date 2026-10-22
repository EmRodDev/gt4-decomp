/* Constructor of mXml: wraps an Expat 1.95.7 parser. After the hObject base constructor and the vtable at +4 it builds the members at +0x10 (func_00209200) and +0x14
 * (func_0026CAA0, given the +0x10 object), then creates the parser with XML_ParserCreate(NULL) (func_004CE828, found by tools/libmatch.py scan expat) and stores it at +0x42C.
 * func_004CF370 is XML_SetUserData (user data = the +0x14 member), func_004CF3F0 is XML_SetElementHandler (start and end callbacks D_0026CD80 and D_0026D108)
 * and func_004CF410 is XML_SetCharacterDataHandler (callback D_0026D2B8). The three D_ names sit in the UI code range, so they are callback functions declared as data (inferred). */
#include "gt4/mXml.h"
typedef int s32;

extern void *D_0026CD80;
extern void *D_0026D108;
extern void *D_0026D2B8;
extern void *mXml__vtable;
extern "C" void *hObject__structor_0(void *);
extern "C" void *func_00209200(void *);
extern "C" void *func_0026CAA0(void *, void *);
extern "C" void *func_004CE828(s32);
extern "C" void *func_004CF370(void *, void *);
extern "C" void *func_004CF3F0(void *, void *, void *);
extern "C" void *func_004CF410(void *, void *);

extern "C" void mXml__structor_0(void *self) {
    hObject__structor_0(self);
    ((struct mXml *)self)->unk4 = &mXml__vtable;
    func_00209200((char *)self + 0x10);
    func_0026CAA0((char *)self + 0x14, (char *)self + 0x10);
    void *parser = func_004CE828(0x0);
    ((struct mXml *)self)->unk42C = parser;
    func_004CF370(parser, (char *)self + 0x14);
    func_004CF3F0(((struct mXml *)self)->unk42C, &D_0026CD80, &D_0026D108);
    func_004CF410(((struct mXml *)self)->unk42C, &D_0026D2B8); return;
}
