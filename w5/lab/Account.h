/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 1
// Version 1.0
// Description
// professor's tester program
//
// Name: Ngai Man Szeto
// ID:180094211
// Section: ZAA
// Email:nszeto1@myseneca.ca
// Submission Date: 06-14-2023
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_ACCOUNT_H_   //header
#define SDDS_ACCOUNT_H_     //header
#include <iostream>         //header

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      bool inValid(); //self function. check valid
      
      operator bool() const;// unary 
      operator int() const;//unary 
		operator double() const;//unary 
      bool operator ~() const;//unary 
      
      Account& operator =(int number); //binary
      Account& operator =(Account& newAcc);//binary
		
		Account& operator +=(double bal);//binary
		Account& operator -=(double bal);//binary
      Account& operator >>(Account& newAcc);//binary    , sum acc balance to right
      Account& operator <<(Account& newAcc);//binary, sum acc balance to left
    
      
   };
   //set helper function: make sure outside the class
   double operator +(const Account& a, const Account& b); 
   double operator +=(double& ref, const Account& bal);
   
}
#endif // SDDS_ACCOUNT_H_