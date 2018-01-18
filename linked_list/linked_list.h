#ifndef __LINKED_LIST
#define __LINKED_LIST

struct NODE
{
  char element[20];
  struct NODE* next;
};

void Init(struct NODE* head, struct NODE* tail);
void Insert(struct NODE* head, struct NODE* tail, char* Element);
struct NODE* Find(struct NODE* head, char* Element);
void Delete(struct NODE* head, struct NODE* tail, char* Element);
void Print(struct NODE* head);

#endif
