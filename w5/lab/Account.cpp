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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty()
   {
      m_number = -1;
      m_balance = 0.0;
   }

   Account::Account()
   {
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance)
   {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream &Account::display() const
   {
      if (*this)
      {
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if (~*this)
      {
         cout << "  NEW  |         0.00 ";
      }
      else
      {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   bool Account::inValid()// self function: Set check valid value in other function
   {
      return (m_number < 0 || m_balance < 0.0) ? true : false;
   }

   Account ::operator bool() const  //Check  2 args within the boundary
   {
      bool check = (m_number >= 10000 && m_number <= 99999 && m_balance >= 0) ? true : false;
      return check;
   }

   Account ::operator int() const // return number to member_number
   {
      return m_number;
   }

   Account::operator double() const  //return  double number to member_balance
   {
      return m_balance;
   }
   bool Account ::operator~() const  //check deallocate memory
   {
      return (m_number == 0) ? true : false;
   }

   Account &Account::operator=(int number)  //binary operator for m_number and return number(*this)to member
   {
      if (!inValid() && m_number == 0 && m_balance == 0.0 && number >= 10000 && number <= 99999)
      {
         setEmpty();
         m_number = number;
      }
      return *this;
   }

   Account &Account::operator=(Account &newAcc)//binary operator: for account, return "new" to member 
   {
      if (!inValid() && this->m_number == 0 && this->m_balance == 0.0 &&
          newAcc.m_number >= 10000 && newAcc.m_number <= 99999)
      {
         this->m_number = newAcc.m_number;
         newAcc.m_number = 0;
         this->m_balance = newAcc.m_balance;
         newAcc.m_balance = 0;
      }
      return *this;
   }

   Account &Account::operator+=(double bal) //binary operator: in order to add bal to m_balance
   {
      if (!inValid() && bal >= 0)
      {
         m_balance += bal;
      }
      return *this;
   }

   Account &Account::operator-=(double bal)//binary operator: in order to reduce the  bal value from m_balance
   {
      if (!inValid() && bal >= 0 && m_balance >= bal)
      {
         m_balance -= bal;
      }
      return *this;
   }

   Account &Account::operator>>(Account &newAcc)  //Check the Account is in valid state: 
                                                   //newAcc balance will sum both balance and set left to 0
   {
      if (!this->inValid() && !newAcc.inValid() && this->m_number != newAcc.m_number)
      {
         newAcc.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   Account &Account::operator<<(Account &newAcc)//Check the Account is in valid state  
                                                   //m_balance will sum both balance and set right to 0
   {
      if (!this->inValid() && !newAcc.inValid() && this->m_number != newAcc.m_number)
      {
         m_balance += newAcc.m_balance;
         newAcc.m_balance = 0;
      }
      return *this;
   }

   double operator+(const Account &a, const Account &b)   //helper function.If current object a,b is valid, sum the balance and return
                                                         // if invalid, return 0
   {
      double value;
      if (!~a && !~b)
      {
         value = double(a) + double(b);
      }
      else
      {
         value = 0;
      }
      return value;
   }
   double operator+=(double &ref, const Account &bal)// set helper function to accept the right current ac reference balance
                                                      // add to left double ref. and return  
   {
      if (!~bal)  
      {
         ref = (ref + double(bal));    
      }
      return ref;
   }

}