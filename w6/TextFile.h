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
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
#define MAX_PATH 256

namespace sdds
{
 class Line
  {
      char* m_value{ nullptr };
      operator const char* ()const;
      Line() {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;
      // copy and copy assignment prevention goes here
   };

   class TextFile
   {
      Line *m_textLines;
      char *m_filename;
      unsigned m_noOfLines;
      unsigned m_pageSize;
      void setFilename(const char *fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName) const;
      void setEmpty();

   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char *filename, unsigned pageSize = 15);
      TextFile(const TextFile &);
      TextFile &operator=(const TextFile &);
      ~TextFile();
      std::ostream &view(std::ostream &ostr) const;
      std::istream &getFile(std::istream &istr);
      operator bool() const;
      unsigned lines() const;
      const char *name() const;
      const char *operator[](unsigned index) const;
   };
   std::ostream &operator<<(std::ostream &ostr, const TextFile &text);
   std::istream &operator>>(std::istream &istr, TextFile &text);

}
#endif // !SDDS_TEXTFILE_H__
