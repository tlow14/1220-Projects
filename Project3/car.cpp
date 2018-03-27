/*Author:   Tom Lowry
Purpose:  This file includes the implementation of car class
(defined in car.h)
Date:      26 March 2018
Summary of Modification:
None		*/
#include "car.h"

//accessor returns the variable of the class
string Car::getTrim() const {
	return trim;
}
//mutator changes the attributes value of trim
void Car::setTrim(string t) {
	trim = t;
	return;
}

//Uses parent funciton to print MotorVehicle's attributes (into given output)
//then prints trim as well
void Car::print() {
	MotorVehicle::print();
	*out << " Trim:           " << trim << "\n";
	return;
}
//Gives prompts so that you can input values into all the attributes of this 
//class at once
void Car::read() {
	MotorVehicle::read();
	cout << "What is the trim level of your vehicle: ";
	cin >> trim;
	return;
}