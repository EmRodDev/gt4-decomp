/* compiler: ee-gcc2.9-991111 */
struct Ops { int x0,x4; int (*begin)(int,int,unsigned); int (*section)(int,int,unsigned); };
struct Request { char pad[0x18]; unsigned mode; int option; char pad20[16]; struct Ops *ops; int context; };
struct Info { int type; unsigned base; int x8,xc; unsigned entry,init,gp; unsigned text,data,bss,fini,x2c,x30; };
struct Elf { char pad[0x20]; unsigned shoff; char pad24[10]; unsigned short shentsize,shnum; char pad32[38]; unsigned offset; char pad5c[8]; unsigned filesz; char pad68[56]; };
struct Section { unsigned name,type,flags,addr,offset,size,link,info,align,entsize; };
struct Reloc { unsigned offset; unsigned char type; unsigned char extra[3]; };
int func_00588C68(struct Ops *,int,int,int,void *,unsigned,int *);
void *func_0058B1B8(void);
void func_0058B1C0(void *);
int func_005898C0(struct Elf *,struct Info *,unsigned char,int,int *);
void *func_0058B138(int,unsigned,int);
void func_0058B140(void *);
void func_0058B8E8(unsigned,void *,unsigned,unsigned,unsigned);
void *func_005A48D8(void *,int,unsigned);
void func_0058B260(struct Info *,void *);
void func_00589A70(void *,int);
void * __attribute__((register_precision(s0,128))) func_00589128(struct Request *req,int fd,struct Info *info,int *flags,int *err) {
 struct Elf elf;
 struct Reloc rel[4];
 void *allocated=0;
 unsigned end;
 struct Section *sections;
 struct Ops *ops=req->ops;
 int context=req->context;
 void *module;
 unsigned size,max;
 int i;
 if(func_00588C68(ops,context,fd,0,&elf,0xa0,err)) return 0;
 module=func_0058B1B8();
 if(!module) { *err=0x81050069; return 0; }
 *flags=func_005898C0(&elf,info,(unsigned char)req->mode,req->option,err);
 if(!*flags) { func_0058B1C0(module); return 0; }
 end=info->base+info->text+info->data;
 size=elf.shentsize*elf.shnum;
 sections=__builtin_alloca(size);
 if(func_00588C68(ops,context,fd,elf.offset,(void *)info->base,elf.filesz,err)) goto fail;
 if(func_00588C68(ops,context,fd,elf.shoff,sections,size,err)) goto fail;
 if(info->type!=1) {
  if(info->init+1) info->init+=info->base;
  if(info->fini+1) info->fini+=info->base;
  if(info->x30+1) info->x30+=info->base;
  info->gp+=info->base;
  if(info->entry+1) info->entry+=info->base;
  max=0;
  for(i=1;i<elf.shnum;i++) {
   struct Section *s=sections+i;
   if(s->type==9 || s->type==4) { if(max<s->size) max=s->size; }
  }
  switch(req->mode&0xf00) {
  case 0x100: {
   void *buffer;
   if(info->bss<max) {
    buffer=allocated=func_0058B138(1,max,0);
    if(!buffer) { *err=0x8105000c; goto fail; }
   } else buffer=(void *)end;
   for(i=1;i<elf.shnum;i++) {
    struct Section *s=sections+i;
    if(s->type==9) {
     if(func_00588C68(ops,context,fd,s->offset,buffer,s->size,err)) goto fail;
     func_0058B8E8(info->base,buffer,s->size/s->entsize,sections[s->info].addr,sections[s->info].size);
    }
   }
   if(allocated) func_0058B140(allocated);
   break;
  }
  case 0x200:
   *err=ops->begin(context,fd,max);
   if(*err) goto fail;
   for(i=1;i<elf.shnum;i++) {
    struct Section *s=sections+i;
    if(s->type==9) {
     int j,n;
     if(func_00588C68(ops,context,fd,s->offset,0,0,err)) goto fail;
     *err=ops->section(context,fd,s->size);
     if(*err) goto fail;
     n=s->size/s->entsize;
     for(j=0;j<n;) {
      int count=1;
      if(func_00588C68(ops,context,fd,-1,rel,8,err)) goto fail;
      if(rel[0].type==5 || rel[0].type==250) {
       count=2;
       if(func_00588C68(ops,context,fd,-1,rel+1,8,err)) goto fail;
      }
      func_0058B8E8(info->base,rel,count,sections[s->info].addr,sections[s->info].size);
      j+=count;
     }
    }
   }
   break;
  }
 }
 if(info->bss) func_005A48D8((void *)end,0,info->bss);
 func_0058B260(info,module);
 return module;
fail:
 if(allocated) func_0058B140(allocated);
 if(module) { func_00589A70(module,*flags); func_0058B1C0(module); }
 return 0;
}
