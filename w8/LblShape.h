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
#ifndef _LBLSHAPE_H_
#define _LBLSAHPE_H_
#include <iostream>
#include "Shape.h"


using namespace std;
namespace sdds
{
	class LblShape : public Shape 
	{
		char* m_label = nullptr;
	protected:
		//query called label 
		//return unmodifiable value of m_label
		const char* label()const;
	public:
		//the m_label is already initialized to null
		LblShape() : m_label() {};
		LblShape(const char* label);
		//Deletes the memory pointed
		~LblShape();
		//delete copy construct and assignment
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;

		//receive a Cstring (a label) from istream up to the ',' character
		//ignore "," 
		void getSpecs(std::istream& is);
	};


}

#endif // !_LBLSHAPE_H_