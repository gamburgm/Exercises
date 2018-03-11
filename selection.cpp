#include <stdio.h>
#include <stdlib.h>
    
#define LEN 10
void selectionSort(int* arr);
void printArray(int* arr);
    
int main() {
    int* arr;    //the array of numbers being sorted
    int num;     //input for the array
        
	//initialize the array from user input
    for (int i = 0; i < LEN; i++) {
        printf("Value of index %d: ", i);
            
        scanf("%d", &num);
        *(arr + i) = num;
    }
        
	//print the array before and after sorting
    printf("The array, before sorting: ");
    printArray(arr);
        
    selectionSort(arr);
        
    printf("The array, after sorting: ");
    printArray(arr);
        
    return 0;
}

//sort the values of an array using selection sort
void selectionSort(int* arr) {
	int start = LEN - 1;    //The location where every recursion through the array will begin
	int lowestValIndex;     //The index of the lowest value found in a loop through the array
	
	//finds the lowest value from arr[i] to arr[start] and moves it to index i
	for (int i = 0; i <= start; i++) {
		lowestValIndex = start;

		//loops through the array and finds the lowest value
		for (int j = start; j >= i; j--) {
			if (arr[j] < arr[lowestValIndex])
				lowestValIndex = j;
		}

		int temp;

		temp = arr[lowestValIndex];
		arr[lowestValIndex] = arr[i];
		arr[i] = temp;
	}
}	
		 


//print the items of the array             
void printArray(int* arr) {
    for (int i = 0; i < LEN; i++)
        printf("[%d]", *(arr + i));
    
    printf("\n");
}

			
