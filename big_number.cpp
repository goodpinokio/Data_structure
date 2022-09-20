#include<stdio.h>

int main()
{
	int num1,num2,num3,max;
	int cnt,cnt1;
	printf("이중 if 문사용\n");
	printf("세 정수를 입력하시오: ");
	scanf("%d %d %d",&num1,&num2,&num3);
	if(num1>=num2){
		cnt+=1;
		if(num1>=num3){
		
			max = num1;
			cnt+=1;
		}
		else {
		max=num3;
		cnt+=1;
		}
	}
	else{
		if(num2>=num3) max=num2;
		else max=num3;
	}
	printf ("가장 큰 수는 %d입니니다\n",max);
	printf("카운트 횟수:%d\n",cnt);
	printf("이중 if~else 논리연산자 사용\n");
	if(num1>=num2 && num1>=num3){
	max=num1;
	cnt1+=1;
	
	} 
	
	else if(num2>=num1 && num2>=num3)
	{
		max = num2;
		cnt1+=1;
	} 
	else {
		max = num3;
		cnt1+=1;
	}
	
	printf("가장 큰 수는 %d 입니다\n",max);
	printf("카운트 횟수:%d",cnt1);
}
