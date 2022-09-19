#include<stdio.h>


int sum(int n){
	if (n<1) return 0;
	return n + sum(n-1);
}

int main(){
	
	int num1;

	printf("정수를 입력하세요:");
	scanf("%d",&num1);
	
	
	printf("0부터 ");
	printf("%d",num1);
	printf("까지 더한값은");
	
	printf("%d",sum(num1));
	system("pause");
	return 0;
}
	

