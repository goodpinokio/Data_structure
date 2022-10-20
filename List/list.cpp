#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[100];
}element;

typedef struct ListNode{
	element data;
	struct ListNode *link;		
}ListNode;

void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
} 
ListNode* insert_first(ListNode *head,element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s->",p->data.name);
	printf("NULL \n");
}


int main(void)
{
	ListNode *head = NULL;
	element data;
	
	strcpy(data.name,"»ç°ú");
	head= insert_first(head,data);
	print_list(head);
	
	strcpy(data.name,"¹Ù³ª³ª");
	head= insert_first(head,data);
	print_list(head);
	
	strcpy(data.name,"Å°À§");
	head= insert_first(head,data);
	print_list(head);
	
	strcpy(data.name,"¹è");
	head= insert_first(head,data);
	print_list(head);
	
	strcpy(data.name,"Æ÷µµ");
	head= insert_first(head,data);
	print_list(head);
	return 0;
}
