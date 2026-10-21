/* Changes the current index of the select bar: remembers the old value at +0xBC, stores the new one through func_0057CE40, then notifies func_002D73C8 with (old, new) and refreshes the bar with func_002D6770.
 * (Reading inferred from the oldIndex/newIndex parameter names already used for func_002D73C8.) */
#include "types.h"

struct S {
    char p0[0xBC];
    s32 fBC;
};

extern "C" void func_002D6770(S *self);
extern "C" void func_002D73C8(S *self, s32 oldIndex, s32 newIndex);
extern "C" void func_0057CE40(s32 *bar, s32 newIndex);

extern "C" void func_002D7288(S *bar, s32 newIndex) {
    s32 *indexField = &bar->fBC;
    s32 oldIndex = *indexField;
    func_0057CE40(indexField, newIndex);
    func_002D73C8(bar, oldIndex, newIndex);
    func_002D6770(bar);
}
