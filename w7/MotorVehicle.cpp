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
#include <cstring>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
	//private, set to safe
	 void MotorVehicle::setSafe()
	 {
	 	if (m_year < 0 && m_license != nullptr && m_address != nullptr)
	 	{
	 		m_license=nullptr;
	 		m_address= nullptr;
	 		m_year = -1;
	 	}
	 }

	// Construct allocate memory by setSafe() and receives as parameters license, year and "Factory"
	MotorVehicle::MotorVehicle(const char *license, int year)
	{
		setSafe();
		if (year > 0 && license != nullptr)
		{
			m_license = new char[strLen(license) + 1];
			strCpy(m_license, license);
			m_year = year;
			m_address = new char[strLen("Factory") + 1];
			strCpy(m_address, "Factory");
		}
	}

	// display format
	//|[    8w]| |[      20w] ---> [20w      ]|
	void MotorVehicle::moveTo(const char *address)
	{
		if (strcmp(m_address, address) != 0)
		{
			cout << "|";
			cout << right << setw(8) << m_license << "| |";
			cout << right << setw(20) << m_address << " ---> ";
			cout << left << setw(20) << address << "|" << endl;
			m_address = new char[strlen(address) + 1];
			strCpy(m_address, address);
		}
	}

	// update fm
	//| [YEAR] | [PLATE] | [ADDRESS]
	ostream &MotorVehicle::write(ostream &os) const
	{
		os << "| " << m_year << " | " << m_license << " | " << m_address;
		return os;
	}

	// Built year : [USER TYPES HERE]
	// License plate : [USER TYPES HERE]
	// Current location : [USER TYPES HERE]
	istream &MotorVehicle::read(istream &in)
	{
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_license;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}

	// helper overload
	// extraction operators : insert new vehicle to os
	ostream &operator<<(ostream &os, const MotorVehicle &NewVehicle)
	{
		NewVehicle.write(os);
		return os;
	}

	// helper overload
	// extraction operators : read new vehiclie from  in
	istream &operator>>(istream &in, MotorVehicle &NewVehicle)
	{
		NewVehicle.read(in);
		return in;
	}

}