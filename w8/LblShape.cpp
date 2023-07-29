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

#include "LblShape.h"

using namespace std;
namespace sdds
{
	const char* LblShape::label()const
	{
		return m_label;
	}

	LblShape::LblShape(const char* label)
	{
		if (label != nullptr)
		{
			delete[]m_label;
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	LblShape::~LblShape()
	{
		delete[]m_label;
		m_label = nullptr;
	}

	//receive a Cstring (a label) from istream up to the ',' 
	void LblShape::getSpecs(std::istream& is)
	{
		//using string labelszie to count the  istream m_label size
		//getline to count the label size until ','
		
		std::string labelSize;
		getline(is, labelSize,',');
		delete[] m_label;
		//allocate memory
		//copy  label string to m_label, 
		m_label = new char[labelSize.length() + 1];
		// I used chat GPT for labelSize.c_str()
		strcpy(m_label, labelSize.c_str());
		
	}

}
