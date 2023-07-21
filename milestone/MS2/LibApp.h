#pragma once
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
#ifndef _LIBAPP_H_
#define _LIBAPP_H_
#include <iostream>
#include "Menu.h"

using namespace std;
namespace sdds
{
	class LibApp
	{
		//default false and display msg
        bool m_changed=false;
		Menu m_mainMenu= "Seneca Libray Application";
		Menu m_exitMenu="Changes have been made to the data, what would you like to do?";
        bool confirm(const char* message);
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        void search();  // prints: "Searching for publication"<NEWLINE>

        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp();
        void run();

	};
}

#endif // !_LIBAPP_H_
