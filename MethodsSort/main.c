#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define TEN 10
#define HUNDRED 100
// Global var
int size;

void printL(int vector[size]) {
	int i;
	for(i = 0; i < size; i++) {		
		printf("%i\n", vector[i]); 		
	}
}
    
void insert(int vector[size], char type) {
	int i, j; 
	if(type == 'r') {		
		// Random order	
		for(i = 0; i < size; i++) {		
			vector[i] = (i+1); 		
		}	
		for(i = 0; i < size; i++) {		
			int temp            = vector[i];
		    int randomIndex     = rand() % size;
		    vector[i]           = vector[randomIndex];
		    vector[randomIndex] = temp;
		}
	}  
	else if(type == 'a') {
		// Ascending oder
		for(i = 0; i < size; i++) {		
			vector[i] = (i+1); 		
		}
	} 
	else if(type == 'd') {
		// Decreasing oder
		int counter = size;
		for(i = 0; i < size; i++) {		
			vector[i] = (counter--);  		
		}
	}	
	// printL(vector); 
}
 
void insertSort(int vector[size], char type) {
	int i, j, elect;
	clock_t start, end;

	if(type == 'a') {
		// Ascending order 
		start = clock();
		for(i = 1; i < size; i++) {
			elect = vector[i];			
			for(j = i - 1; vector[j] > elect && j >= 0; j--)
				vector[j + 1] = vector[j];			
			vector[j + 1] = elect; 			
		}
		end = clock();		
		printf("Elements: %i | Time: %f\n",
			size, (end - start) / (float)CLOCKS_PER_SEC); 
	} 
	else if(type == 'd') {
		// Decreasing order
		start = clock();
		for(i = 1; i < size; i++) {
			elect = vector[i];			
			for(j = i - 1; vector[j] < elect && j >= 0; j--)
				vector[j + 1] = vector[j];			
			vector[j + 1] = elect; 			
		}
		end = clock();
		printf("Elements: %i | Time: %f\n",
			size, (end - start) / (float)CLOCKS_PER_SEC); 
	}
	// printL(vector);
}
   
void selectSort(int vector[size], char type) {
	int i, j, swap, elect;
	clock_t start, end;

	if(type == 'a') {
		// Ascending order 
		start = clock();
		for(i = 0; i < size - 1; i++) {
			elect = i;
			for(j = i + 1; j < size; j++) {
				if(vector[elect] > vector[j]) 
					elect = j;								
			}
			if(elect != i) {
				swap          = vector[i];
				vector[i]     = vector[elect];
				vector[elect] =  swap;
			}
		}
		end = clock();		
		printf("Elements: %i | Time: %f\n",
			size, (end - start) / (float)CLOCKS_PER_SEC); 
	}
	else if(type == 'd') { 
		// Decreasing order 
		start = clock();
		for(i = 0; i < size - 1; i++) {
			elect = i;
			for(j = i + 1; j < size; j++) {
				if(vector[elect] < vector[j]) 
					elect = j;								
			}
			if(elect != i) {
				swap          = vector[i];
				vector[i]     = vector[elect];
				vector[elect] =  swap;
			}
		}
		end = clock();		
		printf("Elements: %i | Time: %f\n",
			size, (end - start) / (float)CLOCKS_PER_SEC);
	}
	// printL(vector);  
}
      
void bubbleSort(int vector[size], char type) {
	int i, j, swap;
	clock_t start, end;

	if(type == 'a'){
		// Ascending order 
		start = clock();
		for(i = 0; i < size - 1; i++) {
			for(j = 0; j < (size - 1) - i; j++) {
				if(vector[j] > vector[j + 1]) {
					swap       = vector[j];
					vector[j] = vector[j + 1];
					vector[j + 1] = swap;
				}
			}
		}
		end = clock();		
		printf("Elements: %i | Time: %f\n",
			size, (end - start) / (float)CLOCKS_PER_SEC); 
	}
	else if(type == 'd') {
		// Decreasing order
		start = clock();
		for(i = 0; i < size - 1; i++) {
			for(j = 0; j < (size - 1) - i; j++) {
				if(vector[j] < vector[j + 1]) {
					swap       = vector[j];
					vector[j] = vector[j + 1];
					vector[j + 1] = swap;
				}
			}
		}
		end = clock();		
		printf("Elements: %i | Time: %f\n",
			size, (end - start) / (float)CLOCKS_PER_SEC);		 
	}
	// printL(vector);  
}
            
int main() {	
	int vHundred[HUNDRED]; 
	int vOneThousand[HUNDRED * TEN]; 
	int vTenThousand[HUNDRED * HUNDRED]; 
	int vHundredThousand[HUNDRED * HUNDRED * TEN];
	char type; 
	int option;

	do {
		printf("1 - Bubble Sort\n");
		printf("2 - Selection Sort\n");
		printf("3 - Insert Sort\n");
		printf("0 - Exit\n");
		scanf("%i", &option);

		switch(option) {
			case 1:
				/* *** METHOD BUBBLE SORT *** */
				printf("\nMethod Bubble Sort\n");
				// From random to decreasing
				printf("\nFrom random to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'r');
				bubbleSort(vHundred, 'a');	

				size *= TEN; 
				insert(vOneThousand, 'r');
				bubbleSort(vOneThousand, 'a');  

				size *= TEN; 
				insert(vTenThousand, 'r');
				bubbleSort(vTenThousand, 'a');  

				size *= TEN;
				insert(vHundredThousand, 'r');
				bubbleSort(vHundredThousand, 'a'); 

				// From random to ascending
				printf("\nFrom random to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'r');
				bubbleSort(vHundred, 'd');	

				size *= TEN; 
				insert(vOneThousand, 'r');
				bubbleSort(vOneThousand, 'd');  

				size *= TEN; 
				insert(vTenThousand, 'r');
				bubbleSort(vTenThousand, 'd');  

				size *= TEN;
				insert(vHundredThousand, 'r');
				bubbleSort(vHundredThousand, 'd');   

				// From ascending to decreasing
				printf("\nFrom ascending to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'a');
				bubbleSort(vHundred, 'd');	

				size *= TEN; 
				insert(vOneThousand, 'a');
				bubbleSort(vOneThousand, 'd');  

				size *= TEN; 
				insert(vTenThousand, 'a');
				bubbleSort(vTenThousand, 'd');  

				size *= TEN;
				insert(vHundredThousand, 'a');
				bubbleSort(vHundredThousand, 'd');

				// From ascending to ascending
				printf("\nFrom ascending to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'a');
				bubbleSort(vHundred, 'a');	

				size *= TEN; 
				insert(vOneThousand, 'a');
				bubbleSort(vOneThousand, 'a');  

				size *= TEN; 
				insert(vTenThousand, 'a');
				bubbleSort(vTenThousand, 'a');  

				size *= TEN;
				insert(vHundredThousand, 'a');
				bubbleSort(vHundredThousand, 'a');

				// From decreasing to ascending
				printf("\nFrom decreasing to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'd');
				bubbleSort(vHundred, 'a');	

				size *= TEN; 
				insert(vOneThousand, 'd');
				bubbleSort(vOneThousand, 'a');  

				size *= TEN; 
				insert(vTenThousand, 'd');
				bubbleSort(vTenThousand, 'a');  

				size *= TEN;
				insert(vHundredThousand, 'd');
				bubbleSort(vHundredThousand, 'a');

				// From decreasing to decreasing
				printf("\nFrom decreasing to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'd');
				bubbleSort(vHundred, 'd');	 

				size *= TEN; 
				insert(vOneThousand, 'd');
				bubbleSort(vOneThousand, 'd');  

				size *= TEN; 
				insert(vTenThousand, 'd');
				bubbleSort(vTenThousand, 'd');  

				size *= TEN;
				insert(vHundredThousand, 'd');
				bubbleSort(vHundredThousand, 'd');
			break;

			case 2:
				/* *** METHOD BUBBLE SORT *** */
				printf("\nMethod Selection Sort\n");
				// From random to ascending
				printf("\nFrom random to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'r');
				selectSort(vHundred, 'a'); 		

				size *= TEN;
				insert(vOneThousand, 'r');
				selectSort(vOneThousand, 'a'); 

				size *= TEN;
				insert(vTenThousand, 'r');
				selectSort(vTenThousand, 'a');

				size *= TEN;
				insert(vHundredThousand, 'r');
				selectSort(vHundredThousand, 'a');

				//From random to decreasing
				printf("\nFrom random to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'r');
				selectSort(vHundred, 'd');   

				size *= TEN;
				insert(vOneThousand, 'r');
				selectSort(vOneThousand, 'd'); 

				size *= TEN;
				insert(vTenThousand, 'r');
				selectSort(vTenThousand, 'd');

				size *= TEN;
				insert(vHundredThousand, 'r');
				selectSort(vHundredThousand, 'd');	

				//From ascending to decreasing
				printf("\nFrom ascending to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'a');
				selectSort(vHundred, 'd');   

				size *= TEN;
				insert(vOneThousand, 'a');
				selectSort(vOneThousand, 'd'); 

				size *= TEN;
				insert(vTenThousand, 'a');
				selectSort(vTenThousand, 'd');

				size *= TEN;
				insert(vHundredThousand, 'a');
				selectSort(vHundredThousand, 'd');

				//From ascending to ascending
				printf("\nFrom ascending to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'a');
				selectSort(vHundred, 'a');   

				size *= TEN;
				insert(vOneThousand, 'a');
				selectSort(vOneThousand, 'a'); 

				size *= TEN;
				insert(vTenThousand, 'a');
				selectSort(vTenThousand, 'a');

				size *= TEN;
				insert(vHundredThousand, 'a');
				selectSort(vHundredThousand, 'a');

				//From decreasing to ascending
				printf("\nFrom ascending to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'd');
				selectSort(vHundred, 'a');   

				size *= TEN;
				insert(vOneThousand, 'd');
				selectSort(vOneThousand, 'a'); 

				size *= TEN;
				insert(vTenThousand, 'd');
				selectSort(vTenThousand, 'a');

				size *= TEN;
				insert(vHundredThousand, 'd');
				selectSort(vHundredThousand, 'a');

				//From decreasing to decreasing
				printf("\nFrom decreasing to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'd');
				selectSort(vHundred, 'd');   

				size *= TEN;
				insert(vOneThousand, 'd');
				selectSort(vOneThousand, 'd'); 

				size *= TEN;
				insert(vTenThousand, 'd');
				selectSort(vTenThousand, 'd');

				size *= TEN;
				insert(vHundredThousand, 'd');
				selectSort(vHundredThousand, 'd');

			break;

			case 3: 				
				/* *** METHOD Insert SORT *** */ 
				printf("\nMethod Insert Sort\n");
				// From random to decreasing
				printf("\nFrom random to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'r');
				insertSort(vHundred, 'a');	

				size *= TEN; 
				insert(vOneThousand, 'r');
				insertSort(vOneThousand, 'a');  

				size *= TEN; 
				insert(vTenThousand, 'r');
				insertSort(vTenThousand, 'a');  

				size *= TEN;
				insert(vHundredThousand, 'r');
				insertSort(vHundredThousand, 'a'); 

				// From random to ascending
				printf("\nFrom random to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'r');
				insertSort(vHundred, 'd');	

				size *= TEN; 
				insert(vOneThousand, 'r');
				insertSort(vOneThousand, 'd');  

				size *= TEN; 
				insert(vTenThousand, 'r');
				insertSort(vTenThousand, 'd');  

				size *= TEN;
				insert(vHundredThousand, 'r');
				insertSort(vHundredThousand, 'd');   
				
				// From ascending to decreasing
				printf("\nFrom ascending to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'a');
				insertSort(vHundred, 'd');	

				size *= TEN; 
				insert(vOneThousand, 'a');
				insertSort(vOneThousand, 'd');  

				size *= TEN; 
				insert(vTenThousand, 'a');
				insertSort(vTenThousand, 'd');  

				size *= TEN;
				insert(vHundredThousand, 'a');
				insertSort(vHundredThousand, 'd');

				// From ascending to ascending
				printf("\nFrom ascending to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'a');
				insertSort(vHundred, 'a');	

				size *= TEN; 
				insert(vOneThousand, 'a');
				insertSort(vOneThousand, 'a');  

				size *= TEN; 
				insert(vTenThousand, 'a');
				insertSort(vTenThousand, 'a');  

				size *= TEN;
				insert(vHundredThousand, 'a');
				insertSort(vHundredThousand, 'a');

				// From decreasing to ascending
				printf("\nFrom decreasing to ascending\n"); 
				size = HUNDRED;
				insert(vHundred, 'd');
				insertSort(vHundred, 'a');	

				size *= TEN; 
				insert(vOneThousand, 'd');
				insertSort(vOneThousand, 'a');  

				size *= TEN; 
				insert(vTenThousand, 'd');
				insertSort(vTenThousand, 'a');  

				size *= TEN;
				insert(vHundredThousand, 'd');
				insertSort(vHundredThousand, 'a');

				// From decreasing to decreasing
				printf("\nFrom decreasing to decreasing\n"); 
				size = HUNDRED;
				insert(vHundred, 'd');
				insertSort(vHundred, 'd');	 

				size *= TEN; 
				insert(vOneThousand, 'd');
				insertSort(vOneThousand, 'd');  

				size *= TEN; 
				insert(vTenThousand, 'd');
				insertSort(vTenThousand, 'd');  

				size *= TEN;
				insert(vHundredThousand, 'd');
				insertSort(vHundredThousand, 'd');
				
			break;

			default : break;
		}
	} while(option != 0);

}           