/* compiler: ee-gcc2.96-g */
typedef unsigned int u32;
struct Node { int type; int value; void *arg; char data[0x100]; Node **children; u32 count; };
struct Obj {
 char pad0[0x8008]; Node *root;
 char pad800c[0xc0c]; void *arg;
 char pad8c1c[8]; void (*start)(int,void *,void *);
 void (*end)(int,void *);
 void (*text)(int,void *,void *);
};
extern "C" int func_00541DD8(Obj *,Node **) throw();
extern "C" int func_00541D78(Obj *,Node *) throw();
extern "C" int func_00541EF0(Obj *obj) {
 Node *prev=0;
 Node *node=0;
 int r;
 r=func_00541DD8(obj,&node);
 if(r!=0) return r;
 while(node!=0) {
  r=func_00541DD8(obj,&node);
  if(r!=0) return r;
 }
 if(obj->root==0) return 0;
 if(obj->start) obj->start(obj->root->value,obj->root->data,obj->arg);
 r=func_00541D78(obj,obj->root);
 if(r!=0) return r;
 do {
  r=func_00541DD8(obj,&node);
  if(r!=0) return r;
  if(node==0) break;
  u32 next=0;
  for(u32 i=0;i<node->count;i++) {
   if(prev==node->children[i]) { next=i+1; break; }
  }
  if(next<node->count) {
   r=func_00541D78(obj,node);
   if(r!=0) return r;
   if(node->children[next]->type==1 && obj->start) {
    obj->start(node->children[next]->value,node->children[next]->data,obj->arg);
   } else if(node->children[next]->type==2 && obj->text) {
    obj->text(node->children[next]->value,node->children[next]->arg,obj->arg);
   }
   r=func_00541D78(obj,node->children[next]);
   if(r!=0) return r;
  } else if(next==node->count) {
   if(node->type==1 && obj->end) obj->end(node->value,obj->arg);
   prev=node;
  } else return 0;
 } while(node!=0);
 return 0;
}
