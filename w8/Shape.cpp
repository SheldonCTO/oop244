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
#include "Shape.h"

using namespace std;
namespace sdds
{
	ostream& operator<<(ostream &os, const Shape &newShape)
	{
		newShape.draw(os);
		return os;
	}

	istream &operator>>(istream &is, Shape &newShape)
	{
		newShape.getSpecs(is);
		return is;
	}
}