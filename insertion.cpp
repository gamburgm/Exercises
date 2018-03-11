#include <stdio.h>
#include <stdlib.h>
    
#define LEN 10
void insertionSort(int* arr);
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
        
    insertionSort(arr);
        
    printf("The array, after sorting: ");
    printArray(arr);
        
    return 0;
}
    
//sort the items in an array using insertion sort
void insertionSort(int* arr) {
        
	//i checks through each value in the array to see if it should be placed elsewhere
    for (int i = 1; i <= LEN - 1; i++) {
		//j checks all values of the array less than i to see if they should be swapped
        for (int j = i - 1; j >= 0; j--) {
            
			//if incorrect order, swap
            if (arr[j] > arr[j + 1]) {
                int temp;
        
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
			//else, proper location found, exit loop
            else
                break;
        }
    }
}
    
    
    
             
//print the items of the array             
void printArray(int* arr) {
    for (int i = 0; i < LEN; i++)
        printf("[%d]", *(arr + i));
    
    printf("\n");
}

