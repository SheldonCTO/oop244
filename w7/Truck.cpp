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
#include <iostream>
#include <iomanip>
#include "MotorVehicle.h"
#include "Truck.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
	void Truck::setSafe()
	{
		if (m_capacity != 0.0 || m_cargo != 0.0)
		{
			m_capacity = 0.0;
			m_cargo = 0.0;
		}
	}

	Truck::Truck(const char* license, int year, double capacity, const char* address) : MotorVehicle(license,year)
	{
		setSafe();
		if (license != nullptr || year > 0 || capacity > 0.0 || address != nullptr)
		{
			m_capacity = capacity;
			//m_cargo == 0.0 set by setSafe
			MotorVehicle::moveTo(address);
		}
	}

	bool Truck::addCargo(double cargo)
	{
		bool change = true;
		double newCargo;
		// if capacity still have space: cargo less than capa
		//add currect para to member cargo
		if (m_cargo < m_capacity)
		{
			newCargo = m_cargo + cargo;
			if (newCargo < m_capacity)
			{
				m_cargo = newCargo;
			}
			else
			{
				m_cargo = m_capacity;
			}
		}
		else
		{
			//no change, bool false
			change = false;
		}
		return change;
	}
	//set member cargo to 0, if it is not 0
	//if change , return true
	bool Truck::unloadCargo()
	{
		bool change = (m_cargo != 0);
		if(change)
		{
			m_cargo = 0;
		}
		return change;
	}

	//update os object from current
	//call MotorVehicle(write) to display the first part
	ostream& Truck::write(ostream& os)const
	{
		MotorVehicle::write(os);
		os  << " | ";
		os << m_cargo << "/" << m_capacity;
		return os;
	}



	//Capacity: [USER TYPES HERE]
	//Cargo : [USER TYPES HERE]
	istream& Truck::read(istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;
	}

	ostream& operator<<(ostream& os, const Truck& newTruck)
	{
		newTruck.write(os);
		return os;
	}
	istream& operator>>(istream& in, Truck& newTruck)
	{
		newTruck.read(in);
		return in;
	}
}