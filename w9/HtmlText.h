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
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
       char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      ~HtmlText();
      HtmlText(const HtmlText& cpyHtml);
      HtmlText& operator=(const HtmlText& cpyHtml);
      //override the virtual write function of hte base classs
      //using the protected index operator
      void write(std::ostream& os) const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
