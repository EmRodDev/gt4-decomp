/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Params { const unsigned char *gain; int gain_bits, pitch_bits; };
extern "C" unsigned func_00567B38(void *,int);
extern "C" void func_0056CE00(int *exc,int start,int end,int pitch_coef,Params *params,int nsf,int *pitch_val,short *gain_val,void *bits,int stack,int lost,int offset,short last_gain,int cdbk_offset) {
    int i;
    short gain[3];
    int *e[3];
    int cdbk_size=1<<params->gain_bits;
    const unsigned char *gain_cdbk=params->gain;
    gain_cdbk += cdbk_size*cdbk_offset*3;
    int pitch=func_00567B38(bits,params->pitch_bits)+start;
    int index=func_00567B38(bits,params->gain_bits);
    gain[0]=(signed char)gain_cdbk[3*index]+32;
    gain[1]=(signed char)gain_cdbk[3*index+1]+32;
    gain[2]=(signed char)gain_cdbk[3*index+2]+32;
    if(lost && pitch>offset) {
        float gain_sum;
        float max_gain;
        if(lost<4)max_gain=last_gain*(1.0f/64);
        else max_gain=last_gain*0.00625f;
        if(max_gain>0.95f)max_gain=0.95f;
        gain_sum=(1.0f/64)*((gain[1]<0?-gain[1]:gain[1])+(gain[0]>0?gain[0]:-(gain[0]>>1))+(gain[2]>0?gain[2]:-(gain[2]>>1)));
        if(gain_sum>max_gain) {
            float fact=max_gain/gain_sum;
            for(i=0;i<3;i++)gain[i]=(short)(gain[i]*fact);
        }
    }
    stack+=(-stack)&15;
    *pitch_val=pitch;
    gain_val[0]=gain[0];gain_val[1]=gain[1];gain_val[2]=gain[2];
    e[0]=(int *)stack;
    e[1]=e[0]+nsf;
    e[2]=e[0]+2*nsf;
    for(i=0;i<3;i++) {
        int pp=pitch+1-i;
        int tmp1=pp<nsf?pp:nsf;
        int j;
        for(j=0;j<tmp1;j++)e[i][j]=exc[j-pp];
        int tmp2=nsf; if(pp+pitch<nsf)tmp2=pp+pitch;
        for(j=tmp1;j<tmp2;j++)e[i][j]=exc[j-pp-pitch];
        for(j=tmp2;j<nsf;j++)e[i][j]=0;
    }
    for(i=0;i<nsf;i++) {
        int g0=gain[0]<<7,g2=gain[2]<<7,g1=gain[1]<<7;
        int x=e[2][i],y=e[0][i],z=e[1][i];
        exc[i]=((g0*(x>>15)+((g0*(x&32767))>>15))+(g1*(z>>15)+((g1*(z&32767))>>15))+(g2*(y>>15)+((g2*(y&32767))>>15)))<<2;
    }
}
