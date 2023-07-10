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
#include <string.h>
#include "cstring.h"
namespace sdds
{
    void strCpy(char *des, const char *src)
    {
        int i;
        for (i = 0; src[i] != '\0'; i++)
        {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

    void strnCpy(char *des, const char *src, int len)
    {
        int i;

        for (i = 0; i < len - 1 && src[i]; i++)
        {
            des[i] = src[i];
        }
        des[i] = src[i];
    }

    int strCmp(const char *s1, const char *s2)
    {
        int i;
        for (i = 0; i < s1[i] && s2[i] && s1[i] == s2[i]; i++) // find the s1 and s2 length
        {
            ;
        }
        return s1[i] - s2[i]; // s1-s2= 0, s1-s2 >0 reture >0 , s1 -s2 < 0 return <0
    }

    int strnCmp(const char *s1, const char *s2, int len)
    {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i])
        {
            i++; /* code */
        }

        return s1[i] - s2[i];
    }

    int strLen(const char *s)
    {
        if (!s )
        {
            return 0;
        }

        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }
        return i;
    }

    // //const char *strStr(const char *str1, const char *str2)
    //   {
    //     const char* nullAddress = nullptr;
    //     if (*str2 == '\0')
    //     {
    //         return str1; // find empty string2, return string1 as a match
    //     }   

    //     while (*str1 != '\0')
    //     {
    //         const char *p1 = str1;
    //         const char *p2 = str2;

    //         while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
    //         {
    //             p1++;
    //             p2++;
    //         }

    //         if (*p2 == '\0')
    //         {
    //             return str1; // Match found
    //         }

    //         str1++;
    //     }

    //     return nullAddress; // No match found
    // }
   void strCat(char *des, const char *src)
    {
        int i = strLen(des), j = strLen(src), k = 0;
        while (k < j)
        {
            des[i + k] = src[k];
            k++; /* code */
        }
        des[i + j] = '\0';
    }
}