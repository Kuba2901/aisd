#pragma once
#include "DoublyLinkedSelector.h"
#include "DoublyLinkedAttribute.h"
#include "Section.h"

class DoublyLinkedSelector;
class DoublyLinkedAttribute;
class Section;

class Section // : public ListNode
{
private:
    DoublyLinkedSelector *selectors;
    DoublyLinkedAttribute *attributes;

    int deleted;
    int filled;

public:
    // Empty section constructor
    Section();

    // Gets the selectors of the section
    virtual DoublyLinkedSelector *GetSelectors();

    // Gets the attributes of the section
    virtual DoublyLinkedAttribute *GetAttributes();

    // Gets the deleted parameter of the section
    virtual int GetDeleted();

    // Assignment operator
    Section &operator=(const Section &cs);

    // Counts the selectors of the section
    virtual int GetSelectorsCount();

    // Counts the attributes of the section
    virtual int GetAttributesCount();

    // Set the section state to deleted
    virtual void SetDeleted();

    // Set the section state to filled
    virtual void SetFilled();

    // Prints out the section info
    virtual void toString();

    /*
     * @brief Determines whether the section is free or not
     * @returns 1 - free
     * @returns 0 - not free
     */
    virtual int Free();

    /*
     * @brief Determines whether the section should be counted or not
     * @returns 1 - should be counted
     * @returns 0 - should not be counted
     */
    virtual int Counts();

    // Destructor of the section
    virtual ~Section();
};
