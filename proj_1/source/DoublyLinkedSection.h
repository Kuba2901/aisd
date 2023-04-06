#pragma once
#include "SectionNode.h"
#include "Section.h"

class SectionNode;
class Section;

class DoublyLinkedSection // : public DoublyLinked
{
private:
    SectionNode *head;

public:
    // Emprt constructor
    DoublyLinkedSection();

    // * @brief Push a new node to the front of the list
    virtual void PushToTheFront(SectionNode *newNode);

    // * @brief Append a new node to the back of the list
    virtual void AppendToTheBack(SectionNode *newNode);

    // * @brief Print out the contents of the whole DLL
    virtual void PrintDLL();

    // * @brief Get the length of the DLL list
    virtual int GetListLen();

    // * @brief Get the last element of the DLL
    virtual SectionNode *GetLast();

    // * @brief Get the element of the DLL at a specified index
    virtual SectionNode *GetAtPos(int pos);

    // * @brief Get the head element of the DLL
    virtual SectionNode *GetHead();

    // * @brief Delete element from the DLL
    virtual void DeleteElement();

    // Get total selectors count
    virtual int GetSelectorsCount();

    // Gets the Section at the given position
    virtual Section *GetSectionAtPos(int i);

    // * @brief Destructor of the DLL
    virtual ~DoublyLinkedSection();
};