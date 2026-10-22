/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
struct Info { u32 flags; union { u8 data[12]; u8 *ptr; } u; u8 suffix; u8 length; };
struct Stack { u16 text[48]; u8 small[32]; int offset; int kind; };
extern "C" int func_004C8ED0(u16 *);
extern "C" void func_004C8F08(u16 *,u16 *);
extern "C" int func_004C1788(int,u16 *,u32,Info *) throw();
extern "C" void func_004C4D68(u16 *,u16 *,int) throw();
extern "C" void *func_004C4070(void *,const void *,unsigned) throw();
extern "C" void func_004C5BF8(u16 *,int,u8 *) throw();
extern "C" int func_004C9330(u8 *);
extern "C" void func_004C8FD8(u16 *,u8 *);
extern "C" void func_004C52A0(u16 *,u8 *,u32) throw();
extern "C" void func_004C5328(u16 *,u8 *,int,u32) throw();
extern "C" void func_004C53E8(u16 *,u8 *,int,u32) throw();
extern "C" int func_004C4E58(u16 *) throw();
extern "C" void func_004C55D8(u16 *,u16 *,int,int,u32) throw();
extern "C" int func_004C8718(int arg0,u16 *out,u32 cap,u16 *in,Info *info) {
    u16 text[48];
    u8 small[32];
    int offset;
    int kind;
    int len;
    u8 *data;
    func_004C8ED0(in);
    kind=-1;
    func_004C8F08(text,in);
    u16 *part=text+func_004C8ED0(text)-info->length;
    if(info->flags&0x100000) {
        offset=info->u.data[0];
        kind=info->u.data[1];
        len=offset;
    } else if(info->flags&0x800000) {
        data=info->u.data;
        offset=data[2];
        kind=*(u16 *)(data+6)>>11;
        len=offset;
    } else if(info->flags&0x400000) {
        data=info->u.data;
        len=data[3];
        offset=data[2];
    } else {
        u8 *ptr=info->u.ptr;
        int b=ptr[2]&15;
        int a=ptr[3]&15;
        offset=a;
        len=b;
    }
    int suffix=info->suffix;
    int total=len+suffix;
    if(cap < (u32)(total*2+2)) return 0x80001007;
    switch(kind) {
    case -1: {
        int r=func_004C1788(arg0,out,cap,info);
        if(r<0)return r;
        break;
    }
    case 1: case 20:
        func_004C4D68(part,part,len);
    case 0: case 16: case 17: case 18:
        func_004C4070(out,part,len*2);
        break;
    case 10: {
        u8 *tmp=small;
        func_004C5BF8(in+suffix,len,tmp);
        if((u32)(func_004C9330(tmp)*2+2)<cap) {
            func_004C8FD8(out,tmp);
            len=func_004C8ED0(out);
        } else { *out=0; return 0; }
        break;
    }
    case 11: {
        u8 *tmp=small;
        func_004C5BF8(in+suffix,len,tmp);
        func_004C52A0(out,tmp,cap);
        len=func_004C8ED0(out);
        if(!len)return len;
        break;
    }
    case 12: case 15: {
        u8 *tmp=small;
        func_004C5BF8(in+suffix,len,tmp);
        func_004C5328(out,tmp,kind,cap);
        len=func_004C8ED0(out);
        if(!len)return len;
        break;
    }
    case 13: case 14: {
        u16 *src=in+suffix;
        if(func_004C4E58(src)>0) {
            u8 *tmp=small;
            func_004C5BF8(src,len,tmp);
            func_004C53E8(out,tmp,kind,cap);
        } else {
            u16 saved=in[info->length];
            in[info->length]=0;
            func_004C55D8(out,src,len,kind,cap);
            in[info->length]=saved;
        }
        len=func_004C8ED0(out);
        if(!len)return len;
        break;
    }
    default:
        func_004C4D68(part,part,len);
        func_004C4070(out,part,len*2);
        break;
    }
    total=len+suffix;
    if(suffix>0) func_004C4070(out+len,part+offset,suffix*2);
    out[total]=0;
    return total;
}
