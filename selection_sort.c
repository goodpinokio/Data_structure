#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


#define MAX_SIZE 10
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

void selection_sort(int list[], int n)
{
	int i,j,least, temp;
	for(i=0;i<n-1;i++){
		least = i;
		for(j=i+1;j<n;j++)
			if(list[j]<list[least])least=j;
		SWAP(list[i],list[least],temp);
	}
}

void main()
{
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE];
	
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
	
		list[i] = rand()%100;
}

	selection_sort(list,n);
	for(i=0;i<n;i++){
	
		printf("%d",list[i]);
	
	printf(" ");
	}

	return 0;
}
