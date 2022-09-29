#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAZE_SIZE 10



typedef struct 
{
    short r;
    short c;
}element;

typedef struct Stack
{
    element data[MAX_SIZE];
    int top;
}Stack;

//���� �ʱ�ȭ �Լ� 
void init(Stack *p)
{
    p->top=-1;
}

//��ȭ ���� ���� �Լ� 
int is_full(Stack *p)
{
    return ( p->top == MAX_SIZE-1);
}

//���� ���� ���� �Լ� 
int is_empty(Stack *p)
{
    return (p->top == -1);
}

//�����Լ� 
void push(Stack *p, element data)
{
    if(is_full(p))
    {
        printf("������ ��á���ϴ�\n"); return ;
    }
    else
    {
        p->top++;
        p->data[p->top].r=data.r;
        p->data[p->top].c=data.c;
    }
}

element pop(Stack *p)
{
	if(is_empty(p)){
		fprintf(stderr,"���� ���� ����\n");
		exit(1);
	}
	else return p->data[(p->top)--];
}

element here = {1,0}, entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE]={
    {'1','1','1','1','1','1','1','1','1','1'},
    {'e','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','1','1','0','0','1','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','0','0','0','1','0','x'},
    {'1','1','1','1','1','1','1','1','1','1'}
	};
	
void push_loc(Stack *p,int r, int c)
{
	if(r<0||c<0)return;
	if(maze[r][c] != '1' && maze[r][c] != '.'){
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(p,tmp);
	}
}


 
// �̷� ���
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) 
{
	printf("\n");
	for(int r = 0; r< MAZE_SIZE;r++){
		for(int c=0;c<MAZE_SIZE;c++){
			printf("%c",maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r,c;
	Stack p;
	
	init(&p);
	here = entry;
	while(maze[here.r][here.c]!='x'){
		r = here.r;
		c = here.c;
		maze[r][c]='.';
		maze_print(maze);
		push_loc(&p,r-1,c);
		push_loc(&p,r+1,c);
		push_loc(&p,r,c-1);
		push_loc(&p,r,c+1);
		if(is_empty(&p)){
			printf("����\n");
			return 0;
		}
		else
			here = pop(&p);
			printf("(%d,%d)",here.r,here.c);
	}
	printf("����\n");
	return 0;
}
