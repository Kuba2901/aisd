#include "AttributeNode.h"

AttributeNode::AttributeNode()
{
    attribute = NULL;
    prev = NULL;
    next = NULL;
    deleted = 0;
}

Attribute *AttributeNode::GetAttribute()
{
    return this->attribute;
}

void AttributeNode::SetNext(AttributeNode *newNode)
{
    this->next = newNode;
}

void AttributeNode::SetPrev(AttributeNode *newNode)
{
    this->prev = newNode;
}

void AttributeNode::toString()
{
    this->attribute->toString();
}

AttributeNode *AttributeNode::GetNext()
{
    return this->next;
}

AttributeNode *AttributeNode::GetPrevious()
{
    return this->prev;
}

AttributeNode::~AttributeNode()
{
}

int AttributeNode::Compare(AttributeNode *node)
{
    if (attribute != NULL)
    {
        return node->GetAttribute()->GetName()->Compare(attribute->GetName()->GetString());
    }

    return 0;
}

void AttributeNode::SetAttribute(Attribute *newNode)
{
    this->attribute = newNode;
}
