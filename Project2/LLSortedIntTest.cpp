#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "LLSortedPosInt.h"
using namespace std;

#define NUM_LISTS 5

void showMenu();
int  rangeCorrect(int);

int main(int argc, char **argv) {
	if (argc > 2) {
		cout << "Usage:  testLL [NoMenu]\n";
		return 0;
	}

	bool noMenu = false;

	if (argc == 2 && strcmp(argv[1], "NoMenu") == 0) {
		noMenu = true;
	}

	// create several lists to work with
	LLSortedPosInt l[NUM_LISTS];

	int            a[] = { 3, 5, -6, 2, 7, 4 };

	// test the different constructors
	l[2] = LLSortedPosInt(2);
	l[3] = LLSortedPosInt(a, 6);
	l[4] = LLSortedPosInt(l[3]);

	{
		// test for memory leak
		LLSortedPosInt temp = l[4];
	}

	// variables to test our implementation
	int              i, k, lnum;
	char             cmd;

	// try various linked-list functions, until q is typed
	do {
		if (!noMenu) showMenu();
		cin >> cmd;

		switch (cmd) {

			// print a list
		case 112: cin >> lnum;
			cout << "List[" << lnum << "]:  ";
			lnum = rangeCorrect(lnum);
			cout << l[lnum] << endl;
			break;

			// print all lists
		case  80: for (i = 0; i < NUM_LISTS; i++) {
			cout << "List[" << i << "]:  ";
			cout << l[i] << endl;
		}
				  break;

				  // insert an element into a list
		case 105: cin >> i >> lnum;
			lnum = rangeCorrect(lnum);
			cout << "Inserting " << i << " into list[" << lnum << "]\n";
			l[lnum] = l[lnum] + i;
			break;

			// remove an element from a list
		case 114: cin >> i >> lnum;
			lnum = rangeCorrect(lnum);
			cout << "Removing " << i << " from list[" << lnum << "]\n";
			l[lnum] = l[lnum] - i;
			break;

			// assign one list to another
		case  97: cin >> i >> lnum;
			i = rangeCorrect(i);
			lnum = rangeCorrect(lnum);
			cout << "Assigning list[ " << i << "] to list[" << lnum
				<< "]\n";
			l[lnum] = l[i];
			break;

			// merge two lists together
		case 109: cin >> i >> k >> lnum;
			i = rangeCorrect(i);
			k = rangeCorrect(k);
			lnum = rangeCorrect(lnum);
			cout << "Merging list[ " << i << "] and list[" << k
				<< "] as list[" << lnum << "]\n";
			l[lnum] = l[i] + l[k];
			break;

			// subtract one list from another
		case 115: cin >> i >> k >> lnum;
			i = rangeCorrect(i);
			k = rangeCorrect(k);
			lnum = rangeCorrect(lnum);
			cout << "Subtracting list[ " << k << "] from list[" << i
				<< "] as list[" << lnum << "]\n";
			l[lnum] = l[i] - l[k];
			break;

			// test if the list is empty
		case 121: cin >> lnum;
			lnum = rangeCorrect(lnum);
			if (l[lnum].isEmpty()) {
				cout << "List[" << lnum << "] is empty\n";
			}
			else {
				cout << "List[" << lnum
					<< "] is not empty\n";
			}
			break;

			// test if the list as a certain element
		case  99: cin >> i >> lnum;
			lnum = rangeCorrect(lnum);
			if (l[lnum].containsElement(i)) {
				cout << "List[" << lnum << "] contains "
					<< i << "\n";
			}
			else {
				cout << "List[" << lnum
					<< "] does not contain " << i << "\n";
			}
			break;

			// test two lists for equality
		case 101: cin >> i >> lnum;
			i = rangeCorrect(i);
			lnum = rangeCorrect(lnum);
			if (l[i] == l[lnum]) {
				cout << "List[" << i
					<< "] is identical to list ["
					<< lnum << "]\n";
			}
			else {
				cout << "List[" << i
					<< "] is different from list ["
					<< lnum << "]\n";
			}
			break;

			// test two lists for inequality
		case 110: cin >> i >> lnum;
			i = rangeCorrect(i);
			lnum = rangeCorrect(lnum);
			if (l[i] != l[lnum]) {
				cout << "List[" << i
					<< "] is different from list ["
					<< lnum << "]\n";
			}
			else {
				cout << "List[" << i
					<< "] is identical to list ["
					<< lnum << "]\n";
			}
			break;

			// quit the program
		case 113: break;

			// any other leading letter is considered a comment
		default: {
			string dummy;
			getline(cin, dummy);
		}
				 break;
		}
	} while (cmd != 113);

	return 0;
}

// display the menu of choices
void showMenu() {
	cout << "This program tests the linked list implementation\n";
	cout << "Use the following single-letter commands to test:\n";
	cout << "  e # #      - compare two lists          ";
	cout << "n # #      - compare lists (not equal)\n";
	cout << "  p #        - print list #               ";
	cout << "P          - print all lists\n";
	cout << "  i #1 #2    - insert elem 1 into list 2  ";
	cout << "r #1 #2    - remove elem 1 from list 2\n";
	cout << "  s #1 #2 #3 - subtract list 2 frm 1 to 3 ";
	cout << "m #1 #2 #3 - merge list 1 & 2 into 3\n";
	cout << "  y #        - ask if list # is empty     ";
	cout << "c #1 #2    - ask is elem 1 in list 2\n";
	cout << "  a #1 #2    - assign list 1 to list 2    ";
	cout << "q          - quit the test program\n\n";
	cout << "Command:  ";
}

int  rangeCorrect(int n) {
	if (n < 0 || n > NUM_LISTS - 1) {
		cout << "rangeCorrect error:  list index " << n
			<< " is outside range 0 to " << NUM_LISTS - 1 << endl;
	}

	return max(0, min(NUM_LISTS - 1, n));
}
