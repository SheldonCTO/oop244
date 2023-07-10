/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Name: Ngai Man Szeto
// ID:180094211
// Section: ZAA
// Email:nszeto1@myseneca.ca
// Submission Date: 06-17-2023
// Revision History

// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
	class Mark
	{
		int m_mark;
		bool valid();
		bool numValid(int number);
	public:
		Mark();
		Mark(int number);
		operator int ();
		operator int ()const;
		Mark& operator += (int);
		Mark& operator = (int);
		operator double();
		operator char();
	};
	double operator +=(int& value, Mark& newMark);
}

#endif // SDDS_MARK_H_