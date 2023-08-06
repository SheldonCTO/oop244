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
#include <iomanip>
#include <iostream>
#include <cstring>
#include "cstring.h"
#include "Book.h"

namespace sdds
{
	
	//default ptr safe
	//default base class member to safe
	Book::Book(): Publication() {}
	//rule of 3
	Book::~Book()
	{
		delete[]m_author;
		m_author = nullptr;
	}
	//copy construct the Derive and base class
	//using self cstring tool
	Book::Book(const Book& newAuthor) : Publication(newAuthor)
	{
		if (m_author)
		{
			delete[]m_author;
			m_author = nullptr;
		}
		cs.cpyConstr(m_author, newAuthor.m_author);
	}

	//cpy assign

	Book& Book::operator=(const Book& newAuthor)
	{	//doing same action in base class
		Publication::operator=(newAuthor);
		if (m_author)
		{
			delete[]m_author;
			m_author = nullptr;
		}
		delete[]m_author;
		cs.cpyConstr(m_author, newAuthor.m_author);

		return *this;
	}
	//return char 'B' to base
	char Book::type()const
	{
		return 'B';
	}

	//invoke write to Publication 
	//condition: conIO ostream obj  valid
	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			//writes a single space
			//write the Author name exactly SDDS_AUTHOR_WIDTH characters 
			//set  a local tempString to storeand Author name
			//format: width  SDDS_AUTHOR_WIDTH with space     " Louise Hay      |"
			os << " ";
			char tempAuthor[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			//cpy cstring with limited size
			strncpy(tempAuthor, m_author, SDDS_AUTHOR_WIDTH);
			os << std::setw(SDDS_AUTHOR_WIDTH) << std::left  << std::setfill(' ')<< tempAuthor << " |";
		}
		else
		{
			//write '\t' and member author 
			os << '\t' << m_author<< "123";
		}
		return os;
	}
	//invoke read to Publication
	//create tempauthor's name <256
	std::istream& Book::read(std::istream& is)
	{
		Publication::read(is);
		char tempAuthor[256] = { 0 };
		//Free the memory held for the author's name
		delete[]m_author;
		m_author = nullptr;
		if (conIO(is))
		{
			//ignore one character and prompt "Author: "
			//read the is.author
			is.ignore();
			std::cout << "Author: ";
			is.get(tempAuthor, 256);
		}
		else
		{
			//ignore '\t and read is.author
			is.ignore(1000, '\t');
			is.get(tempAuthor, 256);
		}
		//if is valid dynamic copy
		//delete tempAuthor
		if (is)
		{
			cs.cpyConstr(m_author, tempAuthor);
		}
		return is;
	}
		//set the base class memberId
		//reset date to date();
	void Book::set(int member_id) 
	{
		//invoke to Publication class
		Publication::set(member_id);
		Publication::resetDate();
	}

	//author is valid && base class bool return true
	Book::operator bool() const
	{
		return (m_author) && (Publication::operator bool());
	}
}