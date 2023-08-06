/***********************************************************************
// Intro. to Object Oriented Programming
// Final Project Milestone 4
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
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef _SDDS_PUBLICATION_H_
#define _SDDS_PUBLICATION_H_
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds{
    class Publication : public Streamable{
    private:
        // c-string to hold a dynamic title
        // This attribute is null by default.
        char*m_title;

        // hold exactly 4 charactor from lib.h
        // defaulf empty string
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];

        // is zero by default
        // int to hold 5number
        int m_membership;

        //-1 by default
        int m_libRef;

        // used for the publish date of the item
        Date m_date;

    public:
        // set all member variable to default
        Publication();
        ~Publication();

        // set copy c and copy as
        Publication(const Publication &publication);
        Publication &operator=(const Publication &publication);

        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // using <ctime>
        //  Sets the date to the current date of the system.

        virtual char type() const;
        // Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan() const;
        // Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate() const;
        // Returns the date attribute
        bool operator==(const char *title) const;
        // Returns true if the argument title appears anywhere in the title of the
        // publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char *() const;
        // Returns the title attribute
        int getRef() const;
        // Returns the libRef attirbute.

        // Returns true
        // if io object is the same as  cin object or the cout object.
        bool conIO(std::ios &io) const;

        // write the os data
        //virtual from base class
        std::ostream &write(std::ostream &os) const;

        // Read all the values in local variables
        // set temp for check condition
        //virtual from base class
        std::istream &read(std::istream &is);

        // overload will true, if base class Streamable is valid
        //virtual from base class
        operator bool() const;
    };

}

#endif // _SDDS_PUBLICATION_H_
