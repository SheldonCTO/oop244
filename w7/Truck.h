/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// professor's tester program
//
// Name: Ngai Man Szeto
// ID:180094211
// Section: ZAA
// Email:nszeto1@myseneca.ca
// Revision History

// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>
#include "MotorVehicle.h"


using namespace std;

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_capacity = { 0.0 };
		double m_cargo = { 0.0 };
		void setSafe();
	public:

		//set construct and receive para licence, yeay, capacity and address
		//set cargo 0 
		Truck(const char* license, int year, double capacity, const char* address);
		
		//update cargo para to member cargo
		//
		//return false, if member cargo is greater than or equal capacity
		//if less than, cargo para + m_cargo to new
		//if new small m_capacity, set new to m_cargo
		//if not, set m_capacity to m_cargo
		bool addCargo(double cargo);

		//if current m_cargo is not 0,set member cargo to O and return true, 
		bool unloadCargo();

		//update os object from current
		//fm: | [CURRENT_CARGO]/[CAPACITY]
		ostream& write(ostream& os)const;

		////user input to read the object value
		istream& read(istream& in);


	};
	ostream& operator<<(ostream& os, const Truck& newTruck);
	istream& operator>>(istream& in, Truck& newTruck);

}

#endif // !_TRUCK_H_

