#include "DoublyLinkedSection.h"

// head
DoublyLinkedSection::DoublyLinkedSection()
{
    head = NULL;
}

void DoublyLinkedSection::PushToTheFront(SectionNode *newNode)
{
    if (head != NULL)
    {
        head->SetPrev(newNode);
        newNode->SetNext(head);
        newNode->SetPrev(NULL);
    }
    else
    {
        this->head = newNode;
    }
}

void DoublyLinkedSection::AppendToTheBack(SectionNode *newNode)
{
    if (head != NULL)
    {
        SectionNode *tmp = head;

        while (tmp != NULL)
        {
            tmp = tmp->GetNext();
        }

        tmp->SetNext(newNode);
        newNode->SetPrev(tmp);
        newNode->SetNext(NULL);
    }
    else
    {
        head = newNode;
    }
}

void DoublyLinkedSection::PrintDLL()
{
    if (head != NULL)
    {
        SectionNode *tmp = head;

        while (tmp != NULL)
        {
            tmp->toString();
            tmp = tmp->GetNext();
        }
    }
}

int DoublyLinkedSection::GetListLen()
{
    int counter = 0;
    if (head != NULL)
    {
        SectionNode *tmp = head;

        while (tmp != NULL)
        {
            counter++;
            tmp = tmp->GetNext();
        }
    }

    return counter;
}

SectionNode *DoublyLinkedSection::GetLast()
{
    int finalCount = GetListLen();
    int counter = 0;

    if (head != NULL)
    {
        SectionNode *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->GetNext();
        }

        return tmp;
    }

    return NULL;
}

SectionNode *DoublyLinkedSection::GetAtPos(int pos)
{
    int index = 0;
    if (head != NULL)
    {
        SectionNode *tmp = head;

        while (tmp != NULL)
        {
            if (index == pos)
                return tmp;

            tmp = tmp->GetNext();
        }

        return NULL;
    }

    return NULL;
}

SectionNode *DoublyLinkedSection::GetHead()
{
    return this->head;
}

void DoublyLinkedSection::DeleteElement() {}

int DoublyLinkedSection::GetSelectorsCount()
{
    int counter = 0;

    if (head != NULL)
    {
        SectionNode *tmp = head;

        while (tmp != NULL)
        {
            Section *sections = tmp->GetSections();

            for (int i = 0; i < T; i++)
            {
                if (sections[i].Counts())
                {
                    counter += sections[i].GetSelectorsCount();
                }
            }

            tmp = tmp->GetNext();
        }
    }

    return counter;
}

Section *DoublyLinkedSection::GetSectionAtPos(int i)
{
    int index = 0;

    if (head != NULL)
    {
        SectionNode *tmp = head;

        while (tmp != NULL)
        {

            Section *sections = tmp->GetSections();

            for (int i = 0; i < T; i++)
            {
                if (sections[i].Counts())
                {
                    index++;
                }

                if (index == i)
                {
                    return &sections[i];
                }
            }

            tmp = tmp->GetNext();
        }

        return NULL;
    }

    return NULL;
}

DoublyLinkedSection::~DoublyLinkedSection()
{
}
