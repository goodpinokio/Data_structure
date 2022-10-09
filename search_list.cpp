#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<limits.h>

typedef struct {
    char name[10];
    int dang; 
}element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
}ListNode;

ListNode *add(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) 
	{
        printf("�����̸�: %s \n", p->data.name);
        printf("�絵: %d \n", p->data.dang);
        printf(" | \n");
        printf(" | \n");
    }
    printf("\n");
}

void max(ListNode *head) {
    int max = INT_MIN;
    char* nick;
    ListNode *p = head;
    while(p != NULL) {
        if(max <= p->data.dang){
        	max = p->data.dang;
        	nick= p->data.name;
		} 
        p = p->link;
    }
    printf(" ���� ���� ���� ������ : %s �׸��� �絵�� : %d", nick,max);
}
int main(void) 
{	
    ListNode *head = NULL;
    
    element h1 = {"���", 34};
    element h2 = {"��", 27};
    element h3 = {"Ű��", 48};
    element h4 = {"���ξ���", 30};
	element h5 = {"�ٳ���", 34};

    head = add(head, h1);
    head = add(head, h2);
    head = add(head, h3);
    head = add(head, h4);
    head = add(head, h5);
    
    print_list(head);
    max(head);
    return 0;
}
