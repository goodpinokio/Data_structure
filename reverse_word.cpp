#include<stdio.h>
#include<string.h>
//재귀 호출로 문자열을 뒤집는 함수 원형 정의
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
