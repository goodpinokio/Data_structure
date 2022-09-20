#include <stdio.h>

int recursive(int n){
   
  	if(n<1){	
  		return 0;
	}
	recursive(n-1);
	printf("%d \t",n);
	
}
int main(void){
    int n=100;
    recursive(n);
    
    return 0;
}
