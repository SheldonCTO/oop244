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
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
   class Text {
       char* m_filename{};
       char* m_content{};
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
       //rule of 3
    
       ~Text();
       Text(const char* filename=nullptr);
       Text(const Text& txt);
       Text& operator=(const Text& txt);

      void read();
      virtual void write(std::ostream& os)const;
   };
   //Overload the insertion operator
   //Text object into ostream. (from rig to lef)
   std::ostream& operator<<(std::ostream& os, const Text& txt);
}
#endif // !SDDS_PERSON_H__

