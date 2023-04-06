#include "SectionNode.h"

/*
SectionNode* next;
SectionNode* prev;
*/

SectionNode::SectionNode()
{
    this->next = NULL;
    this->prev = NULL;
    this->sections = NULL;
}

void SectionNode::SetNext(SectionNode *newNode)
{
    this->next = newNode;
}

void SectionNode::SetPrev(SectionNode *newNode)
{
    this->prev = newNode;
}

void SectionNode::toString()
{
    std::cout << "Section info" << std::endl;
    for (int i = 0; i < T; i++)
    {
        sections[i].toString();
    }
}

SectionNode *SectionNode::GetNext()
{
    return this->next;
}

SectionNode *SectionNode::GetPrevious()
{
    return this->prev;
}

Section *SectionNode::GetSections()
{
    return this->sections;
}

int SectionNode::GetSelectorsCount()
{
    int counter = 0;

    for (int i = 0; i < T; i++)
    {
        Section &section = sections[i];
        if (section.Counts())
        {
            counter += section.GetSelectorsCount();
        }
    }

    return counter;
}

int SectionNode::GetAttributesCount()
{
    int counter = 0;

    for (int i = 0; i < T; i++)
    {
        Section &section = sections[i];
        if (section.Counts())
        {
            counter += section.GetAttributesCount();
        }
    }

    return counter;
}

int SectionNode::CountSections()
{
    int counter = 0;

    if (sections != NULL)
    {
        for (int i = 0; i < T; i++)
        {
            counter += sections->Counts();
        }
    }

    return counter;
}

void SectionNode::AddSection(Section *newSection)
{
    for (int i = 0; i < T; i++)
    {
        if (sections[i].Free())
        {
            sections[i] = *newSection;
        }
    }
}

SectionNode::~SectionNode()
{
}