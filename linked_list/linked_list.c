//linked_listi

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Init(struct NODE* head, struct NODE* tail)
{
   head->next = NULL;   //head의 next를 NULL로 초기화

   tail->next = head;   //tail이 head를 가리키고 있도록 설정
}

void Insert(struct NODE* head, struct NODE* tail, char* Element)
{
   //새로운 node 만들기
   struct NODE* tmp = malloc(sizeof(struct NODE));   //새로운 node 생성
   int i;
    for(i=0;i<20;i++)
   {
      tmp->element[i]= Element[i];    //새로운 node에 data를 담기
   }
   tmp->next = NULL;         //새로운 node의 next를 NULL로 설정
  
   struct NODE *P = tail->next;    //tail이 가리키고 있는 node위치 정보를 복사

   P->next = tmp;                  //tail이 가리키는 node(node의 마지막부분)가 tmp를 가리키도록 설정
   tail->next = tmp;               //tail이 가리키는 node를 재설정
}

struct NODE* Find(struct NODE* head, char* Element)
{
    struct NODE* P = head->next;    //head의 정보를 복사하여

    while(P != NULL && strcmp(P->element, Element) != 0)   //P가 마지막 node가 아니고, Element를 찾지 못할 경우 다음 노드로 이동
    {
      P = P->next;
    }
  
   return P;
}

void Delete(struct NODE* head, struct NODE* tail, char* Element)
{ 
    struct NODE* P = head->next;
    
    while(P != NULL && strcmp(P->next->element, Element) != 0)
    {
      P = P->next;
    }

    if(P->next == tail->next)   //삭제할 node가 마지막 노드일 경우, tail의 처리
    {
      tail->next = P;
      free(P->next);
    }
    else
    {
      struct NODE* target = P->next;
      P->next = target->next;
      free(target);
    }
}

void Print(struct NODE* head)
{
    struct NODE* P = head->next;    //head의 정보를 복사하여

    while(P != NULL)                //마지막 node까지, 각 node의 element를 출력하고 다음 node로 이동
    {
      printf("%s \n", P->element);
      P = P->next;
    }
}
