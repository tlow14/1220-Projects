/*Author:   Tom Lowry
Purpose:  This file includes the MotorVehicle class header file.
Date:     26 March 2018
Summary of Modification:
None		*/
#ifndef MotorVehicle_H
#define MotorVehicle_H
#include "vehicle.h"


class MotorVehicle: public Vehicle {
public:
	//Constructor
	MotorVehicle(string n = "", string ma = "", string mo = "",
		double mp = 0.0): Vehicle(n), make(ma), model(mo), mpg(mp) {}
	//Accessors
	string  getName()  const;
	string  getMake()  const;
	string  getModel() const;
	double  getMpg()   const;
	ostream& getOut() const;
	//Mutators
	void setName(string n);
	void setMake(string m);
	void setModel(string m);
	void setMpg(double m);
	void setOut(ostream& o);
	//Overridding functions to the pure virtual functions in the base class
	void print();
	void read();
private:
	string make;
	string model;
	double mpg;
};
#endif 
