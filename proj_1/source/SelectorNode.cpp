#include "SelectorNode.h"

/*
CustomString* selector;
SelectorNode* next;
SelectorNode* prev;
*/

SelectorNode::SelectorNode()
{
    this->selector = NULL;
    this->next = NULL;
    this->prev = NULL;
}

CustomString *SelectorNode::GetSelector()
{
    return this->selector;
}

void SelectorNode::SetSelector(CustomString *newNode)
{
    this->selector->SetString(newNode->GetString());
}

void SelectorNode::SetNext(SelectorNode *newNode)
{
    this->next = newNode;
}

void SelectorNode::SetPrev(SelectorNode *newNode)
{
    this->prev = newNode;
}

void SelectorNode::toString()
{
    std::cout << "Selector: " << selector->GetString() << std::endl;
}

SelectorNode *SelectorNode::GetNext()
{
    return this->next;
}

SelectorNode *SelectorNode::GetPrevious()
{
    return this->prev;
}

SelectorNode::~SelectorNode()
{
}