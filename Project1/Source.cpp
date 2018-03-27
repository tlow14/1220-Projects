
/*Author: Tom Lowry
//Purpose: This file gives the code that reverses a string passed to it
//Date: 23 Jun 2018
//Summary of Modifications:
//None */

#include <iostream>
#include <string>
#include <locale>

using namespace std;
//This function reverses all characters inbetween the front and rear index passed to it.
void reverse(char *front, char *rear) {

	char temp = *front;

	while (front <= rear) {
		temp = *front;
		*front = *rear;
		*rear = temp;
		front = front + 1;
		rear = rear - 1;
	}

}

//This function checks to see in a all the characters in the string are integers.
bool checkDigit(char *check) {

	for (int i = 0; check != nullptr; ++i) {
		cout << *check << endl;
		if (!(isdigit(*check))) {
			return false;
		}
		
		check = check + 1;
	}
	return true;
}


int main(int argc, char** argv) {

	//This makes sure the right amount of arguements are passed before executing any other code
	if (argc != 4) {
		cout << "Usage: string frontIndex rearIndex" << endl;
		return 0;
	}

	int front = atoi(argv[2]);
	int rear = atoi(argv[3]);
	string strcopy(argv[1]);
	//string strNumCheck1(argv[2]);
	//string strNumCheck2(argv[3]);
	bool isDigit1 = true;
	bool isDigit2 = true;

	//If statements to make sure the user inputs valid inputs for the index integers
	if (rear >= strcopy.length()) {
		cout << "Usage: the rear index must be less than the length of " << strcopy << " (i.e., less than " << rear << ")" << endl;
		return 0;
	}

	if ((front < 0 || front > rear) && isDigit2) {
		cout << "Usage: the front index must be non-negative and less than or equal to the rear index (i.e., less than equal to " << rear << ")" << endl;
		return 0;
	}

	//Checks to make sure the digits are only integers
	isDigit1 = checkDigit(argv[2]);
	isDigit2 = checkDigit(argv[3]);

	if (isDigit1 == false || isDigit2 == false) {
		cout << "Usage: " << argv[2] << " and " << argv[3] << " must both integers" << endl;
		return 0;
	}

	char* frontPtr = &argv[1][front];
	char* rearPtr = &argv[1][rear];

	reverse(frontPtr, rearPtr);
	cout << "Reversing \"" << strcopy << "\" from position " << front << " to postion " << rear << " yeilds \"" << argv[1] << "\"." << endl;
	return 0;
}