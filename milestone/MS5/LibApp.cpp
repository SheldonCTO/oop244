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
#include "Menu.h"
#include "cstring.h"
#include "LibApp.h"


namespace sdds
{


	// Menu m_mainMenu = "Seneca Libray Application";
	// Menu m_exitMenu = "Changes have been made to the data, what would you like to do?";
	bool LibApp::confirm(const char* message)
	{
		Menu confirm(message);//Instantiate a Menu with the message argument.
		confirm << "Yes"; //add  "Yes" the Menu confirm
		return confirm.run();  //return true if the run method of Menu returns 1
	}

	//print msg and ifstream read the file and dyn instance by PPA ARRAY
	void LibApp::load()
	{
		std::cout << "Loading Data" << endl;
		std::ifstream RFile(m_fileName);
		//reading a single character for the type of publication
		//set the temp char to read the store
		char firstChar = '\0';


		//check the Ofile until the end and get(the char)
		for (int i = 0; RFile; i++)
		{
			RFile >> firstChar;
			// igonre all 
			RFile.ignore();
			//if firstchar = P 
			//dyn instance by PPA ARRAY
			if (firstChar == 'P')
			{
				PPA[i] = new Publication;
			}

			//if firstchar = P 
			//dyn instance by PPA ARRAY
			else if (firstChar == 'B')
			{
				PPA[i] = new Book;
			}
			//check PPA[i] processed?
			if (PPA[i])
			{
				//extract PPA from file and NOLP ++
				RFile >> *PPA[i];
				
				//add 1 per fix
				NOLP++;
				//set the LLRN to the reference number of PPA
			
			}
		}
		LLRN = PPA[NOLP-2]->getRef();
	}

	void LibApp::save()
	{
		std::cout << "Saving Data" << endl;
		std::ofstream Ofile(m_fileName, ofstream::trunc);
		//Go through the elements of PPA up to the N0LP
		for (int i = 0; i < NOLP; i++)
		{
			// Insert all PPA into Ofile but not ZERO
			//as Library Reference Number. (return value of getRef() method)
			if (PPA[i]->getRef()!=0)
			{
				Ofile << *PPA[i] << endl;
			}
		}
		Ofile.close();
	}
	//user select option 1= Search All, 2= Search loan by library members, 3 search Available Items for loan
	int LibApp::search(int userSelect)
	{
		//page size for the selector menu should be 15
		PublicationSelector Pubselect("Select one of the following found matches:", 15);
		//get the type to search (selection call Menu m_publictype)
		//run and input function using menu::run()
		//set the local title[256] to store the title
		char title[256]{};
		bool quit = false;
		//set temp for libRefNo default 0
		int tempLibRef{};

		//any useSelect 
		if (userSelect)
		{
			//Choose the type of publication :
			//1 - Book,  2 - Publication    0 - Exit

			if (m_publicType.run() != 0)//select 1 or 2
			{
				//get the title to search the PPA for
				std::cout << "Publication Title: ";
				cin.getline(title, 256, '\n');
			}
			else //   0 - Exit
			{
				std::cout << "Aborted!" << endl;
				//<< "Aborted!\n"
			}
			if (userSelect == 1 && m_publicType.run() != 0)
			{

				{
					int i = 0;
					while (i < NOLP)
					{
						// PPA is not deleted && type matches the selection &&contains the title(book) the user entered
						if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'B' ||
							PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'P')
						{
							//insert PPA into the object
							//sort"psfunction " the result and get the user's selection
							Pubselect << *PPA[i];
							Pubselect.sort();
							tempLibRef = Pubselect.run();
							//templibRef =return
						}
						else
						{
							quit = true;
						}
						i++;
					}
				}
			}
			//Search on Loan
			else if (userSelect == 2 && m_publicType.run() != 0)
			{
				int i = 0;
				while (i < NOLP)
				{
					//add one more condition!!check onLoan
					if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'B' && PPA[i]->onLoan() ||
						PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'P' && PPA[i]->onLoan())
					{
						//insert PPA into the object
						//sort"psfunction " the result and get the user's selection
						Pubselect << *PPA[i];
						Pubselect.sort();
						tempLibRef = Pubselect.run();
						//templibRef =return
					}
					else// not Match
					{
						quit = true;
					}
					i++;
				}
			}
			//Search available item ( PublicSelect not onLoan)
			else if (userSelect == 3 && m_publicType.run() != 0)
			{
				int i = 0;
				while (i < NOLP)
				{
					//check !publicSelect onLoan
					if (PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'B' && !PPA[i]->onLoan() ||
						PPA[i]->getRef() && *PPA[i] == title && PPA[i]->type() == 'P' && !PPA[i]->onLoan())
					{
						//insert PPA into the object
						//sort"psfunction " the result and get the user's selection
						Pubselect << *PPA[i];
						Pubselect.sort();
						tempLibRef = Pubselect.run();
						//templibRef = quit
					}
					else// not Match
					{
						quit = true;
					}
					i++;
				}
			}
		}
		//Search ALL in book and Publication

		if (tempLibRef == 0)
		{
			std::cout << "Aborted!" << endl;
		}
		if (quit)
		{
			std::cout << "No matches found!" << endl;
		}
		return tempLibRef;
	}
	// loaded in PPA (NOLP)
	//if PPA obj NO  == libRef 
	//return PPA[i]
	Publication* LibApp::getPub(int libRef)
	{
		bool find = false;
		int i = 0;
		while (i < NOLP || !find)
		{
			if (PPA[i]->getRef() == libRef)
			{
				find = true;
			}
			i++;
		}
		return PPA[i];
	}

	//Main Menu select 4
	void LibApp::returnPub()
	{

		//set int tempSelect for search
		// onloan = search(2)
		//set date obj for count penalty
		//set int for late
		Publication date;
		int late = 0;
		std::cout << "Return publication to the library" << endl;
		int tempSelect = search(2);
		if (tempSelect > 0 && confirm("Return publication"))
		{
			//set  obj for checkout
			//obj - selectPublication.record checkoutday()
			late = date.checkoutDate() - getPub(tempSelect)->checkoutDate();
			if (late > SDDS_MAX_LOAN_DAYS)
			{
				//penalty fee = (late day - SDDS_MAX_LOAN_DAYS) 0.5
				double lateFee = (late - SDDS_MAX_LOAN_DAYS) * 0.5;
				std::cout.setf(ios::fixed);
				std::cout.precision(2);
				std::cout << "Please pay $" << lateFee << " penalty for being " << late - SDDS_MAX_LOAN_DAYS << "days late!" << endl;


			}
			//set the ID of the Select publication to 0 (zero)
			getPub(tempSelect)->set(0);
			std::cout << "Publication returned" << endl;
			m_changed = true;
		}
	}
	//Main Menu select 1
	//Updata new method
	void LibApp::newPublication()
	{
		//NOLP = 5000,exit
		//set publication temp pointer
		//must delete,after using
		Publication* tempPublic = nullptr;
		if (NOLP == SDDS_LIBRARY_CAPACITY)
		{
			std::cout << "Library is at its maximum capacity!" << endl;
			delete tempPublic;
		}
		else
		{
			std::cout << "Adding new publication to library" << endl;
			//get the publictype in run Meun
			//set int temp for publicType
			int tSelect = m_publicType.run();
			if (tSelect != 0)
			{
				//set PPA  dynamic  to "Publication" or "Book"
				//1=book, 2 =publication
				tSelect == 1 ? tempPublic = new Book : tempPublic = new Publication;
				//read the instantiated object >PPA
				std::cin.ignore(1000, '\n');
				std::cin >> *tempPublic;
				//if the cin fails>exit
				if (cin.fail() == true)
				{
					//clear the cin
					std::cin.ignore(1000, '\n');
					std::cout << "Aborted!" << endl;
					delete tempPublic;
				}
				else
				{
					// confirm that the user wants to add the publication
					if (confirm("Add this publication to library?"))
					{
						if ((*tempPublic))
						{
							//LLRN +1 and set it to Ref LLRN 
							//set tempPtr to  PPA and NOLP +1
							
							LLRN++;
							
							PPA[NOLP] = tempPublic;
							
							PPA[NOLP]->setRef(LLRN);
							NOLP++;
							m_changed = true;
							std::cout << "Publication added" << endl;
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
						std::cout << "Aborted!" << endl;
					}
				}
			}
			else
			{
				std::cin.ignore(1000, '\n');
				delete tempPublic;
				std::cout << "Aborted!" << endl;
			}
		}
	}
	//Main Menu select 2
	void LibApp::removePublication()
	{
		std::cout << "Removing publication from library" << endl;
		//set int temp for search 
		//1:all 2:loan 3: available 
		//apply 1 into search() 
		//search return >0 is valid && confirms to remove 
		int tempSelect = search(1);
		if (tempSelect > 0 && confirm("Remove this publication from the library?"))
		{
			//getRef() const
			//for retrun LibRef
			//set ref of tempSelect to 0
			getPub(tempSelect)->setRef(0);
			m_changed = true;
			std::cout << "Publication removed" << endl;
		}
	}
	//Main Menu select 3
	void LibApp::checkOutPub()
	{
		//set int temp for search and int tempID for memberID
		//1:all 2:loan 3: available 
		//apply 3 into search() 
		int tempID = 0;
		int tempSelect = search(3);
		if (tempSelect > 0 && confirm("Check out publication?"))
		{
			//cout msg and 
			//set loop cin tempID must  5 dig no 
			//using <limit> library
			do
			{
				std::cout << "Enter Membership number: " << endl;
				std::cin >> tempID;
				if (std::to_string(tempID).length() == 5)
				{
					//use set(ID) for return memberID
					//set tempID of  tempSelect value
					getPub(tempSelect)->set(tempID);
					m_changed = true;
					std::cout << "Publication checked out" << endl;
				}
				else
				{
					std::cout << "Invalid membership number, try again: " << endl;
				}
			} while (std::to_string(tempID).length() != 5);
		}
	}
	//construct and initialized titles 
	LibApp::LibApp(const char* filename) : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_publicType("Choose the type of publication:"), NOLP(), LLRN()
	{

		//default
		//select 1, 2, 3, 4 in mainMenu
		m_mainMenu << "Add New Publication" << "Remove Publication";
		m_mainMenu << "Checkout publication from library" << "Return publication to library";
		//select 1,2 in exitMenu
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_publicType << "Book" << "Publication";
		cs.strnCpy(m_fileName, filename, 256);
		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < NOLP; i++) {
			delete PPA[i];
		}
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
		} while (!finish);

		std::cout << "-------------------------------------------" << endl;
		std::cout << "Thanks for using Seneca Library Application" << endl;
	}
}