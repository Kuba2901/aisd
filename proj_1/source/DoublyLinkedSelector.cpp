#include "DoublyLinkedSelector.h"

void DoublyLinkedSelector::PushToTheFront(SelectorNode *newNode)
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

void DoublyLinkedSelector::AppendToTheBack(SelectorNode *newNode)
{
    if (head != NULL)
    {
        SelectorNode *tmp = head;

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

void DoublyLinkedSelector::PrintDLL()
{
    if (head != NULL)
    {
        SelectorNode *tmp = head;

        while (tmp != NULL)
        {
            tmp->toString();
            tmp = tmp->GetNext();
        }
    }
}

int DoublyLinkedSelector::GetListLen()
{
    int counter = 0;
    if (head != NULL)
    {
        SelectorNode *tmp = head;

        while (tmp != NULL)
        {
            counter++;
            tmp = tmp->GetNext();
        }
    }

    return counter;
}

SelectorNode *DoublyLinkedSelector::GetLast()
{
    if (head != NULL)
    {
        SelectorNode *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->GetNext();
        }

        return tmp;
    }

    return NULL;
}

SelectorNode *DoublyLinkedSelector::GetAtPos(int pos)
{
    int index = 0;
    if (head != NULL)
    {
        SelectorNode *tmp = head;

        while (tmp != NULL)
        {
            index++;

            if (index == pos)
                return tmp;

            tmp = tmp->GetNext();
        }
    }

    return NULL;
}

SelectorNode *DoublyLinkedSelector::GetHead()
{
    return this->head;
}

DoublyLinkedSelector::~DoublyLinkedSelector()
{
}