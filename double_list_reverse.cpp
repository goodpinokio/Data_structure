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
   printf("�Էµ����� ���\n");
   for (a= head->llink; a!=head ; a = a->llink)
   {
      printf("<-| |%d| |-> ", a->data);
   }
   printf("\n���� ���\n");
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

   printf("����� �����Է�: ");
   scanf("%d", &num);

   for (int i = 0; i < num; i++)
   {
      int data = NULL;
      printf("��� #%d ������ : ", i + 1);
      scanf("%d", &data);
      Insert(&head,data);

   }
   reverseprint(head);
}
