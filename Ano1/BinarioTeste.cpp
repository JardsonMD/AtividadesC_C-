#include <stdio.h>
#include <stdlib.h>

void binario(int n, int *vet, int id){
    if(n == 0){
        printf("%d", n);
        vet[id] = n;
    }
    else{
        binario(n/2, vet, id - 1);
        printf("%d", n % 2);
        vet[id] = n % 2;
    }
}

int main () {

int num[30];
   int bin[8]; // <---------------
   int aux, i;

  for(i=0; i<30; i++){
  	num[i] = i+1;
  }
	for(i=0; i<30; i++){
		for (aux = 7; aux >= 0; aux--)
	   {
	      if (num[i] % 2 == 0)
	         bin[aux] = 0;
	      else
	         bin[aux] = 1;
	      num[i] = num[i] / 2;
	   }
	
	   for (aux = 0; aux < 8; aux++)
	       printf("%d", bin[aux]);
	    printf("\n");
	}
    return 0;
}
