/***********************************************************************
// Intro. to Object Oriented Programming
// Final Project Milestone 1
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
#include <iomanip>
#include <ctime>
#include <limits>
#include <cstring>
#include "Date.h"
#include "Publication.h"
#include "Utils.h"
#include "Lib.h"

namespace sdds
{
	
	Publication::Publication()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		
	}

	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	// copy construct
	Publication::Publication(const Publication &publication)
	{
		// copy
		
		strcpy(m_shelfId, publication.m_shelfId);
		set(publication.m_membership);
		m_libRef = publication.m_libRef;
		m_date = publication.m_date;
		
		if (publication.m_title != nullptr)
		{
			delete[]m_title;
			ut.aloCpy(m_title, publication.m_title);
		}
	}
	Publication &Publication::operator=(const Publication &publication)
	{
		if (this != &publication)
		{ // set member value by sub-function
			set(publication.m_membership);
			m_libRef = publication.m_libRef;
			strcpy(m_shelfId, publication.m_shelfId);
			m_date = publication.m_date;

			delete[] m_title;

			if (publication.m_title != nullptr)
			{
				m_title = nullptr;
				m_title = new char[strlen(publication.m_title) + 1];
				delete[]m_title;
				ut.aloCpy(m_title, publication.m_title);
			}
			else
			{
				m_title = nullptr;
			}
		}
		return *this;
	}

	// membership attribute to either zero or a five - digit integer.
	void Publication::set(int member_id)
	{ // set member_id only accept 5dig or 0
		if (std::to_string(member_id).length() == 5 || member_id == 0)
		{
			m_membership = member_id;
		}
	}
	// sets the** libRef** attribute value
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	// set m_date to date()
	void Publication::resetDate()
	{
		m_date = Date();
	}

	char Publication::type() const
	{
		// Returns the character 'P' to identify this object
		return 'P';
	}

	bool Publication::onLoan() const
	{
		// return true if membership is !0
		return (m_membership != 0);
	}

	Date Publication::checkoutDate() const
	{
		// Returns the date attribute
		return m_date;
	}

	bool Publication::operator==(const char *title) const
	{
		bool appear = (strstr(m_title, title) != nullptr);
		return appear;
	}

	Publication::operator const char *() const
	{
		// Returns the title attribute
		return m_title;
	}

	int Publication::getRef() const
	{
		// Returns the libRef attirbute.
		return m_libRef;
	}

	bool Publication::conIO(std::ios &io) const
	{
		bool check = (&io == &std::cin || &io == &std::cout);
		return check;
	}

	std::ostream &Publication::write(std::ostream &os) const
	{
		// return os
		// if the os argument console IO conIO() pt
		//| P001 | The Toronto Star.............. | 34037 | 2023/11/17 |
		// check condition  if membership is 0,  cout N/A
		// as book.h, display title no more than TITLE_WIDTH
		// set a title string for display
		if (conIO(os))
		{
			char displayTitle[SDDS_TITLE_WIDTH + 1] = {0};
			strncpy(displayTitle, m_title, SDDS_TITLE_WIDTH);
			os << "| " << m_shelfId << " | ";
			os << std::setw(30) << std::left << std::setfill('.') << displayTitle << " | ";
			if (m_membership == 0)
			{
				os << " N/A ";
			}
			else
			{
				os << m_membership;
			}
			os << " | " << m_date << " |";
		}
		else
		{
			// print type() and member data  with \t
			os << type();
			os << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t';
			if (m_membership != 0)
			{
				os << m_membership;
			}
			else
			{
				os << "0";
			}
			os << '\t'; m_date.write(os);
		}
		return os;
	}

	// set attributes first
	std::istream &Publication::read(std::istream &is)
	{
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();

		// check is argument  console IO
		// if true, read
		// set a temp varibale to store and the and is and default safe
		char tempShelf[SDDS_SHELF_ID_LEN + 1]{};
		// change string[256] like book author
		char* tempTitle= new char[256]{};
		int tempMember = 0;
		int tempLib = 0;
		Date tempDate;
		if (conIO(is))
		{
			// check, the Shelf char in "is" with exactly up to its limit
			std::cout << "Shelf No: ";
			
			is >> tempShelf;
			if (strlen(tempShelf) != SDDS_SHELF_ID_LEN)
			{
				// manually set the fail state
				is.setstate(std::ios::failbit);
			}
			else
			{
				is.ignore(1000, '\n');
			}
			// read is and store to temp
			std::cout << "Title: ";
			is.getline(tempTitle, 256, '\n');
			std::cout << "Date: ";
			is >> tempDate;
		}
		// Otherwise reading begins with libRef attribute as no P
		else
		{
			// read "is" libref , member ,and date
			is >> tempLib;
			// skip the \t
			is.ignore();
			// read "is" after skip '\t'
			is.getline(tempShelf, SDDS_SHELF_ID_LEN + 1, '\t');
			is.getline(tempTitle, 256, '\t');
			is >> tempMember;
			is.ignore();
			is >> tempDate;
		}
		// if the date is in an invalid state
		// set the istr to a fail state manually
		if (!tempDate)
		{
			is.setstate(std::ios::failbit);
		}
		// if "is" is valid
		// copy all temp to member
		if (is)
		{
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelf);
			m_membership = tempMember;
			m_date = tempDate;
			m_libRef = tempLib;
		}
		delete[]tempTitle;
		return is;
	}

	Publication::operator bool() const
	{
		// return true, if base class variable is valid
		bool check = (m_title != nullptr && m_shelfId[0] != '\0');
		return check;
	}
}
