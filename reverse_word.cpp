#include<stdio.h>
#include<string.h>
//��� ȣ��� ���ڿ��� ������ �Լ� ���� ����
void reverse(char str[ ], int size);
int main() 
{
    reverse("flower", strlen("flower"));
    
    getchar();
}

void reverse(char str[],int size)
{
   size = size -1;
   if(size<0)
   {
      return;
   }
   printf("%c",str[size]);
   reverse("flower",size);
}
