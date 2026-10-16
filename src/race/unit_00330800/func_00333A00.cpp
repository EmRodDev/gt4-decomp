/* compiler: ee-gcc2.96-no-strict-aliasing */
struct RenderState {
    int fields[8]; float offsetX,offsetY; int field28,field2C,field30,field34,field38;
    RenderState(int,int,int) __asm__("func_001052E0");
    ~RenderState() __asm__("func_00105280");
};
struct Image {
    int unknown; char *data; int fields8[2]; int width,height,cols,rows,channels; float aspect;
    char *pixel(int x,int y) {
        int size=width*channels;
        size*=height;
        return data+size*(y*cols+x);
    }
};
struct Clock;
struct ClockHolder { int unknown; Clock *clock; };
struct Environment { char gap[0x80]; ClockHolder *holder; };
struct Game { char gap[0x6C]; Environment *environment; };
struct Owner {
    Game *game; int width,height,columns,rows; char gap14[8]; Image image;
    char gap44[0xD4]; int interval,unknown11C; float amount; int paused;
};
extern "C" void func_00333808(Owner *,int) throw();
extern "C" void func_00397568(Clock *,float);
extern "C" void func_00334730(Owner *,RenderState *,RenderState *,int,int,int);
extern "C" void func_001056A0(RenderState *);
extern "C" void func_00330D60(Image *,int,int,float) throw();
extern "C" void func_001059F8(RenderState *,char *,int);
extern "C" void func_001079C8(int,int);
extern "C" void func_003354B8(Owner *,RenderState *);
extern "C" void func_00333900(Owner *) throw();
extern "C" int func_00333A00(Owner *self,int frame) {
    int result=0;
    if(self->game) {
        if(frame==0) func_00333808(self,0);
        RenderState base(0,self->width,self->height);
        if(!self->paused)
            func_00397568(self->game->environment->holder->clock,1.0f/(float)self->interval);
        float alpha=1.0f/((float)frame+1.0f);
        for(int y=0;y<self->rows;++y) {
            for(int x=0;x<self->columns;++x) {
                {
                    RenderState overlay(0x31,self->width,self->height);
                    func_00334730(self,&base,&overlay,x,y,frame);
                }
                if(frame) {
                    func_001056A0(&base);
                    func_00330D60(&self->image,x,y,1.0f-alpha);
                }
                func_001059F8(&base,self->image.pixel(x,y),1);
                func_001079C8(1,0);
            }
        }
        if(frame==self->interval-1) {
            func_003354B8(self,&base);
            func_001079C8(1,0);
            func_00333900(self);
            return 0;
        }
        return 1;
    }
    return result;
}
