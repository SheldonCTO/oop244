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
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include <iostream>
#include "LblShape.h"

using namespace std;
namespace sdds
{
	class Rectangle : public LblShape
	{
		//default member variables =0
		int m_width = 0;
		int m_height= 0 ;
	public:
		//default construct no arg and  set 2 member variables = 0
		Rectangle() : m_width(), m_height() {};
		//2 para: number of characters, int width and height  
		//1 para: Cstring for the label
		Rectangle( const char* labelString,int width, int height);
		//default destruct had no destructor implemented
		~Rectangle() {};

		//read data of rectangle from istream
		void getSpecs(istream& is);

		//draw data of restangle ostream onto ostream 
		//const variable
		void draw(ostream& os) const;
	};
}

#endif // !_RECTANGLE_H_
