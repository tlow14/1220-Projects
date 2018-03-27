/*Author:   Tom Lowry
  Purpose:  This file includes the implementation of MotorVehicle class 
  (defined in MotorVehicle.h) 
  Date:      26 March 2018
  Summary of Modification:
			 None		*/

#include "motorVehicle.h"

//getName changes cstring to string and returns a string
string MotorVehicle::getName() const{
	string s;
	s = name;
	return s;
}
//accessors return the variables
string MotorVehicle::getMake() const {
	return make;
}

string MotorVehicle::getModel() const {
	return model;
}

double MotorVehicle::getMpg() const {
	return mpg;
}
//returns the static variable
ostream& MotorVehicle::getOut() const {
	return *out;
}

//mutators of the class assign the passed parameter into the varible with the
//matching mutator name (Example setName takes the string and assigns it to 
//name)
void MotorVehicle::setName(string n) {
	delete[] name;
	name = new char[n.length() + 1];
	strcpy(name, n.c_str());
	return;
}

void MotorVehicle::setMake(string m) {
	make = m;
	return;
}

void MotorVehicle::setModel(string m) {
	model = m;
	return;
}

void MotorVehicle::setMpg(double m) {
	mpg = m;
	return;
}

void MotorVehicle::setOut(ostream& o) {
	out = &o;
	return;
}
//Pushes the attributes as well as some explination into the chose output
//(stdout, stdcerr, or wherever out is). In essense it prints the attributes.
void MotorVehicle::print(){
	*out << name << " has the following attributes: \n Make:           " << make 
		<< "\n Model:          " << model << "\n MPG:            " << mpg 
		<< "\n";
}
//Gives prompts so that you can input values into all the attributes of this 
//class at once
void MotorVehicle::read() {
	cout << "What is the name of your Vehicle: ";
	string s;
	cin >> s;
	setName(s);
	cout << "What is the make of your Vehicle: ";
	cin >> make;
	cout << "What is the model of your Vehicle: ";
	cin >> model;
	cout << "What is the miles per gallon for a " << make << " " << model 
		<< " : ";
	//takes it in as a string and then converts to number as to cause less 
	//errors for wrong inputs
	string strMPG;
	cin >> strMPG;
	mpg = atof(strMPG.c_str());
	return;
}