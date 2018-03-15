#include <iostream>
using namespace std;

#define MAX 10 //size of sorted array

//runs binary search on a sorted array of integers
int binsearch(int val, int arr[]);

int main() {
	int count = 0;
	int arr[MAX];
	int arrVal, val;

	while (count != MAX) {
		cout << "Initialize index " << count << ": ";
		cin >> arrVal;
		arr[count++] = arrVal;
	}

	cout << "What value are you searching for? ";
	cin >> val;

	cout << "The index of the searched value is: " << binsearch(val, arr) << endl;

	return 0;
}

int binsearch(int val, int arr[]) {
	int left = 0;
	int right = MAX - 1;

	while (left != right) {
		int middle = left + ((right - left) / 2);

		if (arr[middle] == val) 
			return middle;
		
		if (arr[middle] < val) 
			left = middle;
		else
			right = middle;
	}

	return -1;
}

