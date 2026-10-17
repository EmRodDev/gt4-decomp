#include "types.h"
#include "m2c_macros.h"
#define NULL 0
extern "C" {
s32 func_00541D78(void *,void *);
s32 func_00541DD8(void *,void **);
s32 func_00541E30(void *,void *,void *);
s32 func_005422D8(void *,void **);
s32 func_005423C0(void *,void *);
s32 func_00542468(void *,void *);
s32 func_00542510(void *,void *);
s32 func_00594470(const void *,const void *,unsigned);
}
struct Context { char pad[0x8008]; void *root; void *stack[256]; unsigned count,state; unsigned char buffer[2048]; unsigned length; char pad2[8]; int flag; };
extern "C" s32 func_005413B8(Context *arg0, s8 *arg1, u32 arg2) {
    void *sp0;
    void *sp4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 var_a0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    s8 *temp_s2;
    s8 temp_v0_4;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 var_a0_2;
    u32 var_s3;
    u32 var_v0_3;
    u32 var_v1;
    void *var_a1;

    var_s1 = 0;
    for (var_s3=0,var_a0=0;var_s3<arg2;var_s3++,var_a0=0) {
        temp_s2 = arg1 + var_s3;
        switch (*temp_s2) {
        case '<':
            if (arg0->state==24) {arg0->state=0; var_a0=1;}
            break;
        case '>':
            if (arg0->state==2) arg0->state=1;
            else if (arg0->state==4) arg0->state=1;
            else if (arg0->state==5) arg0->state=1;
            else if (arg0->state==9) arg0->state=10;
            else if (arg0->state==14) arg0->state=15;
            else if (arg0->state==19) arg0->state=1;
            break;
        case '/':
            if (arg0->state==0) {arg0->state=11;var_a0=1;}
            else if (arg0->state==2) {arg0->state=9;var_a0=1;}
            else if (arg0->state==4) {arg0->state=9;var_a0=1;}
            else if (arg0->state==5) {arg0->state=9;var_a0=1;}
            break;
        case '?':
            if (arg0->state==0) {arg0->state=12;var_a0=1;}
            else if (arg0->state==13) {arg0->state=14;var_a0=1;}
            break;
        case '!':
            if (arg0->state==0) {arg0->state=16;var_a0=1;}
            break;
        case '=':
            if (arg0->state==5) {arg0->state=6;var_a0=1;}
            break;
        case '"':
            if (arg0->state==6) {arg0->state=7;var_a0=1;}
            else if (arg0->state==8) {arg0->state=4;var_a0=1;}
            break;
        case '\t': case '\n': case '\r': case ' ':
            if (arg0->state==2) arg0->state=3;
            break;
        }
        if (var_a0 == 0) {
            sp0 = NULL;
            sp4 = NULL;
            switch (arg0->state) {                     /* switch 4 */
            case 1: case 3: case 15: case 23:
                if (arg0->length) {
                    var_s1=func_00541DD8(arg0,&sp0);
                    if(var_s1) return var_s1;
                    if(sp0) {
                        if(func_00594470(arg0->buffer,M2C_FIELD(sp0,const char **,4),M2C_FIELD(sp0,u32 *,8))==0 && M2C_FIELD(sp0,u32 *,8)==arg0->length) {
                            arg0->buffer[M2C_FIELD(sp0,u32 *,8)]=0;
                            arg0->length=0;
                            if(arg0->count==0)arg0->state=26;
                        } else {
                            if(arg0->flag) {
                                arg0->flag=0;
                                var_s1=func_00542510(arg0,sp0); if(var_s1)return var_s1;
                                var_s1=func_00541D78(arg0,sp0); if(var_s1)return var_s1;
                            } else {
                                var_s1=func_005422D8(arg0,&sp4); if(var_s1)return var_s1;
                                var_s1=func_00542468(arg0,sp4); if(var_s1)return var_s1;
                                var_s1=func_00541E30(arg0,sp0,sp4); if(var_s1)return var_s1;
                                var_s1=func_00541D78(arg0,sp0); if(var_s1)return var_s1;
                                var_s1=func_00541D78(arg0,sp4); if(var_s1)return var_s1;
                            }
                        }
                    } else {
                        var_s1=func_005422D8(arg0,&sp4); if(var_s1)return var_s1;
                        var_s1=func_00542468(arg0,sp4); if(var_s1)return var_s1;
                        arg0->root=sp4;
                        var_s1=func_00541D78(arg0,sp4); if(var_s1)return var_s1;
                    }
                }
                if(arg0->state==3) {
                    arg0->state=4;
                    arg0->flag=1;
                } else if(arg0->state!=26) arg0->state=24;
                break;
            case 4:                                 /* switch 4 */
            case 7:                                 /* switch 4 */
                if (arg0->length != 0) {
                    var_v0 = func_00541DD8(arg0, &sp0);
                    if (var_v0 == 0) {
                        var_v0 = func_00542510(arg0, sp0);
                        if (var_v0 == 0) {
                            var_v0 = func_00541D78(arg0, sp0);
                            var_s1 = var_v0;
                            if (var_s1 == 0) {
                                goto block_103;
                            }
                        }
                    }
                    /* Duplicate return node #166. Try simplifying control flow for better match */
                    return var_v0;
                }
block_103:
                if(arg0->state==4) arg0->state=5;
                else if(arg0->state==7) arg0->state=8;
                goto block_162;
            case 10:                                /* switch 4 */
                if (arg0->length != 0) {
                    var_v0 = func_00541DD8(arg0, &sp0);
                    var_s1 = var_v0;
                    if (var_s1 == 0) {
                        if (sp0 != NULL) {
                            if (arg0->flag == 0) {
                                var_v0 = func_005422D8(arg0, &sp4);
                                if (var_v0 == 0) {
                                    var_v0 = func_00542468(arg0, sp4);
                                    if (var_v0 == 0) {
                                        var_v0 = func_00541E30(arg0, sp0, sp4);
                                        if (var_v0 == 0) {
                                            var_v0_2 = func_00541D78(arg0, sp0);
                                            goto block_119;
                                        }
                                    }
                                }
                                /* Duplicate return node #166. Try simplifying control flow for better match */
                                return var_v0;
                            }
                            arg0->flag = 0;
                            if (arg0->length != 0) {
                                var_v0_2 = func_00542510(arg0, sp0);
block_119:
                                var_s1 = var_v0_2;
                                if (var_s1 != 0) {
                                    return var_v0_2;
                                }
                                goto block_124;
                            }
                            goto block_125;
                        }
                        arg0->buffer[arg0->length] = 0;
                        arg0->length = 0U;
                        goto block_124;
                    }
                    /* Duplicate return node #166. Try simplifying control flow for better match */
                    return var_v0;
                }
                var_v0 = func_00541DD8(arg0, &sp0);
                var_s1 = var_v0;
                if (var_s1 == 0) {
block_124:
block_125:
                    arg0->state = 0x18U;
                    goto block_164;
                }
                /* Duplicate return node #166. Try simplifying control flow for better match */
                return var_v0;
            case 0: case 11:
                if (arg0->length) {
                    var_s1=func_00541DD8(arg0,&sp0); if(var_s1)return var_s1;
                    if(sp0) {
                        var_s1=func_005422D8(arg0,&sp4); if(var_s1)return var_s1;
                        var_s1=func_005423C0(arg0,sp4); if(var_s1)return var_s1;
                        var_s1=func_00541E30(arg0,sp0,sp4); if(var_s1)return var_s1;
                        var_s1=func_00541D78(arg0,sp0); if(var_s1)return var_s1;
                    } else {
                        arg0->buffer[arg0->length]=0;
                        arg0->length=0;
                    }
                }
                if(arg0->length<0x800) {
                    arg0->buffer[arg0->length]=(u8)*temp_s2;
                    ++arg0->length;
                }
                arg0->state=2;
                break;
            case 12:                                /* switch 4 */
                if (arg0->length != 0) {
                    var_v0 = func_00541DD8(arg0, &sp0);
                    var_s1 = var_v0;
                    if (var_s1 == 0) {
                        if (sp0 != NULL) {
                            var_v0 = func_005422D8(arg0, &sp4);
                            if (var_v0 == 0) {
                                var_v0 = func_005423C0(arg0, sp4);
                                if (var_v0 == 0) {
                                    var_v0 = func_00541E30(arg0, sp0, sp4);
                                    if (var_v0 == 0) {
                                        temp_v0_2 = func_00541D78(arg0, sp0);
                                        var_s1 = temp_v0_2;
                                        if (var_s1 != 0) {
                                            return temp_v0_2;
                                        }
                                        goto block_149;
                                    }
                                }
                            }
                            /* Duplicate return node #166. Try simplifying control flow for better match */
                            return var_v0;
                        }
                        arg0->buffer[arg0->length] = 0;
                        arg0->length = 0U;
                        goto block_149;
                    }
                    /* Duplicate return node #166. Try simplifying control flow for better match */
                    return var_v0;
                }
block_149:
                arg0->state = 0xDU;
                goto block_164;
            case 16:                                /* switch 4 */
                if (arg0->length != 0) {
                    var_v0 = func_00541DD8(arg0, &sp0);
                    var_s1 = var_v0;
                    if (var_s1 == 0) {
                        if (sp0 != NULL) {
                            var_v0 = func_005422D8(arg0, &sp4);
                            if (var_v0 == 0) {
                                var_v0 = func_005423C0(arg0, sp4);
                                if (var_v0 == 0) {
                                    var_v0 = func_00541E30(arg0, sp0, sp4);
                                    if (var_v0 == 0) {
                                        temp_v0_3 = func_00541D78(arg0, sp0);
                                        var_s1 = temp_v0_3;
                                        if (var_s1 != 0) {
                                            return temp_v0_3;
                                        }
                                        goto block_159;
                                    }
                                }
                            }
                            /* Duplicate return node #166. Try simplifying control flow for better match */
                            return var_v0;
                        }
                        arg0->buffer[arg0->length] = 0;
                        arg0->length = 0U;
                        goto block_159;
                    }
                    /* Duplicate return node #166. Try simplifying control flow for better match */
                    return var_v0;
                }
block_159:
                arg0->state = 0x13U;
                goto block_164;
            case 13:                                /* switch 4 */
            case 19:                                /* switch 4 */
                arg0->buffer[arg0->length] = 0;
                arg0->length = 0U;
                goto block_164;
            case 2:                                 /* switch 4 */
            case 5:                                 /* switch 4 */
            case 8:                                 /* switch 4 */
            case 24:                                /* switch 4 */
block_162:
                if (arg0->length < 0x800U) {
                    arg0->buffer[arg0->length] = (u8) *temp_s2;
                    arg0->length = (u32) (arg0->length + 1);
                }
                goto block_164;
            case 6: case 9: case 14: case 17: case 18: case 20: case 21: case 22: case 25: case 26:
                break;
            }
        }
block_164:
        ;
    }
    return var_s1;
}
