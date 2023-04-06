#include "Section.h"

Section::Section()
{
    this->selectors = NULL;
    this->attributes = NULL;
    this->deleted = 0;
    this->filled = 0;
}

DoublyLinkedSelector *Section::GetSelectors()
{
    return this->selectors;
}

DoublyLinkedAttribute *Section::GetAttributes()
{
    return this->attributes;
}

int Section::GetDeleted()
{
    return this->deleted;
}

int Section::GetSelectorsCount()
{
    return this->selectors->GetListLen();
}

int Section::GetAttributesCount()
{
    return this->attributes->GetListLen();
}

void Section::SetDeleted()
{
    this->deleted = 1;
}

void Section::SetFilled()
{
    this->filled = 1;
}

void Section::toString()
{
    std::cout << "Selectors" << std::endl;
    selectors->PrintDLL();

    std::cout << "Attributes" << std::endl;
    attributes->PrintDLL();
}

int Section::Free()
{
    return (!filled && !deleted);
}

int Section::Counts()
{
    return (filled && !deleted);
}

Section::~Section()
{
}

Section &Section::operator=(const Section &cs)
{
    if (this == &cs)
        return *this;

    this->selectors = cs.selectors;
    this->attributes = cs.attributes;
    this->deleted = cs.deleted;
    this->filled = cs.filled;

    return *this;
}
