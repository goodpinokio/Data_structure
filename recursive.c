#include<stdio.h>


int sum(int n){
	if (n<1) return 0;
	return n + sum(n-1);
}

int main(){
	
	int num1;

	printf("������ �Է��ϼ���:");
	scanf("%d",&num1);
	
	
	printf("0���� ");
	printf("%d",num1);
	printf("���� ���Ѱ���");
	
	printf("%d",sum(num1));
	system("pause");
	return 0;
}
	

