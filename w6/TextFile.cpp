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
      if (lineValue != nullptr)
      {
         delete[] m_value;
         m_value = new char[strLen(lineValue) + 1];
         strCpy(m_value, lineValue);
      }
      return *this;
   }
   Line::~Line()
   {
      delete[] m_value;
      m_value = nullptr;
   }
   // private function
   //  set all to safe status
   void TextFile::setEmpty()
   {
      // delete[] m_textLines;
      m_textLines = nullptr;
      // delete[] m_filename;
      m_filename = nullptr;
      m_noOfLines = 0;
   }

   void TextFile::setFilename(const char *fname, bool isCopy)
   {
      // condition exp for  allocate member size.
      int len;
      delete[] m_filename;

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
         strcpy(m_filename, "C_");
         strCat(m_filename, fname);
      }
   }

   void TextFile::setNoOfLines()
   {
      //string function to grab the line
      int noOfLines = 0;
      string line;
      //set new char for create local object "open"
      ifstream open(m_filename);
      if (open.is_open())
      {
         while (!open.eof())
         {
            getline(open, line);
            noOfLines++;
         }
         open.close();
      }
      if (noOfLines == 0)
      {
         m_filename = nullptr;
      }
      m_noOfLines = noOfLines;
   
   }

   void TextFile::loadText()
   {
      int i = 0;
      string line;
      // only active when m_filename is valid
      if (m_filename != NULL)
      {
         // make m_textLines in safe before allocate
         delete[] m_textLines;
         m_textLines = new Line[m_noOfLines];
         ifstream open(m_filename);
         // using string and getline to find the length of each line
         // read the file until the EOF
         if (open.is_open())
         {
            while (!open.eof())
            {
               getline(open, line);
               open >> line;
               m_textLines[i] = line.c_str();
               i++;
            }
            open.close();
         }
         m_noOfLines = i;
      }
   }

   void TextFile::saveAs(const char *fileName) const
   {
      ofstream open(fileName);
      // read the local object OPEN to loop the textLine array by noOfLine
      if (open.is_open())
      {
         for (int i = 0; i < m_noOfLines; i++)
         {
            // add 1 line to the end each line.
            open << m_textLines[i] << endl;
         }
      }
      open.close();
   }

   TextFile::TextFile(unsigned pageSize)
   {
      // set empty and attribute using pageSize = 15
      setEmpty();
      m_pageSize = pageSize;
   }

   TextFile::TextFile(const char *filename, unsigned pageSize)
   {
      // set empty and attribute using pageSize = 15 and current filename
      setEmpty();
      m_pageSize = pageSize;
      if (filename != nullptr)
      {
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }

   // copy construct
   TextFile::TextFile(const TextFile &src)
   {
      setEmpty();
      m_pageSize = src.m_pageSize;
      if (src)
      {
         setFilename(src.m_filename, true);
         saveAs(src.m_filename);
         setNoOfLines();
         loadText();
      }
   }

   // copy assignment
   TextFile &TextFile::operator=(const TextFile &src)
   {
         if (src)
         {
            delete[] m_textLines;
            m_textLines = nullptr;
            // m_pageSize = src.m_pageSize;
            src.saveAs(m_filename);
            setNoOfLines();
            loadText();
         }
      return *this;
   }

   // destruct
   TextFile::~TextFile()
   {
      delete[] m_filename;
      delete[] m_textLines;
   }

   unsigned TextFile::lines() const
   {
      return m_noOfLines;
   }

   // display, use iomanip library
   std::ostream &TextFile::view(std::ostream &ostr) const
   {
      int fileNameLength = strLen(m_filename);
      ifstream open(m_filename);
      if (*this)
      {
         ostr << m_filename << endl;
         ostr << setfill('=');
         ostr << setw(fileNameLength) << "=" << endl;
         ostr << setfill(' ');

         int i = 0;
         if (open.is_open())
         {
            std::string line;
            while (getline(open, line))
            {
               ostr << line.c_str() << endl;
               i++;
               if (i % m_pageSize == 0)
               {

                  ostr << "Hit ENTER to continue...";
                  cin.ignore(1000, '\n');
               }
            }
            open.close();
         }
      }
      return ostr;
   }
   // receive file
   std::istream &TextFile::getFile(std::istream &istr)
   {
      // create local filename for receiving the file

      char *fileName = new char[MAX_PATH + 1];
      istr.getline(fileName, MAX_PATH + 1);
      setFilename(fileName);
      setNoOfLines();
      loadText();
      // delete[] fileName;
      return istr;
   }

   const char *TextFile::operator[](unsigned index) const
   {
      const char *element = nullptr;
      if (*this)
      {
         if (index >= m_noOfLines) // if index = 10, noOfLine = 10 ,
         {
            // return element 10 -10 = index:0 <-first element
            // if index = 11, return   index:1 <-second element
            index = index - m_noOfLines;

            element = m_textLines[index];
         }
      }
      return element;
   }

   TextFile::operator bool() const
   {
      return (m_filename != nullptr && m_textLines != nullptr && m_noOfLines != 0);
   }

   const char *TextFile::name() const
   {
      return m_filename;
   }

   std::ostream &operator<<(std::ostream &ostr, const TextFile &text)
   {
      // just print the ostr
      text.view(ostr);
      return ostr;
   }
   std::istream &operator>>(std::istream &istr, TextFile &text)
   {
      return text.getFile(istr);
   }
}

