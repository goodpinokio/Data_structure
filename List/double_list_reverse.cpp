#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeList {
   struct NodeList* llink;
   struct NodeList* rlink;
   int data;
}Node;

void reverseprint(Node* head) {
   Node* a;
   printf("입력데이터 출력\n");
   for (a= head->llink; a!=head ; a = a->llink)
   {
      printf("<-| |%d| |-> ", a->data);
   }
   printf("\n역순 출력\n");
   for (a = head->rlink; a != head; a = a->rlink)
   {
      printf("<-| |%d| |-> ", a->data);
   }
}
void Insert(Node** head,int data) {
   Node* NewNode = (Node*)malloc(sizeof(Node));
   NewNode->data = data;
   NewNode->llink = *head;
   NewNode->rlink = (*head)->rlink;
   (*head)->rlink->llink = NewNode;
   (*head)->rlink = NewNode;

}
int main() {

   Node* head = (Node*)malloc(sizeof(Node));

   head->rlink = head; 
   head->llink = head;
   int num = NULL;

   printf("노드의 개수입력: ");
   scanf("%d", &num);

   for (int i = 0; i < num; i++)
   {
      int data = NULL;
      printf("노드 #%d 데이터 : ", i + 1);
      scanf("%d", &data);
      Insert(&head,data);

   }
   reverseprint(head);
}
