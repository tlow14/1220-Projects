/*Author:   Tom Lowry
Purpose:  This file includes the Vehicle class header file
Date:      26 March 2018
Summary of Modification:
None		*/

#ifndef Vehicle_H
#define Vehicle_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Vehicle {
public: 
	//Constructors
	Vehicle(string n = "");
	Vehicle(const Vehicle &v);
	//Destructor, made virtual so it calls the right destuctor to aviod memory
	//leaks
	virtual ~Vehicle();
	//Member functions
	Vehicle& operator=(const Vehicle &v);
	//Pure Virtual functions that are going to be overwriiten in the child 
	//classes
	virtual void print() = 0;
	virtual void read() = 0;


protected:
	char* name;
	static ostream* out;
};


#endif //Vehicle_H