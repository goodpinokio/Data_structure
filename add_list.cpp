#include<stdio.h>
#include<stdlib.h>

typedef int element;
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
//�������� ���� ���ϴ� �Լ�
int total(ListNode*head) {
    ListNode *p=head;
    int sum=0;
    while(p!=NULL){
    	sum+=p->data;
    	p=p->link;
	}
	return sum;
}

int main(void) {
    ListNode *head = NULL;
    int n=0, v=0;
    printf("����� ���� : ");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        printf("��� #%d ������ : ", i);
        scanf("%d", &v);
        head = add(head, v);
    }
    printf("���� ����Ʈ�� ������ �� : %d\n", total(head));
    return 0;
}
