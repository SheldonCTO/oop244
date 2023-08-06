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
#include "Publication.h"
#include "PublicationSelector.h"
#include "Book.h"

using namespace std;
namespace sdds
{
	class LibApp
	{   
        //256 characters to hold the publication data file name
        char m_fileName[256]{};
        
         //Publication pointers with SDDS_LIBRARY_CAPACITY, and call it PPA
        Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
        
        //int to hold the no of loaded in PPA
        //call NOLP
        int NOLP;
        
        //int to hole the last library refrence NO read from data file
        //used to assign new lib refer NO to new publication
        // when new public to add to the lib. add 1 and assigne new publication
        int LLRN;

        //return the address of a Pub object in the PPA 
        //PPA (libBef) matching the "libRef" argument.
        Publication* getPub(int libRef);
        
        
        //Publication menu
        //Add a Menu to the LibApp
        Menu m_publicType;
        
        //MS2
        bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
        bool confirm(const char* message);
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>

        //change to return the library reference number
        //add argement for user select
        //use an instance of PublicationSelector 
        //prompt "Select one of the following found matches:
        int search(int userSelect);

        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp(const char* filename);
        ~LibApp();
        void run();

	};
}

#endif // !_LIBAPP_H_
