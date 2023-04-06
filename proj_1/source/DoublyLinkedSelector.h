#pragma once
#include "SelectorNode.h"

class SelectorNode;

class DoublyLinkedSelector // : public DoublyLinked
{
private:
    SelectorNode *head;

public:
    // * @brief Push a new node to the front of the list
    virtual void PushToTheFront(SelectorNode *newNode);

    // * @brief Append a new node to the back of the list
    virtual void AppendToTheBack(SelectorNode *newNode);

    // * @brief Print out the contents of the whole DLL
    virtual void PrintDLL();

    // * @brief Get the length of the DLL list
    virtual int GetListLen();

    // * @brief Get the last element of the DLL
    virtual SelectorNode *GetLast();

    // * @brief Get the element of the DLL at a specified index
    virtual SelectorNode *GetAtPos(int pos);

    // * @brief Get the head element of the DLL
    virtual SelectorNode *GetHead();

    // * @brief Destructor of the DLL
    virtual ~DoublyLinkedSelector();
};