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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
	//self function :check valid mark
	bool Mark::valid()
	{
		return (m_mark >= 0 && m_mark <= 100);
	}

	//self function :check valid number
	bool Mark::numValid(int number) 
	{
		return (number <= 100 && number >= 0);
	}

	//set empty member 
	Mark::Mark()
	{
		m_mark = 0;
	}

	//set number to member, if number is valid
	//if invalid  set member to -1
	Mark::Mark(int number)
	{
		if (numValid(number))
		{
			m_mark = number;
		}
		else
		{
			m_mark = -1;
		}
	}

	//return function :
	//set if member is valid, member = to number
	//if not set num = 0 
	Mark::operator int()
	{
		int num = 0;
		if (valid())
		{
			num = (int)m_mark;
		}
		else
		{
			num = 0;
		}
		return num;
	}

	//return function :
	//set return member value
	Mark::operator int() const
	{
		return m_mark;
	}

	//return overload function:
	//set if member is valid, member = both and return
	Mark &Mark::operator+=(int mark)
	{
		if (valid())
		{
			m_mark = m_mark + mark;
		}
		else
		{
			m_mark = 0;
		}
		return *this;
	}

	//return overload function:
	//set member =to number
	Mark &Mark::operator=(int num)
	{
		m_mark = num;
		return *this;
	}
	
	//double overload function
	//set if member is valid, and return the mark from 4 to 1
	Mark::operator double()
	{
		int mark = 0;
		if (valid())
		{
			if (m_mark <= 100 && m_mark >= 80)
			{
				mark = 4;
			}
			if (m_mark < 80 && m_mark >= 70)
			{
				mark = 3;
			}
			if (m_mark < 70 && m_mark >= 60)
			{
				mark = 2;
			}
			if (m_mark < 60 && m_mark >= 50)
			{
				mark = 1;
			}
		}
		else
		{
			mark = 0;
		}
		return mark;
	}

	//return overload function: 
	//if member is valid, return the grade
	Mark::operator char()
	{
		char grade = 'X';
		if (valid())
		{
			if (m_mark <= 100 && m_mark >= 80)
			{
				grade = 'A';
			}
			if (m_mark < 80 && m_mark >= 70)
			{
				grade = 'B';
			}
			if (m_mark < 70 && m_mark >= 60)
			{
				grade = 'C';
			}
			if (m_mark < 60 && m_mark >= 50)
			{
				grade = 'D';
			}
			if (m_mark < 50 && m_mark >= 0)
			{
				grade = 'F';
			}
		}
		else
		{
			grade = 'X';
		}
		return grade;
	}

	//helper function 
	double operator +=(int& value, Mark& newMark)
	{
		if (newMark.operator int() >= 0 && newMark.operator int() <= 100)
		{
			value = newMark.operator int() + value;
		}
		return value;
	}
}