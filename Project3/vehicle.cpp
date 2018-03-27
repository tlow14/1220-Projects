/*Author:   Tom Lowry
Purpose:  This file includes the implementation of Vehicle class
(defined in Vehicle.h)
Date:      26 March 2018
Summary of Modification:
None		*/

#include "vehicle.h"
#include <cstring>

//Needed for static variable to declared it for all classes
ostream* Vehicle::out= &cout;
//constructor initializes the variable
Vehicle::Vehicle(string n) {
	name = new char[n.length() + 1];
	strcpy(name, n.c_str());
}
//Copy Constructor. Makes a deep copy of vehicle
Vehicle::Vehicle(const Vehicle &v) {
	string s;
	s = v.name;
	name = new char[s.length() + 1];
	//copies the name from v to this object's name
	strcpy(name, v.name);
}

//Destructor frees the char* name
Vehicle::~Vehicle() {
	delete[] name;
}
//Assignment opertator allows for a deep copy
Vehicle& Vehicle::operator=(const Vehicle &v) {
	//makes sure its point to something different to begin with
	if (this == &v) {
		return *this;
	}
	else {
		//frees the char* it has already and then makes a new name
		delete[] name;
		string s;
		s = v.name;
		name = new char[s.length() + 1];
		//Copies the attribute
		strcpy(name, v.name);
		return *this;
	}
}
