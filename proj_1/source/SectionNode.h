#pragma once
#include "SectionNode.h"
#include "Section.h"

class SectionNode;
class Section;

class SectionNode // : public ListNode
{
private:
    SectionNode *next;
    SectionNode *prev;
    Section *sections;

public:
    SectionNode();

    // * @brief Set the next element of this to the newNode
    virtual void SetNext(SectionNode *newNode);

    // * @brief Set previous next element of this to the newNode
    virtual void SetPrev(SectionNode *newNode);

    // * @brief Print out the content of the node
    virtual void toString();

    // * @brief Get the pointer to the next element
    virtual SectionNode *GetNext();

    // * @brief Get the pointer to the previous element
    virtual SectionNode *GetPrevious();

    // * @brief Get sections of the node
    virtual Section *GetSections();

    // Count sections that are both filled and not removed
    virtual int CountSections();

    // Get the count of selectors
    virtual int GetSelectorsCount();

    // Get the count of attributes
    virtual int GetAttributesCount();

    // Add a new section to the dll
    virtual void AddSection(Section *newSection);

    // * @brief Destructor of the node
    virtual ~SectionNode();
};