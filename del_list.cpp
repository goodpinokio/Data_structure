#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void error(const char *msg) {
    fprintf(stderr,"%s\n", msg);
    exit(1);
}

//����Ʈ�� �������� �߰��ϴ� �Լ�
ListNode *insert_last(ListNode *head, element item) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = item;
    p->link = NULL;
    if(head == NULL) {
        p->link = head;
        head = p;
    } else {
        ListNode *lastNode = head;
        while(lastNode->link!= NULL)
            lastNode = lastNode->link;
        lastNode->link = p;
    }
    return head;
}

//Ư���� ���� ���ִ� �Լ� 
ListNode *del(ListNode *head, element item) {
    ListNode *removed = head, *p = NULL;
    while(removed->data != item) {
        p = removed;
        removed = removed->link;
    }
    if(p==NULL) head = head->link;
    else p->link = removed->link;

    free(removed);
    return head;
}

void print_list(ListNode *head) {
    ListNode *p = head;
    while(p!=NULL) {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("NULL \n");
}

int main() {
    ListNode *head = NULL;
    int n, v;
    int del1; 
    printf("����� ����: ");
    scanf("%d", &n);
    for(int i = 1; i<= n;i++) {
        printf("��� #%d ������: ", i);
        scanf("%d", &v);
        head = insert_last(head,v);
    }
    printf("���: ");
    print_list(head);
    printf("\n");
	printf("������ ���� �Է��ϼ��� : ");
	scanf("%d",&del1);
	printf("\n");
	
	head = del(head,del1);
	print_list(head); 
    return 0;
}
