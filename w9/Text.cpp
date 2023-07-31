/***********************************************************************
// Intro. to Object Oriented Programming
// workshop 9.1
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
#include <fstream>
#include "cstring.h"
#include "Text.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }


   const char& Text::operator[](int index)const
   {
       if (strlen(m_content) > size_t(index) || size_t(strlen(m_content)) > 0)
       {
           m_content[index];
       }
       else
       {
           index= strlen(m_content)
       }
       return m_content[index];
   }
   Text::Text()
   {
       M_Content = nullptr;
   }
   Text::Text(

   
 
   Text::~Text()
   {
       delete[]m_content;
       m_content = nullptr;
       delete[]m_filename;
       m_filename = nullptr;
   }
   //allocate memory fileName obj by cstring function
   Text::Text(const char* filename)
   {
       if (filename)
       {
            cpyConstr(m_filename, filename);
            //read the copy the content
            read();
       }
       else
       {
           m_filename = nullptr;
       }
       
   }
   //cpy constr by cstring function
   Text::Text(const Text& txt)
   {
       operator = (txt);
       //cpyConstr(m_content, txt.m_content);  
   }
   //copy assignment
   Text& Text::operator=(const Text& txt)
   {
       if (this != &txt)
       {
            delete[]m_content;
            cpyConstr(m_content, txt.m_content);
       }
       
       return *this;
   }
   
   //read the current content of file
   //allocate memory to size of the file  +1--> 
   //using variable int getFileLength()
   void Text::read()
   {
       //open and set the temp fin to the file obj
       std::ifstream fin(m_filename);
       //set temp char to store the end Character
       char endChar='\0';
       int i = 0;
       if (fin.is_open())
       {
            //allocate the m_content
           int fLength = getFileLength();
           m_content = new char[fLength + 1];

           
           //readthe file until the end
           //set \0 at the end
           while (fin.get(endChar))
           {
               m_content[i++] = endChar;
           }
           m_content[i] = '\0';
       }
       fin.clear();
       fin.close();
   }
   //content of the Text class into the ostream
   //if m_content is not null.
   void Text::write(std::ostream& os)const
   {
       if (m_content != nullptr)
       {
           os << m_content;
       }
   }

   std::ostream& operator<<(std::ostream& os, const Text& txt)
   {
       txt.write(os);
       return os;
   }
}

