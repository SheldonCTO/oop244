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
#pragma once
#ifndef _LINE_H_
#define _LINE_H_
#include <iostream>
#include "LblShape.h"

using namespace std;
namespace sdds
{
	class Line : public LblShape
	{
		//default member variable =0
		int m_length =0;
	public:
		
		//default construct no arg and member m_leught = 0
		Line() :LblShape(), m_length() {};
		Line(const char* labelString, int length);
		//default destruct had no destructor implemented
		~Line() {};

		//read Line of rectangle from istream
		void getSpecs(istream& is);
		//draw data of Line ostream onto ostream 
		//const variable
		void draw(ostream& os)const;
	};

}

#endif // !_LINE_H_

