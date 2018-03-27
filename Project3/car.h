/*Author:   Tom Lowry
Purpose:  This is file of the Car header class
Date:      26 March 2018
Summary of Modification:
None		*/
#ifndef Car_H
#define Car_H
#include "motorVehicle.h"

class Car: public MotorVehicle {
public:
	//constructors
	Car(string n = "", string ma = "", string mo = "", double mp = 0.0, 
		string t = "") : MotorVehicle(n, ma, mo, mp), trim(t) {}
	//Accessors
	string getTrim() const;
	//Mutators
	void setTrim(string t);
	//Overidding functions
	void print();
	void read();

private:
	string trim;
};
#endif