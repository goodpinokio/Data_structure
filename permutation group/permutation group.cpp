#include<stdio.h>

int sig(int n){
	if(n==1)
		return 1;
		
	else 
		return n+sig(n-1);
	
}


int main()
{
	int n=4;
	int i,sum=0;
	
	for (i=1;i<=n;i++)
		sum = sum + sig(i);
		
	printf("n이 %d인 경우 군수열의 합 = %d\n",n,sum);
}
