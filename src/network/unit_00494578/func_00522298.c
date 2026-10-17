/* compiler: ee-gcc2.96-nsa-g */
struct S { unsigned int count; float rate, max; };
void func_00522298(struct S *s, unsigned int elapsed) {
 float rate;
 if(elapsed!=0) s->rate=(float)s->count/((float)elapsed/1000.0f);
 else s->rate=0.0f;
 rate=s->rate;
 if(s->max<rate)s->max=rate;
 s->count=0;
}
