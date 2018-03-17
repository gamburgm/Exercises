#include <iostream>
#include <string.h>
using namespace std;

#define LEN 10
#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))

int binsearch(int* arr, int val, int right);

int main() {
	int count = 0;
	int arr[LEN];
	int arrVal, val;

	while (count != LEN) {
		cout << "Initialize index " << count << ": ";
		cin >> arrVal;
		arr[count++] = arrVal;
	}

	int right = ARRAY_LEN(arr) - 1;

	cout << "What value are you searching for? ";
	cin >> val;
 
	cout << "The index of the searched value is: " << binsearch(arr, val, right) << endl;
 
	return 0;
}

int binsearch(int* arr, int val, int right) {

	if (right == 0)
		return (val == arr[right] ? right : -1);	

	int middle = right / 2;

	if (val == arr[middle])
		return middle;

	int newArrSize = (val < arr[middle] ? middle : right - middle);

	int halfArr[newArrSize];
	
	int shiftInIdx = (val < arr[middle] ? 0 : right - middle);

	val < arr[middle] ? memcpy(halfArr, arr, sizeof(halfArr)) : memcpy(halfArr, &arr[middle + 1], sizeof(halfArr));

	int newRight = ARRAY_LEN(halfArr) - 1;

	int foundIdx = binsearch(halfArr, val, newRight);

	return (foundIdx < 0 ? -1 : foundIdx + shiftInIdx); 
}	
