/* Expat 1.95.7 XML_SetUserData (identified by address with tools/libmatch.py scan expat): sets m_userData (+0) and, if the handler argument (+4) was still equal to the old user data, moves it along. */
#include "types.h"

struct Obj {
    s32 userData;
    s32 handlerArg;
};

extern "C" void func_004CF370(Obj *parser, s32 userData) {
    s32 oldUserData = parser->userData;
    s32 handlerArg = parser->handlerArg;
    if (handlerArg == oldUserData) {
        parser->handlerArg = userData;
    }
    parser->userData = userData;
}
