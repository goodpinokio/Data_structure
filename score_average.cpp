#include <stdio.h>
#define SIZE 10
#define OUT 4.3

void convert(double*grades, double*scores, int size);
int main(void)
{
	double grades[SIZE]={3.7,4.3,3.6,0.7,1.1,2.1,3.1,4.0,3.0,2.0};
	double scores[SIZE]={0};
	int i;
	convert(grades,scores,SIZE);
	for(i=0;i<SIZE;i++)
		printf("학생%d 의 평점: %lf\n", i+1, grades[i]);
	for(i=0;i<SIZE;i++)
		printf("학생%d의 점수: %lf\n",i+1,scores[i]);
		
	
}

void convert(double *grades,double*scores,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		*(scores+i)=*(grades+i)*(100/OUT);
	}
}
