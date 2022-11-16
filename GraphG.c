#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
    int v;
    g->n =0;
    for(v=0;v<MAX_VERTICES;v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g,int u,int v)
{
    GraphNode *node;
    if(u >= g->n|| v>= g->n){
        fprintf(stderr,"그레프: 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node -> vertex = v;
    node -> link = g->adj_list[u];
    g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s)
{
    return(s->top ==-1);
}

int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE -1));
}

void push(StackType *s,element item)
{
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}

element pop(StackType *s)
{
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else  return s->stack[(s->top)--];
}

int topo_sort(GraphType *g)
{
    int i;
    StackType s;
    GraphNode *node;

    int *in_degree = (int *)malloc(g->n * sizeof(int));
    for(i=0;i<g->n;i++)
        in_degree[i] = 0;
    for(i=0;i<g->n;i++){
        GraphNode *node = g->adj_list[i];
        while (node != NULL)
        {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    init(&s);
    for(i=0;i<g->n;i++){
        if(in_degree[i] == 0) push(&s, i);
    }
    while(!is_empty(&s)){
        int w;
        w = pop(&s);
        printf("정점 %d ->",w);
        node = g->adj_list[w];
        while (node != NULL)
        {
            int u = node -> vertex;
            in_degree[u]--;
            if(in_degree[u] == 0) push(&s,u);
            node = node->link;
        }
        
    }
    free(in_degree);
    printf("\n");
    return (i==g->n);
}

int main(void)
{
    GraphType g;

    graph_init(&g);
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);
    insert_vertex(&g, 6);
    insert_vertex(&g, 7);
    insert_vertex(&g, 8);
    insert_vertex(&g, 9);

    //정점 0의 인접리스트 생성
    insert_edge(&g,0,1);

    //정점 1의 인접리스트 생성
    insert_edge(&g,1,2);
    insert_edge(&g,1,3);
    
    //정점 2의 인접리스트 생성
   
    insert_edge(&g,2,4);

    //정점 3의 인접리스트 생성
    
    insert_edge(&g,3,5);

    //정점 4의 인접리스트 생성
    
    insert_edge(&g,4,3);

    //정점 5의 인접리스트 생성
    
    insert_edge(&g,5,6);
    insert_edge(&g,5,7);

    //정점 6의 인접리스트 생성
   
    insert_edge(&g,6,7);

    //정점 7의 인접리스트 생성
    
    insert_edge(&g,7,8);
    insert_edge(&g,7,9);

    //정점 8의 인접리스트 생성
    //insert_edge(&g,8,7);

    //정점 9의 인접리스트 생성
    //insert_edge(&g,9,7);

    //위상 정렬
    topo_sort(&g);

    return 0;


}
