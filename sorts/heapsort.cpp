#include <iostream>
#include <string.h>
#include <string>
using namespace std;

#define LEN 10

void buildHeap(int* arr);
void heapsort(int* arr);
void upheap(int* arr, int valIdx);
void downheap(int* arr, int valIdx, int maxIdx);
void swap(int* valOne, int* valTwo);
void printArray(int* arr);

int main() {
	int arr[LEN];
	
	for (int i = 0; i < LEN; i++) {
		int x;
		printf("Initialize index %d in array: ", i);
		cin >> x;
		arr[i] = x;
	}

	printf("Original Array:\n");
	printArray(arr);

	printf("Array in Heap form:\n");
	buildHeap(arr);
	printArray(arr);

	printf("Sorted Array:\n");
	heapsort(arr);
	printArray(arr);

	return 0;
}

void buildHeap(int* arr) {
	for (int i = 1; i < LEN; i++) 
		upheap(arr, i);
}

void upheap(int* arr, int valIdx) {
	if (valIdx == 0)
		return;

	int parentIdx = (valIdx - 1) / 2;
	if (arr[valIdx] > arr[parentIdx]) {
		swap(arr[valIdx], arr[parentIdx]);
		upheap(arr, parentIdx);
	}
}

void heapsort(int* arr) {
	for (int i = 0; i < LEN; i++) {
		int maxIdx = LEN - 1 - i;
		
		swap(arr[0], arr[maxIdx]);
		downheap(arr, 0, maxIdx - 1);
	}
}	

void downheap(int* arr, int valIdx, int maxIdx) {
	int leftChildIdx = (2 * valIdx) + 1;
	int rightChildIdx = (2 * valIdx) + 2;
	int biggestChildIdx;

	if (leftChildIdx > maxIdx)
		return;

	if (rightChildIdx > maxIdx)
		biggestChildIdx = leftChildIdx;
	else
		biggestChildIdx = (arr[leftChildIdx] > arr[rightChildIdx] ? leftChildIdx : rightChildIdx);		

	if (arr[valIdx] < arr[biggestChildIdx]) {
		swap(arr[valIdx], arr[biggestChildIdx]);
		downheap(arr, biggestChildIdx, maxIdx);
	}
} 

void swap(int* valOne, int* valTwo) {
	int temp = *valTwo;
	*valTwo = *valOne;
	*valOne = temp;
}

void printArray(int* arr) {
	for (int i = 0; i < LEN; i++) 
		cout << "[" << arr[i] << "]";
	printf("\n");
}	
