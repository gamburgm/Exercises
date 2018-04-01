#include <iostream>
using namespace std;

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))

void printArray(int* arr, int len);
void swap(int* valOne, int* valTwo);
void quicksort(int* arr, int loIdx, int hiIdx);
void pivot(int* arr, int loIdx, int midIdx, int hiIdx);
int partition(int* arr, int loIdx, int hiIdx);

int main() {
	int arr[10]; 

	for (int i = 0; i < 10; i++) {
		int x;
		cout << "what number? ";
		cin >> x;
		arr[i] = x;
	}
	

	printArray(arr, 10);

	quicksort(arr, 0, 10);

	printArray(arr, 10);

	return 0;
}


void quicksort(int* arr, int loIdx, int hiIdx) {
	if (loIdx >= hiIdx)
		return;

	int midIdx = loIdx + (hiIdx - loIdx) / 2;
	pivot(arr, loIdx, midIdx, hiIdx);

	int pivotIdx = partition(arr, loIdx, hiIdx);

	quicksort(arr, loIdx, pivotIdx);
	quicksort(arr, pivotIdx + 1, hiIdx);
}

int partition(int* arr, int loIdx, int hiIdx) {
	int pivot = arr[loIdx];
	int curLo = loIdx;
	int curHi = hiIdx - 1;	

	while (curLo < curHi) {
		while (curLo < hiIdx && arr[curLo] <= pivot) 
			curLo++;
		while (curHi > loIdx && arr[curHi] > pivot)
			curHi--;
		if (curLo < curHi)
			swap(arr + curLo, arr + curHi);	
	}
	swap(arr + loIdx, arr + curHi);
	return curHi;
}	

void pivot(int* arr, int loIdx, int midIdx, int hiIdx) {
	int* first = arr + loIdx;
	int* mid = arr + midIdx;
	int* last = arr + hiIdx;

	if ((*mid >= *first && *mid <= *last) || (*mid <= *first && *mid >= *last)) 	
		swap(mid, first);
	else if ((*last >= *first && *last <= *mid) || (*last <= *first && *last >= *mid)) 
		swap(last, first);
	else
		return;
}

void swap(int* valOne, int* valTwo) {
	int temp = *valOne;
	*valOne = *valTwo;
	*valTwo = temp;
}


void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) 
		cout << "[" << arr[i] << "]";
	cout << endl;
} 
