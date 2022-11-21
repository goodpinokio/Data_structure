#include <stdio.h>
#include <stdlib.h>
#define SIZE1 7
#define SIZE2 7
#define Count_Vertice 7
#define Far_Distance 1000
#include <time.h>

int D[Count_Vertice][Count_Vertice]; // D[i][j]는 i에서 j까지 가는 최소 거리를 저장
int P[Count_Vertice][Count_Vertice]; // P[i][j]는 i에서 j까지 가는 데 거치는 최고 차수 정점을 저장

void Floyd1(){
    int a,b;
    int grade[SIZE2][SIZE1]; //배열,변수선언. 

    srand((int)time(NULL)); //랜덤함수

    for(a=0;a<SIZE2;a++){ //2차원 배열에
        for(b=0;b<SIZE1;b++){
            grade[a][b]=rand()%1000;//랜덤값 저장(보기쉽게1000까지했습니다)
        }

    }
    int i,j,k;
    for(i=0;i<Count_Vertice;i++)
        for(j=0;j<Count_Vertice;j++){
            P[i][j] = -1;
            D[i][j] = grade[i][j];
        }
        for(k=0;k<Count_Vertice;k++)
		    for(i=0; i < Count_Vertice; i++)
	    		for(j=0; j < Count_Vertice; j++)
                    if(D[i][j] > D[i][k] + D[k][j]){
                        D[i][j] = D[i][k] + D[k][j];
                        P[i][j] = k;
                    }
}   

void Print_Path(int a, int b){ // Print_Path[i][j]에서 i와 j는 출력하지 않음을 주의
	if(P[a][b] != -1) { // P[a][b] = -1 "=" a에서 바로 b로 가는 것이 최단거리
		Print_Path(a, P[a][b]);
		printf("%d ", P[a][b]);
		Print_Path(P[a][b], b);
	}
}

int main(int argc, char *argv[]){
	// Floyd();
    Floyd1();
	int a, b;
	printf("출발점과 도착점을 입력하시오. (0 ~ %d)\n", Count_Vertice - 1);
	scanf("%d %d", &a, &b);
	printf("최단거리 : %d\n", D[a][b]);
	printf("최단경로 : ");
	printf("%d ", a); Print_Path(a, b);
	if(D[a][b] != 0) printf("%d", b); // D[a][b] = 0 "=" a = b
	return 0;
}