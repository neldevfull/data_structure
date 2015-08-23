#include <stdlib.h> 
#include <stdio.h>
#define SIZE 5

void insertSort(int vector[SIZE]) {
	int i, j, elect; 
	printf("\n\nInicio da ordenacao por insercao \n");
	for(i = 1; i < SIZE; i++) {
		elect = vector[i];
		printf("\nEleito numero %i \n", elect);
		for(j = i - 1; vector[j] > elect && j >= 0; j--) {			
			vector[j + 1] = vector[j];
			printf("%i e maior que %i, entao substitui! - Vetor no momento da substituicao: %i | %i | %i | %i | %i \n",
				vector[j], elect, vector[0], vector[1], vector[2], vector[3], vector[4]);	
		} 		
		vector[j + 1] = elect;			
		if(j != (i - 1)) {		
			printf("Eleito %i e inserido - Vetor apos a insercao: %i | %i | %i | %i | %i \n",
				elect, vector[0], vector[1], vector[2], vector[3], vector[4]);	
		}
		else {
			printf("Nao ha numero maior que eleito para ordenacao \n");
		}
	}
}

void insert(int vector[SIZE]) {
	int i;
	printf("\nInsira 5 numeros inteiros \n");
	for(i = 0; i < SIZE; i++) {
		printf("%i: ", (i + 1));
		scanf("%i", &vector[i]);		
	}
}

int main() {

	int vector[SIZE], i;

	insert(vector);

	printf("\nVector antes da ordenacao crescente \n");
	for(i = 0; i < SIZE; i++) {
		printf("%i ", vector[i]);
	}

	insertSort(vector);

	printf("\nVector ordenado com sucesso \n");
	for(i = 0; i < SIZE; i++) {
		printf("%i ", vector[i]);
	}
	printf("\n\n");  
}