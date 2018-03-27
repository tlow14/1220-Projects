/*Author:   Tom Lowry
Purpose:  This file includes the implementation of Truck class
(defined in Truck.h)
Date:      26 March 2018
Summary of Modification:
None		*/
#include "truck.h"

//accessors access the named variable
double Truck:: getCargoCapacity() const {
	return cargoCapacity;
}

//mutator changes the variable of the class
void Truck::setCargoCapacity(double c) {
	cargoCapacity = c;
	return;
}

//Uses parent funciton to print MotorVehicles attributes (into given output)
//then prints cargoCapacity as well
void Truck::print(){
	MotorVehicle::print();
	*out << " Cargo Capcity:  " << cargoCapacity << "\n";
	return;
}

//Gives prompts so that you can input values into all the attributes of this 
//class at once
void Truck::read() {
	MotorVehicle::read();
	cout << "What is the cargo capacity of your vehicle: ";
	//takes it in as a string and then converts to number as to cause less 
	//errors for wrong inputs
	string strCargoCapacity;
	cin >> strCargoCapacity;
	cargoCapacity = atof(strCargoCapacity.c_str());
	return;
}