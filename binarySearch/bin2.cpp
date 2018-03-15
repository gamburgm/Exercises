#include <iostream>
using namespace std;

#define LEN 10

int binsearch(int val, int *arr); 
int recurBinsearch(int left, int right, int val, int *arr);

int main() {
	int count = 0;
	int arr[LEN];
	int arrVal, val;

	while (count < LEN) {
		cout << "Initialize index " << count << ": ";
		cin >> arrVal;
		arr[count++] = arrVal;
	}

	cout << "What value are you searching for? ";
	cin >> val;

	cout << "The index of the searched value is: " << binsearch(val, arr) << endl;

	return 0;
}


int binsearch(int val, int *arr) {
	return recurBinsearch(0, LEN - 1, val, arr);
}

int recurBinsearch(int left, int right, int val, int *arr) {
	int splitIndex  = left + (right - left) / 2;

	if (val == arr[splitIndex]) 
		return splitIndex;
	
	return val < arr[splitIndex] ? 
		recurBinsearch(left, splitIndex, val, arr) :
		recurBinsearch(splitIndex, right, val); 
}

