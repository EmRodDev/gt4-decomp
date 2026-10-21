/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mode { int pad[18]; int quality[11]; int modes[11]; };
struct Root { struct Mode *mode; };
struct Sub { char pad[56]; int bits; };
struct State { struct Root *root; void *low; int frame, subframe, a10, count, size, a1c, rate, enh; char pad[24]; void *p40, *p44; int *p48; char pad4c[16]; void *p5c; int *p60; int sampling; struct Sub **subs; int mode; };
int func_00567D80(void *, int, void *);
void func_00567F50(const char *, int request);
void *func_005A48D8(void *, int, unsigned int);
extern char D_006CAFB0[];
int func_0056CA60(struct State *st, int request, void *ptr) {
 int q, tmp, i;
 switch(request) {
 case 10: st->mode=*(int *)ptr; break;
 case 8: func_00567D80(st->low,8,ptr); break;
 case 9: func_00567D80(st->low,9,ptr); break;
 case 3: *(int *)ptr=st->frame; break;
 case 0: func_00567D80(st->low,request,ptr); st->enh=*(int *)ptr; break;
 case 4: case 6: { int quality=*(int *)ptr; if(quality<0) quality=0; if(quality>10) quality=10; st->mode=st->root->mode->modes[quality]; q=st->root->mode->quality[quality]; func_00567D80(st->low,6,&q); break; }
 case 19: { struct Sub *s; func_00567D80(st->low,request,ptr); s=st->subs[st->mode]; if(s) *(int *)ptr+=st->rate*s->bits/st->frame; else *(int *)ptr+=st->rate*4/st->frame; break; }
 case 24: st->rate=*(int *)ptr; tmp=st->rate>>1; func_00567D80(st->low,24,&tmp); break;
 case 25: *(int *)ptr=st->rate; break;
 case 20: func_00567D80(st->low,20,ptr); break;
 case 22: func_00567D80(st->low,22,ptr); break;
 case 26: func_005A48D8(st->p5c,0,st->size*8); func_005A48D8(st->p40,0,256); func_005A48D8(st->p44,0,256); break;
 case 36: st->sampling=*(int *)ptr; func_00567D80(st->low,36,&ptr); break;
 case 37: *(int *)ptr=st->sampling; break;
 case 100: { int *p=(int *)ptr; for(i=0;i<st->count;i++) p[i]=st->p60[i]; break; }
 case 101: { int *p=(int *)ptr; func_005A48D8(ptr,0,st->frame*4); for(i=0;i<st->subframe;i++) p[2*i]=st->p48[i]*2; break; }
 case 102: { int *p=(int *)ptr; func_005A48D8(ptr,0,st->frame*4); for(i=0;i<st->subframe;i++) p[2*i]=st->p48[i]*2; break; }
 case 103: func_00567D80(st->low,103,ptr); break;
 default: func_00567F50(D_006CAFB0, request); return -1;
 }
 return 0;
}
