#include <stdio.h>

#define LEN 10

void bubbleSort(int* arr);
void printArray(int* arr);

int main() {
	int* arr;
	int num;

	for (int i = 0; i < LEN; i++) {
		printf("Value of index %d: ", i);
			
		scanf("%d", &num);
		*(arr + i) = num;
	}

	printf("The array, before sorting: ");
	printArray(arr);

	bubbleSort(arr);

	printf("The array, after sorting: ");
	printArray(arr);

	return 0;	
}

void bubbleSort(int* arr) {
	int temp;

	for (int i = 0; i < LEN; i++) {
		for (int j = i + 1; j < LEN; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void printArray(int* arr) {
	for (int i = 0; i < LEN; i++)
        printf("[%d]", *(arr + i));
	
	printf("\n");
}	
	
