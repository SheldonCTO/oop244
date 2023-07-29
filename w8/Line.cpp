/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
// Name: Ngai Man Szeto
// Student No: 180094211
// Email: nszeto1
// Section: ZAA
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Line.h"

using namespace std;
namespace sdds
{
	
	//Passes the Cstring to the LblShape constructor 
	//set member variable m_length to length
	Line::Line(const char* labelString, int length) : LblShape(labelString), m_length(length) {}


	void Line::getSpecs(istream& is)
	{
		//call getSpecs from base(LblShape)
		//read m_lenth from LblShape
		LblShape::getSpecs(is);
		is >> m_length;

		//ignore The rest of the characters to newLine
		is.ignore(1000, '\n');
	}

	void Line::draw(ostream& os) const
	{
		//condition: m_length > zero and the label() ! null
		if (m_length > 0 && label() != nullptr)
		{
			//display the Label String
			//display "=" to the value of the m_length, using library, <iomanip>
			cout << label() << endl;
			os << setw(m_length) << setfill('=') << '=';
		}
	}
}