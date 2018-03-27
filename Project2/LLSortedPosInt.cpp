#include "LLSortedPosInt.h"
#include <vld.h>
// The linked-list is constructed of Node elements
struct Node {
	int   key;
	Node *next;
};

// createNode() allocates a Node and initializes it with the
// given parameter values to simplify the initilization of a Node
static NodePtr createNode(int key, NodePtr p) {
	// allocate a new Node for storing the given key value
	NodePtr n = new Node;

	// store the key value and the next pointer
	n->key = key;
	n->next = p;

	// return the new Node to the caller
	return n;
}


// Implementation of the LLSortedPosInt begins here
// Constructors

LLSortedPosInt::LLSortedPosInt() {
	// create the sentinal Node at the head of the list
	head = createNode(HEAD_OF_LIST, nullptr);
}

LLSortedPosInt::LLSortedPosInt(int key) {
	// create the sentinal Node at the head of the list
	head = createNode(HEAD_OF_LIST, nullptr);
	// add the single element key, as long as it is positive
	if (key > 0) {
		NodePtr firstElement;
		firstElement = createNode(key, nullptr);
		head->next = firstElement;
	}
}

LLSortedPosInt::LLSortedPosInt(int *keys, int n) {
	// create the sentinal node at the head of the list
	head = createNode(HEAD_OF_LIST, nullptr);

	// add new Nodes for each positive value in keys
	for (int i = 0; i < n; ++i) {
		if (keys[i] > 0 && head->next == nullptr) {
			NodePtr firstElement = createNode(keys[i], nullptr);
			head->next = firstElement;
		}
		else if (keys[i] > 0) {
			insert(keys[i]);
		}
	}
}

LLSortedPosInt::LLSortedPosInt(const LLSortedPosInt &l) {
	//builds sentinal and creates a deep copy of the input list l
	head = createNode(HEAD_OF_LIST, nullptr);
	NodePtr previousNode = head;
	for (NodePtr p = l.head->next; p != nullptr; p = p->next) {
		NodePtr currentNode = createNode(p->key, nullptr);
		previousNode->next = currentNode;
		previousNode = currentNode;
	}
}

// Destructor

LLSortedPosInt::~LLSortedPosInt() {
	// free the Nodes in *this, including the sentinal
	NodePtr previous = head;
	for (NodePtr p = head; p != nullptr; p = p->next) {
	if (p->next == nullptr &&  p != head) {
	delete p;
	p = head;
	previous->next = nullptr;
	}
	previous = p;
	}
	delete previous;
}

// Boolean Functions

bool LLSortedPosInt::containsElement(int key) const {
	// return true if key is in the list; return false otherwise
	for (NodePtr p = head; p->next != nullptr; p = p->next) {
		if (key == p->key) {
			return true;
		}
	}
	return false;
}

bool LLSortedPosInt::isEmpty() const {
	// return true if only the sentinal is in the list; return false otherwise
	// Do I need both I may only need the nullptr part
	if (head->key == HEAD_OF_LIST && head->next == nullptr) {
		return true;
	}
	return false;
}

// Operators
LLSortedPosInt&  LLSortedPosInt::operator=
(const LLSortedPosInt &l) {
	// handle self assignment
	if (this == &l) {
		return *this;
	}
	else {
		// free old elements of the list before the new elements from l are 
		//assigned
		NodePtr previous = head;
		for (NodePtr p = head; p != nullptr; p = p->next) {
		if (p->next == nullptr &&  p != head) {
		delete p;
		p = head;
		previous->next = nullptr;
		}
		previous = p;
		}
		delete previous;

		//rebuilds sentinal
		head = createNode(HEAD_OF_LIST, nullptr);

		// build the list as a deep copy of l
		NodePtr previousNode = head;
		for (NodePtr p = l.head->next; p != nullptr; p = p->next) {
			NodePtr currentNode = createNode(p->key, nullptr);
			previousNode->next = currentNode;
			previousNode = currentNode;
		}
	}
	// return *this
	return *this;
}

bool LLSortedPosInt::operator==(const LLSortedPosInt &l) const {
	// compare the Nodes in *this with the Nodes in l
	NodePtr tempThis = head;
	NodePtr tempL = l.head;
	//compares all the nodes except the last one
	while (tempL->next != nullptr && tempThis->next != nullptr) {
		if (tempL->key != tempThis->key) {
			return false;
		}
		tempL = tempL->next;
		tempThis = tempThis->next;
	}
	//compares the last node
	if (tempL->key != tempThis->key || (tempL->next != tempThis->next)) {
		return false;
	}
	// if all Node key values in *this match the cooresponding
	//  Node key values in l, then the lists are equivalent
	return true;
}

bool LLSortedPosInt::operator!=(const LLSortedPosInt &l) const {
	// do the opposite of operator==
	if (*this == l) {
		return false;
	}
	return true;
}

LLSortedPosInt  operator+ (const LLSortedPosInt &l1,
	const LLSortedPosInt &l2) {
	// create a copy of l1 and add each element of l2 to it in 
	// the correct (sorted ascending) order, allow duplicates
	LLSortedPosInt sum;
	sum = l1;
	for (NodePtr p = l2.head->next; p != nullptr; p = p->next) {
		sum.insert(p->key);
	}
	return sum;
}

LLSortedPosInt  operator- (const LLSortedPosInt &l1,
	const LLSortedPosInt &l2) {
	// copy l1 and remove all of l2 from l1, taking care to 
	// reclaim any storage -- do not to remove the sentinal Node
	LLSortedPosInt diff;
	diff = l1;
	for (NodePtr p = l2.head->next; p != nullptr; p = p->next) {
		diff.remove(p->key);
	}
	return diff;
}

ostream&  operator<<  (ostream &out, const LLSortedPosInt &l) {
	// an empty list will be printed as <>
	// a singleton list (a list having one key value k) will be
	//printed as <k>
	// a list having multiple keys such as 2, 5, 7 will be printed
	//     as <2, 5, 7>

	// print the left angle bracket
	out << "<";
	// print the keys in the list l
	for (NodePtr p = l.head->next; p != nullptr; p = p->next) {
		if (p == l.head->next) {
			out << p->key;
		}
		else {
			out << ", " << p->key;
		}
	}
	// print the right angle bracket
	out << ">";
	return out;
}

// The following helper functions are provide to assist you in
// building the class--these helper functions are useful in
// several places among the functions you will write--take time
// to learn what they do

// insert() inserts an element in the linked list in sorted order
void LLSortedPosInt::insert(int key) {

	// setup pointers to walk the list
	NodePtr npp = head;
	NodePtr npc = head->next;

	// walk the list, searching until the given key value is exceeded
	while (npc != NULL && npc->key <= key) {
		npp = npc;
		npc = npc->next;
	}

	// insert the new value into the list
	npp->next = createNode(key, npc);
}

// remove() removes an element from the list (if it is present)
void LLSortedPosInt::remove(int key) {

	// negative values should not be stored in the list
	if (key <= 0) {
		return;
	}

	// setup pointers to walk the list
	NodePtr npp = head;
	NodePtr npc = head->next;

	// search the list until the end (if necessary)
	while (npc != NULL) {

		// if the key value is found, then splice this Node from the list and
		// reclaim its storage
		if (npc->key == key) {
			npp->next = npc->next;
			delete npc;
			break;
		}

		// walk the pointers to the next Node
		npp = npc;
		npc = npc->next;
	}
}

