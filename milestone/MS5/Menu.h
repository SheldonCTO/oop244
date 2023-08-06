/***********************************************************************
// Intro. to Object Oriented Programming
// Final Project Milestone 5
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
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

using namespace std;
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem
	{
		char *m_itemName{nullptr};
		MenuItem();
		MenuItem(const char *itemName);
		MenuItem(const MenuItem &copyConstr) = delete;
		MenuItem &operator=(const MenuItem &copyAssign) = delete;
		~MenuItem();
		operator bool() const;
		operator const char *() const;
		void display(std::ostream &os) const;
		friend class Menu;
	};
	class Menu
	{
		MenuItem m_title = {0};
		MenuItem *m_item[MAX_MENU_ITEMS]{nullptr};
		unsigned int m_noOfItems = 0;
	public:

		Menu();
		Menu(const char *title);
		Menu(const Menu &copy) = delete;
		Menu &operator=(const MenuItem &copy) = delete;
		void displayTitle(std::ostream &os =std::cout) const;
		void display() const;
		std::ostream& display(ostream& os) const;

		~Menu();
		unsigned run()const;
		unsigned operator~();
		Menu& operator<<(const char *menuitemConent);
		operator unsigned int() const;
		operator int() const;
		operator bool() const;
		const char *operator[](int i) const;
	};
	std::ostream &operator<<(std::ostream &os, const Menu &copy);
}
#endif