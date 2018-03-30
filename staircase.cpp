#include <iostream>
using namespace std;

//a problem recommended by a friend

void printStaircase(char* argv[]);

int main(int argc, char *argv[]) {
	printStaircase(argv);

	return 0;
}


//take in the array of strings from input
//and use the integer form to compute the number of stairs
void printStaircase(char* argv[]) {
	//convert char array to int
	int x = atoi(*(argv + 1));

	//for each number, create the corresponding number of steps
	//increasing on each loop
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < i; j++) {
			printf("_");
		}
		printf("\n");
	}
} 	
