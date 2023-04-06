#pragma once
#include "CustomString.h"

class CustomString;

class Attribute
{
private:
    CustomString *name;
    CustomString *value;
    int deleted;

public:
    // * @brief Empty constructor of an attribute
    Attribute();

    // * @brief Set the name of the attribute
    virtual void SetName(char *newName);

    // * @brief Set the value of deleted property to true
    virtual void SetDeleted();

    // * @brief Set the value of the attribute
    virtual void SetValue(char *newValue);

    // * @brief Get the value of the attribute
    virtual CustomString *GetName();

    // * @brief Get the value of the deleted argument
    virtual int GetDeleted();

    // * @brief Get the value of the attribute
    virtual CustomString *GetValue();

    // Prints out the value of the attribute
    virtual void toString();

    virtual ~Attribute();
};