/* Copies the race entries, ordered by rank, into per-slot tables of the screen object (shape inferred from the offsets): for entry i
 * it writes a name-like string at +4 + i*0x80 (func_005A609C of func_00445450(entry object)), a 0x10-byte record at +0x304 + i*0x10
 * (func_00445AE8), and a word at +0x454 + i*4 that is the entry's value at +0x718 when its byte at +0x5B6 is set, otherwise the
 * sentinel 0x157529FF. The index of the first entry whose flag is zero goes to +0x4A0. The list comes from *(other + 0x6C)->list, sorted
 * first by RaceEntryBase::sortByRank. What the tables are used for is unknown (probably a results display). */
struct N{char pad[0x10];N*next;int flag;char*data;char pad1c[4];char object[1];};
struct L{int count;char pad[0x10];N*head;};
struct O{char pad[0x60];L*list;};
extern "C" void RaceEntryBase__sortByRank(L*);
extern "C" char *func_00445450(char*);
extern "C" void func_005A609C(char*,char*);
extern "C" void func_00445AE8(char*,char*);
extern "C" void func_00114390(char*self,char*other){
 O*owner=*(O**)(other+0x6c);
 RaceEntryBase__sortByRank(owner->list);
 N*node=owner->list->head;
 int index=0;
 if(owner->list->count>0){
 int sentinel=0x157529ff;int*valueSlot=(int*)(self+0x454);char*recordSlot=self+0x304;char*nameSlot=self+4;
 do{
  char*entryObject=(char*)node+0x20;
  func_005A609C(nameSlot,func_00445450(entryObject));
  func_00445AE8(entryObject,recordSlot);recordSlot+=0x10;
  char*entryData=node->data;
  if(*(unsigned char*)(entryData+0x5b6))*valueSlot=*(int*)(entryData+0x718);else *valueSlot=sentinel;
  if(!node->flag)*(int*)(self+0x4a0)=index;
  ++index;node=node->next;++valueSlot;nameSlot+=0x80;
 }while(index<owner->list->count);
 }
}
