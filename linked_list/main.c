//main.c for linked_list

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   //strcmp를 이용하기 위해서

int main()
{
  struct NODE* head = malloc(sizeof(struct NODE));
  struct NODE* tail = malloc(sizeof(struct NODE));

  char input;
  char string1[20];
  Init(head, tail);
  

  while(scanf("%c", &input))
  {
    switch(input)
    {
      case 'i':
      scanf("%s", string1);
      Insert(head, tail, string1);
      printf("Insert \n");
      Print(head);
      break;
    
    case'f':
      scanf("%s", string1);
      struct NODE* found = Find(head, string1);
      printf("Find \n");
      if(found->element == NULL)   //없어서 마지막 노드에 간 경우
      {
        printf("%s \n", "Not found");
      }
      else                        //찾은 경우
      {
        printf("%s\n", string1);
      }
      break;

    case 'd':
      scanf("%s", string1);
      printf("Delete \n");
      Delete(head, tail, string1);
      Print(head);
      break;

    case 'p':
      Print(head);
      break;

    default:
      break;
    }
  }

  return 0;
}
