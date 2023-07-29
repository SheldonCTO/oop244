/***********************************************************************
// Intro. to Object Oriented Programming
// Final Project Milestone 3
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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Streamable.h"

namespace sdds
{
	
	std::ostream& operator<<(std::ostream& os, const Streamable& Stream)
	{
		//if insertion valid 
		// overload the ostream os by write() and return new os
		if (Stream)
		{
			Stream.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& Stream)
	{
		//return overload the object and read the istream is
		return (Stream.read(is));
	}
}