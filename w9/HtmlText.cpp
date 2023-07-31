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
#include <iostream>
#include "cstring.h"
#include "HtmlText.h"


namespace sdds {
	//pass the arge filanme to base class
	HtmlText::HtmlText(const char* filename, const char* title): Text{filename}
	{
		if (title)
		{
			cpyConstr(m_title, title);
		}
		else
		{
			m_title = nullptr;
		}
	}
	//rule of three
	

	HtmlText::~HtmlText()
	{
		delete[]m_title;
		m_title = nullptr;
	}
	// pass the obj to base cpyConstruct
	HtmlText::HtmlText(const HtmlText& cpyHtml) : Text(cpyHtml)
	{
		cpyConstr(m_title, cpyHtml.m_title);
	}

	HtmlText& HtmlText::operator=(const HtmlText& cpyHtml)
	{
		if (this != &cpyHtml)
		{
			//pass the obj to base cpy Assign
			Text::operator=(cpyHtml);
			delete[]m_title;
			cpyConstr(m_title, cpyHtml.m_title);
		}
		return *this;
	}

	//using the protected index operator
	// base clase protect "operator[](int index)"
	//loop all element of operator m_content
	void HtmlText::write(std::ostream& os) const
	{
		bool MS = false;
		
		os << "<html><head><title>";
		//if m_title is not null, insert the title,
		//condition express
		os << (m_title != nullptr ? m_title : "No Title");
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		
		//loop all element of m_content
		//set tempValue to store the content of title
		char tempValue;
		int i = 0;
		while (this->operator[](i) !='\0')
		{
			tempValue = this->operator[](i);
			if (tempValue == ' ')
			{
				if (MS)
				{
					os << "&nbsp;";
				}
				else
				{
					MS = true;
					os << ' ';
				}
			}
			else if (tempValue == '<')
			{
				os << "&lt;";
				MS = false;
			}
			else if (tempValue == '>')
			{
				os << "&gt;";
				MS = false;
			}
			else if (tempValue == '\n')
			{
				os << "<br />\n";
				MS = false;
			}
			else
			{
				MS = false;
				os << tempValue;
			}
			i++;
		}
		os << "</body>\n</html>";
		
	}
}