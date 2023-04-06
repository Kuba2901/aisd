#pragma once
#include <iostream>
#include "string.h"
#include "const.h"
#include "DoublyLinkedSelector.h"
#include "DoublyLinkedAttribute.h"
#include "SplitCommands.h"

class DoublyLinkedSelector;
class DoublyLinkedAttribute;
struct SplitCommands;

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

    // Check if the section is being opened or closed
    virtual int SectionOpened(int open);

    // Assignment operator
    CustomString &operator=(const CustomString &cs);

    // Split attributes operation
    virtual void SplitAttributes(DoublyLinkedAttribute *dll);

    // Split selectors operation
    virtual void SplitSelectors(DoublyLinkedSelector *dll);

    // Add operation
    virtual CustomString &Add(CustomString &a, CustomString &b);

    // Append characters to string
    virtual void Append(char *s, char c);

    // Split for commands control
    virtual SplitCommands *SplitForCommands();

    // Trim the string
    virtual void Trim();

    // Check if the string is empty
    virtual int Empty();

    /*
     * @brief Check whether the string is a number
     * @returns
     * 1 - true
     * 0 - false
     */
    virtual int IsNumber();

    /*
     * @brief Compare two strings
     * @returns 1 - same
     * @returns 2 - different
     */
    virtual int Compare(char *second);

    ~CustomString();
};
