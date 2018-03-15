#include <stdio.h>
#include <stdlib.h>
    
#define LEN 10
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

void mergeSort(int* arr, int size);
void merge(int *, int *, int *, int, int);
void printArray(int* arr);
    
int main() {
    int arr[LEN];    //the array of numbers being sorted
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
        
	int sizeOfArray = ARRAY_SIZE(arr);
    mergeSort(arr, sizeOfArray);
        
    printf("The array, after sorting: ");
    printArray(arr);
        
    return 0;
}



void mergeSort(int* arr, int sizeOfArray) {

	int divider = sizeOfArray / 2;
	
	int firstHalf[divider];
	int secondHalf[sizeOfArray - divider];

	if (sizeOfArray == 1 || sizeOfArray == 0)
		return;
	else {
		for (int arrIndex = 0; arrIndex < divider; arrIndex++) 
			firstHalf[arrIndex] = arr[arrIndex];
		 
		for (int destIdx = 0, srcIdx = divider; srcIdx < sizeOfArray; destIdx++, srcIdx++)
			secondHalf[destIdx] = arr[srcIdx];

		int sizeOfFirst = ARRAY_SIZE(firstHalf);
		int sizeOfSecond = ARRAY_SIZE(secondHalf);

		mergeSort(firstHalf, sizeOfFirst);
		mergeSort(secondHalf, sizeOfSecond);

		merge(arr, firstHalf, secondHalf, sizeOfFirst, sizeOfSecond);
	}
}


void merge(int* arr, int* firstHalf, int* secondHalf, int sizeOfFirst, int sizeOfSecond) {

	int sizeOfArr = sizeOfFirst + sizeOfSecond;

	int firstIndex = 0;
	int secondIndex = 0;

	for (int arrIndex = 0; arrIndex < sizeOfArr; arrIndex++) {

		bool bothHaveElements = (firstIndex < sizeOfFirst && secondIndex < sizeOfSecond);

		if (bothHaveElements) {
			arr[arrIndex] = (firstHalf[firstIndex] < secondHalf[secondIndex] ?
				firstHalf[firstIndex++] :
				secondHalf[secondIndex++]);
		}
		else {
			arr[arrIndex] = (firstIndex >= sizeOfFirst ? 
				secondHalf[secondIndex++] :
				firstHalf[firstIndex++]);
		}
	}	
}


//print the items of the array             
void printArray(int* arr) {
    for (int i = 0; i < LEN; i++)
        printf("[%d]", *(arr + i));
    
    printf("\n");
}
