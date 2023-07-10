/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6 Part 1
// Version 1.0
// Description
// professor's tester program
//
// Name: Ngai Man Szeto
// ID:180094211
// Section: ZAA
// Email:nszeto1@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
   Line::operator const char *() const
   {
      return (const char *)m_value;
   }
   Line &Line::operator=(const char *lineValue)
   {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line()
   {
      delete[] m_value;
   }
   // private function
   //  set all to safe status
   void TextFile::setEmpty()
   {
      if (bool() == false)
      {
         delete[] m_textLines;
         delete[] m_filename;
         m_textLines = nullptr;
         m_filename = nullptr;
         m_noOfLines = 0;
      }
   }

   void TextFile::setFilename(const char *fname, bool isCopy)
   {
      // condition exp for  allocate member size.
      int len;
      delete[] m_filename;
      m_filename = nullptr;
      if (!isCopy)
      {
         len = strLen(fname);
         m_filename = new char[len + 1];
         strCpy(m_filename, fname);
      }
      // bool is true, allocate member with "C_" and current fname
      else
      {
         len = strLen(fname) + 2;
         m_filename = new char[len + 1];
         strCpy(m_filename, "C_");
         strCat(m_filename, fname);
      }
   }

   void TextFile::setNoOfLines()
   {
      int noOfLines = 0;
      string line;
      ifstream openObj(name());
      if (openObj.is_open())
      {
         while (!openObj.eof())
         {
            getline(openObj, line);
            noOfLines++;
         }
      }
      if (noOfLines == 0)
      {
         delete[] m_filename;
         m_filename = nullptr;
      }
      else
      {
         m_noOfLines = (noOfLines + 1);
      }
      openObj.close();
   }

   void TextFile::loadText()

   {
      // set bool check, only action if m_filename is not empty.
      bool check = (m_filename == nullptr);
      if (!check)
      {
         delete[] m_textLines;
         m_textLines = new Line[m_noOfLines];
         ifstream openObj(m_filename);
         unsigned int i = 0;
         if (openObj.is_open())
         {
            string line;
            while (getline(openObj, line))
            {
               m_textLines[i] = line.c_str();
               i++;
            }
            openObj.close();
         }
         m_noOfLines = i;
      }
   }

   void TextFile::saveAs(const char *fileName) const
   {

      ofstream openObj(fileName);
      // read the local object OPEN to loop the textLine array by noOfLine
      if (openObj.is_open())
      {
         for (unsigned int i = 0; i < m_noOfLines; i++)
         {
            // add 1 line to the end each line.
            openObj << m_textLines[i] << endl;
         }
      }
      openObj.close();
   }

   TextFile::TextFile(unsigned pageSize)
   {
      // set empty and attribute using pageSize = 15
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
      m_pageSize = pageSize;
   }

   TextFile::TextFile(const char *filename, unsigned pageSize)
   {
      // set empty and attribute using pageSize = 15 and current filename

      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
      m_pageSize = pageSize;
      if (filename)
      {
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }

   // copy construct
   TextFile::TextFile(const TextFile &src)
   {
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
      m_pageSize = src.m_pageSize;
      if (src)
      {
         setFilename(src.name(), true);
         src.saveAs(name());
         setNoOfLines();
         loadText();
      }
   }

   // copy assignment
   TextFile &TextFile::operator=(const TextFile &src)
   {
      if (this != &src)
      {
         delete[]m_textLines;
         m_textLines = nullptr;
         m_noOfLines = 0;
         m_pageSize = src.m_pageSize;
         if (src)
         {
            src.saveAs(name());
            setNoOfLines();
            loadText();
         }
      }
      return *this;
   }

   TextFile::~TextFile()
   {
      delete[] m_textLines;
      m_textLines = nullptr;
      delete[] m_filename;
      m_filename = nullptr;
   }

   unsigned TextFile::lines() const
   {
      return m_noOfLines;
   }

   std::ostream &TextFile::view(std::ostream &ostr) const
   {
      int fileNameLength = strLen(m_filename);
      if (*this && m_noOfLines >= 1)
      {
         //using iomanip
         ostr << m_filename << endl;
         ostr << setfill('=');
         ostr << setw(fileNameLength) << "=" << endl;
         ostr << setfill(' ');
         //display the text data
         unsigned int i = 0;
            while ( i < m_noOfLines)
            {
               ostr << m_testFile[i]<< endl;
               i++;
               if (i % m_pageSize == 0)
               {
                  ostr << "Hit ENTER to continue...";
                  cin.ignore(1000, '\n');
               }
            }
      }
      return ostr;
   }

   std::istream &TextFile::getFile(std::istream &istr)
   {
      string objName;
      istr >> objName;
      cin.ignore();
      setFilename(objName.c_str());
      setNoOfLines();
      loadText();

      return istr;
   }

   const char *TextFile::operator[](unsigned index) const
   {

      const char *element = nullptr;
      if (*this)
      {
         // return element 10 or 20  % 10 = index:0 <-first element
         // if index = 11, return   index:1 <-second element
         index = index % m_noOfLines;
         element = m_textLines[index];
      }
      return element;
   }

   const char *TextFile::name() const
   {
      return m_filename;
   }
   TextFile::operator bool() const
   {
      bool check = true;
      check = (m_filename == nullptr && m_textLines == nullptr && m_noOfLines == 0) ? false : true;
      return check;
   }

   ostream &operator<<(ostream &ostr, const TextFile &text)
   {
      text.view(ostr)
      return ostr;
   }

   istream &operator>>(istream &istr, TextFile &text)
   {
      return text.getFile(istr);
   }
}
