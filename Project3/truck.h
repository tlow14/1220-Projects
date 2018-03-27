/*Author:   Tom Lowry
Purpose:  This file includes the Truck class header
Date:      26 March 2018
Summary of Modification:
None		*/
#ifndef Truck_H
#define Truck_H
#include "motorVehicle.h"

class Truck: public MotorVehicle {
public:
	//constructor
	Truck(string n  = "", string ma = "", string mo = "", double mp = 0.0, 
		double c = 0.0) : MotorVehicle(n, ma, mo, mp), cargoCapacity(c) {}
	//Accessor
	double getCargoCapacity() const;
	//mutator
	void setCargoCapacity(double c);
	//Overidding functions
	void print();
	void read();
private:
	double cargoCapacity;
};
#endif