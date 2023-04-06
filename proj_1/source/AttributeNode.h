#pragma once
#include "Attribute.h"

class Attribute;

class AttributeNode // : public ListNode
{
private:
    Attribute *attribute;
    AttributeNode *prev;
    AttributeNode *next;

    int deleted;

public:
    // Attribute node constructor
    AttributeNode();

    // * @brief Set the next element of this to the newNode
    virtual void SetNext(AttributeNode *newNode);

    // * @brief Set previous next element of this to the newNode
    virtual void SetPrev(AttributeNode *newNode);

    // * @brief Set the value of attribute to newNode
    virtual void SetAttribute(Attribute *newNode);

    // * @brief Print out the content of the node
    virtual void toString();

    // * @brief Get the pointer to the next element
    virtual AttributeNode *GetNext();

    // * @brief Get the pointer to the previous element
    virtual AttributeNode *GetPrevious();

    // * @brief Get value of the Attribute
    virtual Attribute *GetAttribute();

    /*
     * @brief Checks if the two attributes are the same
     * @returns 1 - same
     * @returns 0 - different
     */
    virtual int Compare(AttributeNode *node);

    // * @brief Destructor of the node
    virtual ~AttributeNode();
};