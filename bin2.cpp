#include <iostream>
using namespace std;

#define LEN 10

int binsearch(int val, int arr[]); 
int recurBinsearch(int midpoint, int val, int arr[]);

int main() {
	int count = 0;
	int arr[LEN];
	int arrVal, val;

	while (count != LEN) {
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
	return recurBinsearch(LEN/2, val, arr);
}

int recurBinsearch(int midpoint, int val, int arr[]) {
	int newMidpoint;

	if (val == arr[midpoint]) 
		return midpoint;
	
	if (val < arr[midpoint]) {
		newMidpoint = midpoint - (midpoint/2);

		if (midpoint == newMidpoint) 
			return -1;
		else
			return recurBinsearch(newMidpoint, val, arr);
	}	
	else {
		newMidpoint = midpoint + (midpoint/2);
		
		if (midpoint == newMidpoint)
			return -1;
		else
			return recurBinsearch(newMidpoint, val, arr);
	}
} 
