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
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
using namespace std;

namespace sdds
{
   bool Date::validate()
   {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1)
      {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12)
      {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays())
      {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays() const
   {
      int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   int Date::systemYear() const
   {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday()
   {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1() const
   { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3)
      {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() : m_CUR_YEAR(systemYear())
   {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear())
   {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char *Date::dateStatus() const
   {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear() const
   {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode)
   {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode() const
   {
      return m_ErrorCode;
   }
   bool Date::bad() const
   {
      return m_ErrorCode != 0;
   }

   std::istream &Date::read(std::istream &is)
   {
      int yy, mm, dd;
      // read is yy/mm/dd, and ignore any char
      // set errCode to NO_ERROR
      errCode(NO_ERROR);
      is >> yy;
      is.ignore();
      is >> mm;
      is.ignore();
      is >> dd;
      // check is fail? return CIN_FAILED
      if (is.fail())
      {
         errCode(CIN_FAILED);
         is.clear();
         is.ignore(1000, '\n');
      }
      else
      {
         m_year = yy;
         m_mon = mm;
         m_day = dd;
         validate();
         is.clear();
         is.ignore(1000, '\n');
      }
      return is;
   }

   std::ostream &Date::write(std::ostream &os) const
   {
      // if in bad status, print the dateStatus
      if (bad())
      {
         os << dateStatus();
      }
      else
      {
         // using <iomanip> for output
         os << m_year << "/";
         os << setfill('0') << setw(2) << m_mon << "/";
         os << setfill('0') << setw(2) << m_day;
      }
      return os;
   }

   ostream &operator<<(ostream &os, const Date &RO)
   {
      return RO.write(os);
   }
   istream &operator>>(istream &is, Date &RO)
   {
      return RO.read(is);
   }

   // Overload operator
   // if same ,return true
   bool Date::operator==(const Date &newDate) const
   {

      bool same = (m_year == newDate.m_year && m_mon == newDate.m_mon && m_day == newDate.m_day);
      return same;
   }
   // if return bigger the newDate or equal ,return true
   bool Date::operator>=(const Date &newDate) const
   {
      bool same = (*this > newDate || *this == newDate);
      return same;
   }
   // if return smaller the newDate or equal ,return true
   bool Date::operator<=(const Date &newDate) const
   {
      bool same = (*this < newDate || *this == newDate);
      return same;
   }
   // if any date smaller than newDate, return true
   bool Date::operator<(const Date &newDate) const
   {
      bool same = false;
      if (m_year < newDate.m_year)
      {
         same = true;
      }
      else if (m_year == newDate.m_year)
      {
         if (m_mon < newDate.m_mon)
         {
            same = true;
         }
         else if (m_mon == newDate)
         {
            if (m_day < newDate.m_day)
            {
               same = true;
            }
            else
            {
               same = false;
            }
         }
         else
         {
            same = false;
         }
      }

      return same;
   }

   // if any date bigger than newDate, return true
   bool Date::operator>(const Date &newDate) const
   {
      bool same = false;
      if (m_year > newDate.m_year)
      {
         same = true;
      }
      else if (m_year == newDate.m_year)
      {
         if (m_mon > newDate.m_mon)
         {
            same = true;
         }
         else if (m_mon == newDate)
         {
            if (m_day > newDate.m_day)
            {
               same = true;
            }
            else
            {
               same = false;
            }
         }
         else
         {
            same = false;
         }
      }

      return same;
   }

   // return the minus value
   int Date::operator-(const Date &newDate) const
   {

      return (daysSince0001_1_1() - newDate.daysSince0001_1_1());
   }

   // return true , if no in bad
   Date::operator bool() const
   {

      return !bad();
   }

   bool Date::operator!=(const Date &newDate) const
   {

      return !(*this == newDate);
   }
};
