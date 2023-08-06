/***********************************************************************
// Intro. to Object Oriented Programming
// Final Project Milestone 4
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo

// Name: Ngai Man Szeto
// ID:180094211
// Section: ZAA
// Email:nszeto1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ngai Man Szeto
////////////////////////////////////////////////////////////////*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef _SDDS_STREAMABLE_H_
#define _SDDS_STREAMABLE_H_
#include <iostream>
#include "Lib.h"

namespace sdds
{
	class Streamable
	{
	public:
		//receive and reture ostream
		//interface =pure virtual =0
		//not capable of modifying  = const
		virtual std::ostream& write(std::ostream& os)const = 0;

		//receives and returns a reference of an istream
		//interface =pure virtual =0
		virtual std::istream& read(std::istream& is) = 0;

		//receive a reference of an ios =iostream
		//the object IO
		//not capable of modifying  = const
		//if IO conIO(IO)
		virtual bool conIO(std::ios& io)const = 0;

		//operator overload and return Bool
		//virtual function to publication
		//conversion to 'bool'
		virtual operator bool()const = 0;

		//Add an empty virtual destructor to this interface
		virtual ~Streamable() {};
	};

	//help function
	//operator overload
	// if valid insertion << constant object of type Streamable
	//otherwise ostream object
	std::ostream& operator<<(std::ostream& os, const Streamable& Stream);

	//operator overload
	//extraction from  istream  >> streamable
	std::istream& operator>>(std::istream& is, Streamable& Stream);


}
#endif // !_SDDS_STREAMABLE_H_
