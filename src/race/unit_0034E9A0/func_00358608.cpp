/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Drive { char p[0x4a4]; float position; char q[4]; short lap; unsigned char gate,pad4af,back,pad4b1,blocked,pad4b3,logger; char r[0x5c1-0x4b5]; unsigned char flag; char t[0x614-0x5c2]; int time; char u[0x650-0x618]; float delta; char v[7]; unsigned char start; };
struct Position {char p[0x114]; float value; void adjust(float v) {value+=v;} void subtract(float v) {value-=v;} };
struct Car { char p[0x104]; Drive d; char q[0x888-0x104-sizeof(Drive)]; Position pos; };
struct Config { char p[0xe0]; int log0,log1; };
struct Owner { Config* config; char p[0xf898-4]; unsigned tick; char q[0x10140-0xf89c];
virtual int v0();
virtual int v1();
virtual int v2();
virtual int v3();
virtual int v4();
virtual int v5();
virtual int v6();
virtual int v7();
virtual int v8(Car*,int);
virtual int v9();
virtual int v10();
virtual int v11();
virtual int v12();
virtual int v13();
virtual int v14();
virtual unsigned v15(int);
virtual int v16();
virtual void v17(int,int,int,unsigned,int);
virtual void v18(int,int,int,unsigned,unsigned,int);
virtual void v19(int,unsigned,int,float);
virtual void v20(int,int,unsigned,unsigned,int,int,float);
virtual void v21(int,unsigned,float,int);
virtual int v22(int,int,unsigned,unsigned,int);
virtual int v23();
virtual int v24();
virtual int v25();
virtual int v26();
virtual int v27();
virtual int v28();
virtual int v29();
virtual int v30();
virtual int v31();
virtual int v32();
virtual int v33();
virtual int v34();
virtual int v35();
virtual int v36();
virtual float v37();
virtual float v38();
virtual int v39();
virtual int v40();
virtual int v41();
virtual float v42(int);
};
extern "C" Car* func_0034C190(Owner*,int);
extern "C" float DynamicsConductor__GetCourseLength(Owner*);
extern "C" int DynamicsConductor__IsExistStartV(Owner*);
extern "C" int func_0034C470(Owner*);
extern "C" float func_00359AD8(Owner*,int);
extern "C" int func_00359AF0(Car*);
extern "C" void Automobile__isDataLoggerActive(Car*,int,float,int,float,float);
extern "C" void func_00359C10(Car*,int,int,int);
extern "C" int func_00358608(Owner* self,int index,float pos) {
 Car*car=func_0034C190(self,index);
 Drive*d=&func_0034C190(self,index)->d;
 float length=DynamicsConductor__GetCourseLength(self);
 float old=d->position;
 int result=0;
 if(pos<=old) {
  if(pos+length*0.5f<old) {
   result=1;
   d->delta=(old-(pos+length))*60.0f;
   car->pos.adjust(length);
   if(++d->back>250)d->back=250;
  } else {
   float distance=old-pos;
   d->delta=distance*60.0f;
   if(!d->back && d->lap && !d->blocked) {
    float gate=self->v42(d->gate);
    if(pos<gate && gate<=old) {
     unsigned raw=self->tick+(int)(((gate-pos)/distance)*50.0f);
     raw+=self->v15(index);
     unsigned time=raw/3U;
     int dt=time-d->time;
     if(!self->v5())self->v17(index,d->lap-1,d->gate,time,dt);
     self->v18(index,d->lap,d->gate,raw,time,dt);
     d->gate++;
    }
    if(func_00359AF0(car) && self->config->log0) {
     float gate=func_00359AD8(self,d->logger);
     if(pos<gate && gate<=old) {
      float ratio=(gate-pos)/distance;
      int fraction=(int)(ratio*50.0f);
      unsigned raw=self->tick+fraction;
      raw+=self->v15(index);
      unsigned time=raw/3U;
      int dt=time-d->time;
      func_00359C10(car,self->v8(car,1),dt,self->config->log1);
      d->logger++;
      int remain=50-fraction;
      int g=self->v8(car,0);
      if(self->config->log1)Automobile__isDataLoggerActive(car,g,ratio,remain,gate,old);
     }
    }
    if(d->start==1 && DynamicsConductor__IsExistStartV(self)) {
     float gate=self->v37();
     if(pos<gate && gate<=old) {
      float ratio=(gate-pos)/distance;
      int fraction=(int)(ratio*50.0f);
      unsigned time=self->tick+fraction;
      int remain=50-fraction;
      time+=self->v15(index);
      time/=3U;
      self->v21(index,time,ratio,remain);
      d->start=2;
     }
    }
    if(func_0034C470(self)) {
     float gate=self->v38();
     if(pos<gate && gate<=old) {
      unsigned raw=self->tick+(int)(((gate-pos)/distance)*50.0f);
     raw+=self->v15(index);
      unsigned time=raw/3U;
      int dt=time-d->time;
      int active=func_00359AF0(car);
      int passed=self->v22(index,d->lap,raw,time,dt);
      if(passed && !self->v5())self->v17(index,d->lap-1,d->gate,time,dt);
      if(active && passed && self->config->log0)func_00359C10(car,self->v8(car,1),dt,self->config->log1);
     }
    }
   }
  }
 } else {
  if(old+length*0.5f<pos) {
   d->delta=((old+length)-pos)*60.0f;
   car->pos.subtract(length);
   if(d->back) {d->back--;}
   else if(!d->blocked) {
    float ratio=(length-pos)/((length-pos)+old);
    int gate=d->gate;
    int lap=d->lap;
    d->lap++;
    d->gate=0;
    int fraction=(int)(ratio*50.0f);
    unsigned raw=self->tick+fraction;
    raw+=self->v15(index);
    unsigned time=raw/3U;
    int dt=time-d->time;
    int remain=50-fraction;
    d->flag=0;
    if(lap==0) {
     self->v19(index,time,remain,ratio);
     if(func_00359AF0(car) && !self->v6() && self->config->log1)Automobile__isDataLoggerActive(car,0,ratio,remain,0.0f,old);
    } else {
     if(!self->v5())self->v17(index,lap-1,gate,time,dt);
     int active=func_00359AF0(car);
     self->v20(index,lap,raw,time,dt,remain,ratio);
     if(active && self->config->log0) {
      int g=self->v8(car,1);
      func_00359C10(car,g,dt,self->config->log1);
      if(self->v7() && !d->blocked)Automobile__isDataLoggerActive(car,g+1,ratio,remain,0.0f,old);
     }
    }
    d->logger=0;
   }
  } else {d->delta=(old-pos)*60.0f;result=1;}
 }
 return result;
}
