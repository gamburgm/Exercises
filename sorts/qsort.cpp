#include <iostream>
#include <string.h>
using namespace std;

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))
#define LEN 10

void quickSort(int*, int, int);
void swap(int *, int *);
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

    quickSort(arr, 0, LEN - 1);

    printf("\nThe array after sorting: ");
    printArray(arr);

    return 0;
}

void quickSort(int* arr, int left, int right) {
	if (left >= right)
		return;

	int middle = left + (right - left) / 2;
	int pivot = middle;

	for (int i = left; i <= right; i++) {
		if (i < pivot) {
			if (arr[i] >= arr[pivot]) {
				swap(arr + i, arr + pivot);
				pivot = i;
			}
		}
		else {
			if (arr[i] <= arr[pivot]) {
				swap(arr + i, arr + pivot);
				pivot = i;
			}
		}
	}
	swap(arr + middle, arr + pivot);

	quickSort(arr, left, middle - 1);
	quickSort(arr, middle + 1, right);
}

void swap(int* valOne, int* valTwo) {
	int temp = *valOne;

	*valOne = *valTwo;
	*valTwo = temp;
}

void printArray(int* arr) {
    for (int i = 0; i < LEN; i++)
        printf("[%d]", *(arr + i));

    printf("\n");
}
