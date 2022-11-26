#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define NAME_SIZE 100

typedef struct
{
	int key;
	char name[NAME_SIZE];
}record;

record A[MAX_SIZE];
int n;
void record_inserton_sort();

int main()
{
	int i, j;
	clock_t a, b;
	printf("Enter the number of Records to generate: ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	{
		A[i].key = rand() % 100;
		for (j = 0; j <= NAME_SIZE - 2; j++)
			A[i].name[j] = rand() % 26 + 'a';
		A[i].name[j] = rand() % 26 + 'a';
		A[i].name[j] = '\0';
		printf("%d(%s)\n", A[i].key, A[i].name);
	}

	a = clock();
	record_inserton_sort();
	b = clock();

	printf("\n\nSorted array : \n");
	for (i = 0; i < n; i++)
		printf("%d(%s)\n", A[i].key, A[i].name);
	printf("\n");

	for (i = 0; i < n - 1; i++)
		if (A[i].key > A[i + 1].key) break;
	if (i == n - 1) printf("정렬 완료!!\n");
	else printf("정렬 안됨!!\n");
	printf("\n");
	printf("Execution Duration = %f\n", (double)(b - a) / CLOCKS_PER_SEC);
}

void record_inserton_sort()
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		record rec = A[i];
		for (j = i - 1; j >= 0 && A[j].key > rec.key; j--)
			A[j + 1] = A[j];
		A[j + 1] = rec;
	}
}