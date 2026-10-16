extern "C" void free(void*);
struct String{char* data;~String(){int* header=(int*)(data-16);if(--header[2]==0)free(header);}};
struct Value{int data;unsigned payload;~Value();};
extern "C" void func_004768C0(Value*);
inline Value::~Value(){func_004768C0(this);}
struct Pair{String key;Value value;};
struct Node{int a,b;Node* left;Node* right;Pair pair;};
extern "C" void func_00606258(void* tree,Node* p){while(p){func_00606258(tree,p->right);Node* left=p->left;p->pair.~Pair();free(p);p=left;}}
