#pragma once
#include "CustomString.h"

class CustomString;

class SelectorNode // : public ListNode
{
private:
    CustomString *selector;
    SelectorNode *next;
    SelectorNode *prev;

public:
    // SelectorNode empty constructor
    SelectorNode();

    // * @brief Set the next element of this to the newNode
    virtual void SetNext(SelectorNode *newNode);

    // * @brief Set previous next element of this to the newNode
    virtual void SetPrev(SelectorNode *newNode);

    // * @brief Set the selector value to a new string
    virtual void SetSelector(CustomString *newNode);

    virtual CustomString *GetSelector();

    // * @brief Print out the content of the node
    virtual void toString();

    // * @brief Get the pointer to the next element
    virtual SelectorNode *GetNext();

    // * @brief Get the pointer to the previous element
    virtual SelectorNode *GetPrevious();

    // * @brief Destructor of the node
    virtual ~SelectorNode();
};