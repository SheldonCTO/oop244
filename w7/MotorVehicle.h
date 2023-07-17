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

#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_
#include <iostream>  

using namespace std;
namespace sdds
{
	const int MAX_LICE_NO=9;
	const int MAX_ADDRESS_SIZE=64;

	class MotorVehicle
	{
		//set default private members to safe status
		char* m_license{ nullptr };
		int m_year = -1;
		char* m_address{ nullptr };
		
		void setSafe();
	public:
			// construct memory
			//set receives as parameters licence and year to member, if value is valid
			MotorVehicle(const char* license,int year);
			
			//display the Member licence, address, and the new address 
			//licece field 8width to right
			//member address field 20w to right
			//new address field 20w to left 
			//update the new address to member
			//|[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|
			void moveTo(const char* address);
			
			//insert date to new object from current
			//| [YEAR] | [PLATE] | [ADDRESS]
			ostream& write(ostream& os)const;

			//user input to read the object value
			istream& read(istream& in);
	};
	ostream& operator<<(ostream& os, const MotorVehicle& NewVehicle);
	istream& operator>>(istream& in, MotorVehicle& NewVehicle);

}
#endif // !MOTORVEHICLE.H_