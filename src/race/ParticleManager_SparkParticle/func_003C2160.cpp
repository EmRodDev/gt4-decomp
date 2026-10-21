/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Spawns one spark of a ParticleManager::SparkParticle effect from a request (position, base angle, size, direction, two values a and b).
 * The launch speed is (b - a) times a random factor in [0.5, 0.95); sparks slower than 2 are not created. The direction is the request's
 * direction turned by the base angle plus a random +-15 degrees, normalised in its two components with the rsqrt helper, and then tilted by a
 * random angle between about -85 and -75 degrees (sign flipped for a negative speed); the velocity is that direction times the speed plus
 * 0.85 of inheritedVelocity (the vehicle's own motion, inferred). Position gets +-0.1 jitter, spin a random +-10 / +-4 / +-10, and one of
 * 8 appearance records (0x74 bytes each) is picked at random. The do-while runs once. The angle and 0.85 readings come from decoding the
 * hex float literals; the meaning of a and b is purpose unknown. */
struct V3 { float x,y,z,pad; };
struct P3 { float x,y,z; };
struct V4 { float x,y,z,w; };
struct T { char pad[116]; };
struct Manager { char pad[12]; T table[8]; };
struct Input { char pad[8]; P3 pos; float angle, size; V4 dir; char pad2[8]; float a,b; };
extern "C" void *func_003C2710(Manager *);
extern "C" void func_0040AED0(void *, V3 *, V3 *, V3 *, V4 *, float, T *);
extern "C" float pglmRandom();
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
static inline float rsqrt(float typeIndex, float inheritedVelocity) { float r=inheritedVelocity; __asm__("rsqrt.s %0, %1, %0" : "+f"(r) : "f"(typeIndex)); return r; }
extern "C" void func_003C2160(Manager *manager, Input *request, V3 *inheritedVelocity) {
 V3 velocity, position, rotation;
 float speedSign;
 float speed=(request->b-request->a)*(pglmRandom()*0x1.ccccccp-2f+0.5f);
 speedSign=speed;
 float angle, sinAngle, cosAngle, y, x, tilt, sinTilt;
 if(speed<0.0f) speed=-speed;
 if(speed<2.0f) return;
 int spawned=0;
 do {
  void *particle=func_003C2710(manager);
  if(!particle) return;
  angle=request->angle+pglmRandom()*0x1.0c1512p-1f+-0x1.0c1512p-2f;
  sinAngle=func_0057D1F0(angle);
  cosAngle=func_0057D2B8(angle);
  x=request->dir.x*cosAngle+request->dir.z*sinAngle;
  y=request->dir.y;
  float d=x*x+y*y;
  float invLength=rsqrt(1.0f,d);
  x=x*invLength;
  y=y*invLength;
  tilt=pglmRandom()*0x1.657160p-3f+-0x1.7bc884p+0f;
  if(speedSign<0.0f) tilt=-tilt;
  spawned++;
  sinTilt=func_0057D1F0(tilt);
  float cosTilt=func_0057D2B8(tilt);
  float t=sinTilt*x-cosTilt*y;
  velocity.x=t*cosAngle*speed+inheritedVelocity->x*0x1.b33332p-1f;
  velocity.y=(cosTilt*x+sinTilt*y)*speed+inheritedVelocity->y*0x1.b33332p-1f;
  velocity.z=t*sinAngle*speed+inheritedVelocity->z*0x1.b33332p-1f;
  position.x=request->pos.x+(pglmRandom()-0.5f)*0x1.999998p-3f;
  position.y=request->pos.y+(pglmRandom()-0.5f)*0x1.999998p-3f;
  position.z=request->pos.z+(pglmRandom()-0.5f)*0x1.999998p-3f;
  rotation.x=(pglmRandom()-0.5f)*20.0f;
  rotation.y=(pglmRandom()-0.5f)*8.0f;
  rotation.z=(pglmRandom()-0.5f)*20.0f;
  int typeIndex=(int)(pglmRandom()*8.0f);
  if(typeIndex>=8)typeIndex=7;
  func_0040AED0(particle,&position,&velocity,&rotation,&request->dir,request->size,&manager->table[typeIndex]);
 } while(spawned<=0);
}
