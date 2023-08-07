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
#include <fstream>
#include <limits>
#include <string>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
#include "LibApp.h"

namespace sdds
{

	// Menu m_mainMenu = "Seneca Libray Application";
	// Menu m_exitMenu = "Changes have been made to the data, what would you like to do?";
	bool LibApp::confirm(const char *message)
	{
		Menu confirm(message); // Instantiate a Menu with the message argument.
		confirm << "Yes";	   // add  "Yes" the Menu confirm
		return confirm.run();  // return true if the run method of Menu returns 1
	}

	// print msg and ifstream read the file and dyn instance by PPA ARRAY
	void LibApp::load()
	{
		std::cout << "Loading Data" << endl;
		std::ifstream RFile(m_fileName);
		// reading a single character for the type of publication
		// set the temp char to read the store
		char firstChar = '\0';
		// check the Ofile until the end and get(the char)
		for (int i = 0; RFile; i++)
		{
			RFile >> firstChar;
			// igonre all
			RFile.ignore();
			// if firstchar = P
			// dyn instance by PPA ARRAY
			if (RFile)
			{
				if (firstChar == 'P')
				{
					PPA[i] = new Publication;
				}

				// if firstchar = P
				// dyn instance by PPA ARRAY
				else if (firstChar == 'B')
				{
					PPA[i] = new Book;
				}
				// check PPA[i] processed?
				if (PPA[i])
				{
					// extract PPA from file and NOLP ++
					RFile >> *PPA[i];
					// add 1 per fix
					NOLP++;
					// set the LLRN to the reference number of PPA
				}
			}
		}
		LLRN = PPA[NOLP - 1]->getRef();
		firstChar = '\0';
	}

	void LibApp::save()
	{
		std::cout << "Saving Data" << endl
				  << endl;
		std::ofstream Ofile(m_fileName);
		// Go through the elements of PPA up to the N0LP
		for (int i = 0; i < NOLP; i++)
		{
			// Insert all PPA into Ofile but not ZERO
			// as Library Reference Number. (return value of getRef() method)
			if (PPA[i]->getRef() != 0)
			{
				Ofile << *PPA[i] << endl;
			}
		}
		Ofile.close();
	}

	// user select option 1= Search All, 2= Search loan by library members, 3 search Available Items for loan
	int LibApp::search(int userSelect) const
	{
		// page size for the selector menu should be 15
		PublicationSelector Pubselect("Select one of the following found matches:", 15);
		// get the type to search (selection call Menu m_publictype)
		// run and input function using menu::run()
		// set the local title[256] to store the title
		char title[256]{};

		char type{};
		// set temp for libRefNo default 0
		int tempLibRef{};

		// any useSelect

		// Choose the type of publication :
		// 1 - Book,  2 - Publication    0 - Exit
		// set pubSel for 1,2,3
		std::cin.ignore();
		int pubSel = m_publicType.run();
		if (pubSel > 0) // select 1 or 2
		{
			if (pubSel == 1)
			{
				type = 'B';
				std::cin.ignore();
				std::cout << "Publication Title: ";
				cin.getline(title, 256, '\n');
			}
			else if (pubSel == 2)
			{
				type = 'P';
				std::cin.ignore();
				std::cout << "Publication Title: ";
				cin.getline(title, 256, '\n');
			}
		}
		else //   0 - Exit
		{
			std::cout << "Aborted!" << endl
					  << endl;

			//<< "Aborted!\n"
		} // get the title to search the PPA for

		if (userSelect == 1)
		{
			int i = 0;
			while (i < NOLP)
			{
				// PPA is not deleted && type matches the selection &&contains the title(book) the user entered
				if (PPA[i]->getRef() && std::strstr((const char *)*PPA[i], title) && PPA[i]->type() == type)
				{
					// insert PPA into the object
					Pubselect << *PPA[i];
				}
				i++;
			}
		}
		// Search on Loan
		else if (userSelect == 2)
		{
			int i = 0;
			while (i < NOLP)
			{
				// add one more condition!!check onLoan
				if (PPA[i]->getRef() && std::strstr((const char *)*PPA[i], title) && PPA[i]->onLoan() &&
					PPA[i]->type() == type)
				{
					// insert PPA into the object
					Pubselect << *PPA[i];
				}
				i++;
			}
		}
		// Search available item ( PublicSelect not onLoan)
		else if (userSelect == 3)
		{
			for (int i = 0; i < NOLP; i++)
			{
				// check !publicSelect onLoan
				if (PPA[i]->getRef() && std::strstr((const char *)*PPA[i], title) && !PPA[i]->onLoan() &&
					PPA[i]->type() == type)
				{
					// insert PPA into the object
					Pubselect << *PPA[i];
				}
			}
		}
		if (Pubselect)
		{
			Pubselect.sort();
			tempLibRef = Pubselect.run();
			if (tempLibRef == 0)
			{
				std::cout << "Aborted!" << endl
						  << endl;
			}
		}
		// Search ALL in book and Publication

		else
		{
			std::cout << "No matches found!" << endl
					  << endl;
		}
		return tempLibRef;
	}
	// loaded in PPA (NOLP)
	// if PPA obj NO  == libRef
	// return PPA[i]
	Publication *LibApp::getPub(int libRef) const
	{
		bool find = false;
		int i = 0;
		for (int i = 0; i < NOLP && !find; i++)
		{
			if (PPA[i]->getRef() == libRef)
			{
				find = true;
			}
		}
		
		return PPA[i];
	}

	// Main Menu select 4
	void LibApp::returnPub()
	{

		// set int tempSelect for search
		//  onloan = search(2)
		// set date obj for count penalty
		// set int for late
		Publication date;
		int late = 0;
		std::cout << "Return publication to the library" << endl;
		int j = 0;
		int tempSelect = search(2);
		if (tempSelect > 0)
		{
			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->getRef() == tempSelect)
				{

					j = i;
				}
			}
		}
		if (j > 0)
		{
			std::cout << *PPA[j] << endl;
			if (confirm("Return Publication?"))
			{
				// set  obj for checkout
				// obj - selectPublication.record checkoutday()
				late = date.checkoutDate() - PPA[j]->checkoutDate();
				if (late > SDDS_MAX_LOAN_DAYS)
				{
					// penalty fee = (late day - SDDS_MAX_LOAN_DAYS) 0.5
					double lateFee = (late - SDDS_MAX_LOAN_DAYS) * 0.5;
					std::cout.setf(ios::fixed);
					std::cout.precision(2);
					std::cout << "Please pay $" << lateFee << " penalty for being " << late - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
				}
				// set the ID of the Select publication to 0 (zero)
				PPA[j]->set(0);
				std::cout << "Publication returned" << endl
						  << endl;
				m_changed = true;
			}
		}
	}
	// Main Menu select 1
	// Updata new method
	void LibApp::newPublication()
	{
		// NOLP = 5000,exit
		// set publication temp pointer
		// must delete,after using
		Publication *tempPublic = nullptr;
		if (NOLP == SDDS_LIBRARY_CAPACITY)
		{
			std::cout << "Library is at its maximum capacity!" << endl
					  << endl;
			delete tempPublic;
		}
		else
		{
			std::cout << "Adding new publication to the library" << endl;
			// get the publictype in run Meun
			// set int temp for publicType
			int tSelect = m_publicType.run();
			if (tSelect != 0)
			{
				// set PPA  dynamic  to "Publication" or "Book"
				// 1=book, 2 =publication
				tempPublic = tSelect == 1 ? new Book : new Publication;
				// read the instantiated object >PPA
				std::cin.ignore(1000, '\n');
				std::cin >> *tempPublic;
				// if the cin fails>exit
				if (cin.fail() == true)
				{
					// clear the cin
					std::cin.ignore(1000, '\n');
					std::cout << "Aborted!" << endl
							  << endl;
					delete tempPublic;
				}
				else
				{
					// confirm that the user wants to add the publication
					if (confirm("Add this publication to the library?"))
					{
						if ((*tempPublic))
						{
							// LLRN +1 and set it to Ref LLRN
							// set tempPtr to  PPA and NOLP +1

							LLRN++;

							PPA[NOLP] = tempPublic;

							PPA[NOLP]->setRef(LLRN);
							NOLP++;
							m_changed = true;
							std::cout << "Publication added" << endl
									  << endl;
						}
						else
						{
							std::cout << "Failed to add publication!" << endl;
							delete tempPublic;
						}
					}
					else
					{
						delete tempPublic;
						std::cout << "Aborted!" << endl
								  << endl;
					}
				}
			}
			else
			{
				std::cin.ignore(1000, '\n');
				delete tempPublic;
				std::cout << "Aborted!" << endl
						  << endl;
			}
		}
	}
	// Main Menu select 2
	void LibApp::removePublication()
	{
		std::cout << "Removing publication from the library" << endl;
		// set int temp for search
		// 1:all 2:loan 3: available
		// apply 1 into search()
		// search return >0 is valid && confirms to remove
		int tempSelect = search(1);
		int j = 0;
		if (tempSelect > 0)
		{
			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->getRef() == tempSelect)
				{
					j = i;
				}
			}
			if (j >= 0)
			{
				std::cout << *PPA[j] << endl;
				if (confirm("Remove this publication from the library?"))
				{
					// getRef() const
					// for retrun LibRef
					// set ref of tempSelect to 0
					PPA[j]->setRef(0);
					m_changed = true;
					std::cout << "Publication removed" << endl
							  << endl;
				}
			}
		}
	}
	// Main Menu select 3
	void LibApp::checkOutPub()
	{
		// set int temp for search and int tempID for memberID
		// 1:all 2:loan 3: available
		// apply 3 into search()
		int tempID = 0;
		std::cout << "Checkout publication from the library" << endl;
		;
		int tempSelect = search(3);
		int j = 0;
		if (tempSelect > 0)
		{
			for (int i = 0; i < NOLP; i++)
			{
				if (PPA[i]->getRef() == tempSelect)
				{
					j = i;
				}
			}
		}
		if (j >= 0)
		{
			std::cout << *PPA[j] << endl;
			// cout msg and
			// set loop cin tempID must  5 dig no
			// using <limit> library
			if (confirm("Check out publication?"))
			{

				std::cout << "Enter Membership number: ";
				do
				{
					std::cin >> tempID;
					if (std::to_string(tempID).length() == 5)
					{
						// use set(ID) for return memberID
						// set tempID of  tempSelect value
						PPA[j]->set(tempID);
						m_changed = true;
						std::cout << "Publication checked out" << endl
								  << endl;
					}
					else
					{
						std::cout << "Invalid membership number, try again: ";
					}
				} while (std::to_string(tempID).length() != 5);
			}
		}
	}
	// construct and initialized titles
	LibApp::LibApp(const char *filename) : NOLP(), LLRN(), m_publicType("Choose the type of publication:"), m_changed(false),
										   m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")

	{

		// default
		// select 1, 2, 3, 4 in mainMenu
		m_mainMenu << "Add New Publication"
				   << "Remove Publication";
		m_mainMenu << "Checkout publication from library"
				   << "Return publication to library";
		// select 1,2 in exitMenu
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_publicType << "Book"
					 << "Publication";
		ut.strncpy(m_fileName, filename, 256);
		load();
	}

	LibApp::~LibApp()
	{
		for (int i = 0; i < NOLP; i++)
		{
			delete PPA[i];
		}
	}
	void LibApp::run()
	{ // flag is false
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
			else // select == 0
			{
				if (m_changed)
				{
					int quit = m_exitMenu.run();
					if (quit == 2)
					{
						// back to loop;
					}
					else // quit == 1 || 0
					{
						if (quit == 1)
						{ // flag exit
							save();
							finish = true;
						}
						else
						{
							if (confirm("This will discard all the changes are you sure?"))
							{ // flag exit
								finish = true;
							}
						}
					}
				}
				else
				{ // flag exit without change
					finish = true;
				}
			}
		} while (!finish);

		std::cout << "-------------------------------------------" << endl;
		std::cout << "Thanks for using Seneca Library Application" << endl;
	}
}
