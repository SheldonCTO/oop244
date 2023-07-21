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
#include "LibApp.h"

using namespace std;
namespace sdds
{
	bool LibApp::confirm(const char* message)
	{
		Menu confirm(message);//Instantiate a Menu with the message argument.
		confirm << "Yes"; //add  "Yes" the Menu confirm
		return confirm.run();  //return true if the run method of Menu returns 1
	}

	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}

	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}

	//Main Menu select 4
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}
	//Main Menu select 1
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		if(confirm("Add this publication to library"))
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}
	//Main Menu select 2
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library ?"))
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}
	//Main Menu select 3
	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?"))
		{
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}

	LibApp::LibApp()
	{
		//select 1, 2, 3, 4 in mainMenu
		m_mainMenu << "Add New Publication" << "Remove Publication";
		m_mainMenu << "Checkout publication from library" << "Return publication to library";
		//select 1,2 in exitMenu
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		load();
	}

	void LibApp::run()
	{	// flag is false
		bool finish = false;
		
			do 
			{
				int select = m_mainMenu.run();
				if (select == 1)
				{
					newPublication();
				}
				else if (select == 2)
				{
					removePublication();
				}
				else if (select == 3)
				{
					checkOutPub();
				}
				else if (select == 4)
				{
					returnPub();
				}
				else// select == 0
				{
					if (m_changed)
					{
						int quit = m_exitMenu.run();
						if (quit == 2)
						{	
							//back to loop;
						}
						else //quit == 1 || 0
						{
							if (quit == 1)
							{	//flag exit
								save();
								finish = true;

							}
							else
							{
								if (confirm("This will discard all the changes are you sure?"))
								{	//flag exit
									finish = true;
								}
							}
						}
					}
					else
					{	//flag exit without change
						finish = true;
					}
				}
				cout << endl;
			} while (!finish);
		
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}