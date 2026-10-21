/* Loads per-entry data of a ranked list into a race object. Sorts the list found through source+0x6C with
 * RaceEntryBase__sortByRank, then for each node copies func_00445450 of the entry object into the 0x80-byte slot starting at +4,
 * runs func_00445AE8 on the entry with a 0x10-byte slot from +0x304, stores either the entry data's word at +0x718 (when its byte
 * at +0x5B6 is set) or the marker 0x157529FF at +0x454 onward, and records the rank of the first node whose flag is zero at
 * +0x4A0 (all inferred from the code, field purposes unknown). */
struct N{char pad[0x10];N*next;int flag;char*data;char pad1c[4];char object[1];};
struct L{int count;char pad[0x10];N*head;};
struct O{char pad[0x60];L*list;};
extern "C" void RaceEntryBase__sortByRank(L*);
extern "C" char *func_00445450(char*);
extern "C" void func_005A609C(char*,char*);
extern "C" void func_00445AE8(char*,char*);
extern "C" void func_0011C1D8(char*self,char*source){
 O*owner=*(O**)(source+0x6c);
 RaceEntryBase__sortByRank(owner->list);
 N*node=owner->list->head;
 int rank=0;
 if(owner->list->count>0){
 int noValueMarker=0x157529ff;int*valueSlot=(int*)(self+0x454);char*auxSlot=self+0x304;char*nameSlot=self+4;
 do{
  char*entryObject=(char*)node+0x20;
  func_005A609C(nameSlot,func_00445450(entryObject));
  func_00445AE8(entryObject,auxSlot);auxSlot+=0x10;
  char*entryData=node->data;
  if(*(unsigned char*)(entryData+0x5b6))*valueSlot=*(int*)(entryData+0x718);else *valueSlot=noValueMarker;
  if(!node->flag)*(int*)(self+0x4a0)=rank;
  ++rank;node=node->next;++valueSlot;nameSlot+=0x80;
 }while(rank<owner->list->count);
 }
}
