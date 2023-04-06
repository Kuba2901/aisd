#include "DoublyLinkedAttribute.h"

void DoublyLinkedAttribute::PushToTheFront(AttributeNode *newNode)
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

void DoublyLinkedAttribute::AppendToTheBack(AttributeNode *newNode)
{
    if (head != NULL)
    {
        AttributeNode *tmp = head;

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

void DoublyLinkedAttribute::PrintDLL()
{
    if (head != NULL)
    {
        AttributeNode *tmp = head;

        while (tmp != NULL)
        {
            tmp->toString();
            tmp = tmp->GetNext();
        }
    }
}

int DoublyLinkedAttribute::GetListLen()
{
    int counter = 0;
    if (head != NULL)
    {
        AttributeNode *tmp = head;

        while (tmp != NULL)
        {
            Attribute *attribute = tmp->GetAttribute();
            if (!attribute->GetDeleted())
                counter++;
            tmp = tmp->GetNext();
        }
    }

    return counter;
}

AttributeNode *DoublyLinkedAttribute::GetLast()
{
    int finalCount = GetListLen();
    int counter = 0;

    if (head != NULL)
    {
        AttributeNode *tmp = head;
        while (tmp != NULL)
        {
            Attribute *attribute = tmp->GetAttribute();

            // Add to counter only if attribute is not deleted
            if (!attribute->GetDeleted())
                counter++;

            // Compare the counter to the index of the last non-deleted element
            if (counter == finalCount)
            {
                return tmp;
            }

            tmp = tmp->GetNext();
        }

        return NULL;
    }

    return NULL;
}

AttributeNode *DoublyLinkedAttribute::GetAtPos(int pos)
{
    int index = 0;
    if (head != NULL)
    {
        AttributeNode *tmp = head;

        while (tmp != NULL)
        {
            Attribute *attribute = tmp->GetAttribute();

            if (!attribute->GetDeleted())
                index++;
            if (index == pos)
                return tmp;

            tmp = tmp->GetNext();
        }

        return NULL;
    }

    return NULL;
}

AttributeNode *DoublyLinkedAttribute::GetHead()
{
    return this->head;
}

void DoublyLinkedAttribute::DeleteElement(CustomString &n)
{
    if (head != NULL)
    {
        AttributeNode *tmp = head;

        while (tmp != NULL)
        {
            Attribute *attribute = tmp->GetAttribute();

            if (attribute->GetName()->Compare(n.GetString()))
            {
                attribute->SetDeleted();
                return;
            }

            tmp = tmp->GetNext();
        }
    }
}

AttributeNode *DoublyLinkedAttribute::CheckIfAttributeExists(AttributeNode *node)
{
    if (head != NULL)
    {
        AttributeNode *tmp = head;

        while (tmp != NULL)
        {
            if (tmp->Compare(node))
            {
                return tmp;
            }

            tmp = tmp->GetNext();
        }
    }

    return NULL;
}

DoublyLinkedAttribute::~DoublyLinkedAttribute()
{
}