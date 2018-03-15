#include <iostream>
using namespace std;

#define LEN 9

int binsearch(int val, int *arr); 

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


int binsearch(int val, int* arr) {
	int splitIndex, changeInRange;
	splitIndex = changeInRange = LEN/2;

	do {
		changeInRange /= 2;

		if (val == arr[splitIndex])
			return splitIndex;
		
		if (val < arr[splitIndex])
			splitIndex -= changeInRange;
		else
			splitIndex += changeInRange;
		} while (changeInRange != 0);

	return -1;
}
