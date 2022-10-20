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

//리스트를 마지막에 추가하는 함수
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

//특정한 값을 없애는 함수 
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
    printf("노드의 개수: ");
    scanf("%d", &n);
    for(int i = 1; i<= n;i++) {
        printf("노드 #%d 데이터: ", i);
        scanf("%d", &v);
        head = insert_last(head,v);
    }
    printf("출력: ");
    print_list(head);
    printf("\n");
	printf("삭제할 값을 입력하세요 : ");
	scanf("%d",&del1);
	printf("\n");
	
	head = del(head,del1);
	print_list(head); 
    return 0;
}
