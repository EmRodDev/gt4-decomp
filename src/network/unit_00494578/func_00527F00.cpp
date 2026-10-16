typedef signed char s8;
typedef unsigned char u8;
struct Obj { char pad[0x98]; s8 *links; };
extern "C" int func_00527E10(Obj *, s8, s8 *) throw();
extern "C" int func_00527F00(Obj *self, s8 value) {
    s8 factors[2];
    s8 *rows[2];
    s8 count=0;
    int result=func_00527E10(self, value, &count);
    if(result!=0) return result;
    {
        if(count<2) {
            if(value>0) {
                u8 odd = value & 1;
                if(odd == 0) {
                    factors[0]=value/2;
                    factors[1]=value>>2;
                } else {
                    factors[0]=value/3;
                    factors[1]=value/5;
                }
                int found=count;
                rows[0]=self->links+factors[0]*3;
                rows[1]=self->links+factors[1]*3;
                for(int i=0; found<2 && i<2; ++i) {
                    for(int j=0;j<3;++j) {
                        s8 v=rows[i][j];
                        if(v != -1) {
                            s8 *p=self->links+v;
                            for(int k=0;k<3;++k) {
                                if(p[k]==factors[i]) {
                                    p[k]=-1;
                                    break;
                                }
                            }
                            ++found;
                            rows[i][j]=-1;
                            break;
                        }
                    }
                }
                int ret=func_00527E10(self,value,&count);
                if(ret!=0) return ret;
            }
        }
    }
    return 0;
}
