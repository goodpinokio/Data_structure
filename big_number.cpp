#include<stdio.h>

int main()
{
	int num1,num2,num3,max;
	int cnt,cnt1;
	printf("���� if �����\n");
	printf("�� ������ �Է��Ͻÿ�: ");
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
	printf ("���� ū ���� %d�Դϴϴ�\n",max);
	printf("ī��Ʈ Ƚ��:%d\n",cnt);
	printf("���� if~else �������� ���\n");
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
	
	printf("���� ū ���� %d �Դϴ�\n",max);
	printf("ī��Ʈ Ƚ��:%d",cnt1);
}
