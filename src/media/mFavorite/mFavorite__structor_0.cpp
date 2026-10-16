// Favorite object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mFavorite:hObject {void* const data;mFavorite(void*) __asm__("func_001C0DC0");virtual ~mFavorite();};
mFavorite::mFavorite(void* value):data(value){}
