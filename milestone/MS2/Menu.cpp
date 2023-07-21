/***********************************************************************
// Intro. to Object Oriented Programming
// Final Project Milestone 2
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
#include <ctime>
#include <string.h>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	//MenuItem construct
	//m_itemName in safe
	MenuItem::MenuItem()
	{
		m_itemName = nullptr;
	}

	//allocate member and pass the itemName to member
	MenuItem::MenuItem(const char *itemName)
	{
		if (itemName != nullptr)
		{
			m_itemName = new char[strlen(itemName) + 1];
			strcpy(m_itemName, itemName);
		}
		else
		{
			m_itemName = nullptr;
		}
	}

	//destruct
	//delete the member pointer
	MenuItem::~MenuItem()
	{
		delete[] m_itemName;
		m_itemName = nullptr;
	}

	//overload operator return true, if m_itemName is valid
	MenuItem::operator bool() const
	{
		return (m_itemName != nullptr);
	}

	//overload operator return, member value
	MenuItem::operator const char *() const
	{
		return m_itemName;
	}

	//overload operator return	member to display if member is valid
	void MenuItem::display(std::ostream &os) const
	{
		if (m_itemName != nullptr)
		{
			os << m_itemName;
		}
	}

	//construct
	//set all member to safe 
	Menu::Menu()
	{
		m_title.m_itemName = nullptr;
		m_noOfItems = 0;
	}

	//allocate member and pass the title to member
	Menu::Menu(const char *title)
	{
		if (title != nullptr)
		{
			m_title.m_itemName = new char[strlen(title) + 1];
			strcpy(m_title.m_itemName, title);
		}
		// if title is invalid. deallocate the pointer, and DELETE the ARRAY
		else
		{
			delete[] m_title;
			m_title.m_itemName = nullptr;
			unsigned int i = 0;
			while (i < m_noOfItems)
			{
				delete m_item[i];
				m_item[i] = nullptr;
			}
			m_noOfItems = 0;
		}
	}
	
	//display the title, if title is valid
	void Menu::displayTitle(std::ostream &os) const
	{
		if (m_title != nullptr)
		{
			os << m_title.m_itemName;
		}
	}
	
	//if m_title is valid, run the title function and display the Menu Items

	void Menu::display() const
	{
		if (m_title)
		{
			displayTitle();
			cout << "" << endl;
		}
		unsigned int i = 0;
		while (i < m_noOfItems)
		{
			cout << " " << i + 1 << "- " << m_item[i]->m_itemName << endl;
			i++;
		}
		cout << " 0- Exit" << endl;
		cout << "> ";
	}

	//run the title function and return the member to current os
	std::ostream &Menu::display(ostream &os) const
	{
		displayTitle();
		return os;
	}

	//destruct
	//delete the member pointer
	Menu::~Menu()
	{
		delete[]m_title;
		m_title.m_itemName = nullptr;
		unsigned int i = 0;
		while (i < m_noOfItems)
		{
			delete m_item[i];
			m_item[i]=nullptr;
			i++;
		}
	}

	//run and input function
	//ask user to input the valid number
	unsigned Menu::run() const
	{

		bool valid = true;
		unsigned select;
		display();
		do
		{
			cin >> select;

			//error input msg, if input invalid, loop until input is valid 
			if (cin.fail() || select > (unsigned)m_noOfItems)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
				valid = false;
			}
			else
			{
				valid = true;
			}
		} while (!valid);
		return select;
	}

	//overload operator to run the input function
	unsigned Menu::operator~()
	{

		return run();
	}

	//overload operator. return the member value
	Menu::operator unsigned int() const
	{
		return m_noOfItems;
	}

	//overload operator  return true, if member is valid
	Menu::operator bool() const
	{
		return m_title != nullptr;
	}

//overload operator. return the member value
	Menu::operator int() const
	{
		return m_noOfItems;
	}

//overload operator. return the pointer member value
	const char *Menu::operator[](int i) const
	{
		return *m_item[i % m_noOfItems];
	}

	
	//overland , if current value is valid and member is smaller than the MAX
	//allocate the member point
	//set the no of item + 1
	Menu &Menu::operator<<(const char *menuitemConent)
	{
		if (menuitemConent != nullptr && m_noOfItems < MAX_MENU_ITEMS)
		{
			m_item[m_noOfItems] = new MenuItem(menuitemConent);
			m_noOfItems++;
		}
		return *this;
	}

	//helper function. 
	std::ostream &operator<<(std::ostream &os, const Menu &copy)
	{
		copy.display(os);
		return os;
	}
}