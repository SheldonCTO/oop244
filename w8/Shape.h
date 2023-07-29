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
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <iostream>

using namespace std;
namespace sdds
{
	class Shape
	{
	public:
		//class Shape has no construct
		//destructor, default removed memory when deleted
		//{} remove all Shape  pointer memory
		virtual ~Shape() {};
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
	};
	ostream& operator<<(ostream& os, const Shape& newShape);
	istream& operator>>(istream& is, Shape& newShape);
	
}
#endif // !_SHAPE_H_
