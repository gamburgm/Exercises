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



int binsearch(int val, int* arr) {
	int splitIndex = LEN/2;
	
	for (int changeInRange = splitIndex/2; changeInRange != 0 && val != arr[splitIndex]; changeInRange /= 2) 
		splitIndex += (val < arr[splitIndex] ? -changeInRange : changeInRange);
	
	return (val == arr[splitIndex] ? splitIndex : -1);

}	
