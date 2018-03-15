#include <iostream>
#include <string.h>
using namespace std;

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))
#define LEN 10

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void printArray(int*);

int main() {
	int x;

	int arr[LEN];

	for (int i = 0; i < LEN; i++) {
		cout << "Value of index " << i << ": ";
		cin >> x;
		*(arr + i) = x;
	}

	printf("The array before sorting: ");
	printArray(arr);

	mergeSort(arr, 0, LEN - 1);

	printf("\nThe array after sorting: ");
	printArray(arr);

	return 0;
}

void mergeSort(int* arr, int left, int right) {

	if (left >= right)
		return;

	int middle = left + (right - left) / 2;
	int leftIdx = 0, rightIdx = middle + 1;

	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	merge(arr, left, middle, right);

}

void merge(int* arr, int left, int middle, int right) {
	int size = right - left + 1; 

	int temp[size];

	int leftIdx = left, rightIdx = middle + 1;
	
	for (int tempIdx = 0; tempIdx < size; tempIdx++) { 			
		bool bothHaveElements = (leftIdx <= middle && rightIdx <= right);

		if (bothHaveElements) 
			temp[tempIdx] = (arr[leftIdx] < arr[rightIdx] ? arr[leftIdx++] : arr[rightIdx++]);
		else
			temp[tempIdx] = (leftIdx > middle ? arr[rightIdx++] : arr[leftIdx++]);	
	}
	
	for (int arrIdx = left, tempIdx = 0; arrIdx <= right && tempIdx < size; arrIdx++, tempIdx++)
		arr[arrIdx] = temp[tempIdx];
}

//print the items of the array             
void printArray(int* arr) {
	for (int i = 0; i < LEN; i++)
		printf("[%d]", *(arr + i));

	printf("\n");
}
