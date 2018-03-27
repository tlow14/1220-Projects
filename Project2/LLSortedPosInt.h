#ifndef LLSortedPosInt_H
#define  LLSortedPosInt_H
#include <iostream>
using namespace std;

// forward declaration
struct  Node;

// typedef to help code readability
typedef Node* NodePtr;

// The key value HEAD_OF_LIST is used as a "sentinel" value
const int HEAD_OF_LIST = -1;

// the linked-list SPECIFICATION
class LLSortedPosInt {
public:
	// constructors
	LLSortedPosInt();
	LLSortedPosInt(int  key);
	LLSortedPosInt(int *keys, int n);
	LLSortedPosInt(const LLSortedPosInt &l);

	// destructor
	~LLSortedPosInt();

	bool                  containsElement(int key) const;
	bool                  isEmpty() const;

	LLSortedPosInt&       operator= (const LLSortedPosInt &l);
	bool                  operator==(const LLSortedPosInt &l) const;
	bool                  operator!=(const LLSortedPosInt &l) const;

	friend LLSortedPosInt operator+ (const LLSortedPosInt &l1,
		const LLSortedPosInt &l2);
	friend LLSortedPosInt operator- (const LLSortedPosInt &l1,
		const LLSortedPosInt &l2);
	friend ostream&       operator<<(ostream &out,
		const LLSortedPosInt &l);
private:
	void                  insert(int key);
	void                  remove(int key);

	NodePtr head;
};
#endif //LLsortedPosInt_H