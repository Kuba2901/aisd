#pragma once
#include "CustomString.h"
#include "AttributeNode.h"

class CustomString;
class AttributeNode;

class DoublyLinkedAttribute //: public DoublyLinked
{
private:
    AttributeNode *head;

public:
    // * @brief Push a new node to the front of the list
    virtual void PushToTheFront(AttributeNode *newNode);

    // * @brief Append a new node to the back of the list
    virtual void AppendToTheBack(AttributeNode *newNode);

    // * @brief Print out the contents of the whole DLL
    virtual void PrintDLL();

    // * @brief Get the length of the DLL list
    virtual int GetListLen();

    // * @brief Get the last element of the DLL
    virtual AttributeNode *GetLast();

    // * @brief Get the element of the DLL at a specified index
    virtual AttributeNode *GetAtPos(int pos);

    // * @brief Get the head element of the DLL
    virtual AttributeNode *GetHead();

    // * @brief Delete element from the DLL
    virtual void DeleteElement(CustomString &n);

    // Check if the is already defined
    virtual AttributeNode *CheckIfAttributeExists(AttributeNode *node);

    // * @brief Destructor of the DLL
    virtual ~DoublyLinkedAttribute();
};