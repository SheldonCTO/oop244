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
#include <string.h>
#include "Rectangle.h"


using namespace std;
namespace sdds
{   
	//set member variables value receive arg
	//pass labelString to construct of Base class(LblShape)
	Rectangle::Rectangle(const char* labelString,int width, int height): LblShape(labelString),m_width(width), m_height(height)
	{
		//check m_heigth is <3 or m_width < (labelString +2)
		int length = strlen(labelString);
		if (m_height < 3 || m_width < length + 2)
		{
			//set the Rectangle to an empty
			m_height = 0;
			m_width = 0;
		}

	}

	void Rectangle::getSpecs(istream& is)
	{
		//override from base class 
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(ostream& os) const
	{
		//check 2 member varibles are valid
		if (m_width != 0 && m_height != 0)
		{
			//using iomanip
			os << '+';
			os << setw(m_width - 2) << setfill('-') << '-';
			os << '+' << endl;
			os << '|' << label();
			os << setw(m_width - strlen(label()) - 2) << setfill(' ') << ' ';
			os << '|' << endl;

			//iomanip  is not work for display line 3-4
			for (int i = 0; i < m_height - 3; i++)
			{
				os << "|";
				for (int j = 0; j < m_width - 2; j++)
				{
					os << " ";
				}
				os << "|" << endl; 
			}
			os << '+';
			os << setw(m_width - 2) << setfill('-') << '-';
			os << '+';
			

		}
	}
}