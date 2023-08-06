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
#ifndef _SDDS_BOOK_H_
#define _SDDS_BOOK_H_
#include "Publication.h"

namespace sdds
{
	class Book : public Publication
	{
		char* m_author{};
	public:
		//constructe default empty state
		Book();
		//rule of 3
		~Book();
		Book(const Book& newAuthor);
		Book& operator=(const Book& newAuthor);

		// following virtual methods from the base publication and streamable
		char type() const;

		// write of its Base class
		// condtion: incoming argument conIO 
		//returns the incoming ostream
		std::ostream& write(std::ostream& os) const;

		//Read the author name in local variables 
		//create tempauthor's name <256
		//condtion: incoming istream object 
		//return is
		std::istream& read(std::istream& is);

		//virtual method
		//set the base class memberId
		//reset date to date();
		virtual void set(int member_id);

		//condition: author is valid && base class bool return true
		operator bool() const;


	};
}

#endif // !_SDDS_BOOK_H_
