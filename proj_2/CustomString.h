#pragma once
#include <iostream>
#include "string.h"

class CustomString
{

private:
    char *str;

    friend std::ostream &operator<<(std::ostream &os, CustomString &customString);
    friend std::istream &operator>>(std::istream &is, CustomString &customString);

public:
    // No arguments Constructor
    CustomString();

    // Constructor with 1 arguments
    CustomString(char *val);

    // Copy Constructor
    CustomString(const CustomString &source);

    // Move Constructor
    CustomString(CustomString &&source);

    // @brief Empty out the string
    virtual void EmptyString();

    // String getter
    virtual char *GetString();

    // String getter
    virtual void SetString(char *str);

    // Assignment operator
    CustomString &operator=(const CustomString &cs);

    // Add operation
    virtual CustomString &Add(CustomString &a, CustomString &b);

    // Append characters to string
    virtual void Append(char *s, char c);

    // Trim the string
    virtual void Trim();

    // Check if the string is empty
    virtual int IsEmpty();

    /*
     * @brief Check whether the string is a number
     * @returns
     * 1 - true
     * 0 - false
     */
    virtual int IsNumber();

    /*
     * @brief Compare two strings
     * @returns
     * 1 - same
     * 0 - different
     */
    virtual int Compare(char *second);

    virtual CustomString *GetSubstring(int beg, int end);

    ~CustomString();
};
