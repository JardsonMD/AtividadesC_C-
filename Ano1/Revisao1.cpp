#include <stdio.h>
#include <stdlib.h>

int main(){

	int i, j, k=0, mat[5][5];
	for(i=0; i<5; i++){
		if(i%2 ==0){
			for(j=0; j<5; j++){
				mat[i][j] = ++k;
			}
		}else{
			for(j=4; j>-1; j--){
				mat[i][j] = ++k;
			}
		}
	}
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}

