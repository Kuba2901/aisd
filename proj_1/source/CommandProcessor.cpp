#include "CommandProcessor.h"
#include "DoublyLinkedAttribute.h"
#include "DoublyLinkedSelector.h"
#include "CustomString.h"
#include "SelectorNode.h"
#include "AttributeNode.h"
#include "Attribute.h"

CommandProcessor::CommandProcessor(DoublyLinkedSection *initializer)
{
    this->dll = initializer;
}

void CommandProcessor::PrintSelectorsCountForSectionI(int i)
{
    SectionNode *node = dll->GetAtPos(i);

    if (node != NULL)
    {
        std::cout << " == " << node->GetSelectorsCount() << std::endl;
    }
}

void CommandProcessor::PrintSelectorJForSectionI(int j, int i)
{
    SectionNode *node = dll->GetAtPos(i);
    int index = 0;

    if (node != NULL)
    {
        for (int i = 0; i < T; i++)
        {

            Section &section = node->GetSections()[i];
            if (section.Counts())
            {
                DoublyLinkedSelector *selectors = section.GetSelectors();

                // Iterate through selectors
                SelectorNode *selNode = selectors->GetHead();

                while (selNode != NULL)
                {
                    index++;

                    if (index == j)
                    {
                        std::cout << " == " << selNode->GetSelector()->GetString() << std::endl;
                        return;
                    }

                    selNode = selNode->GetNext();
                }
            }
        }
    }
}

void CommandProcessor::PrintAttributesCountForSectionI(int i)
{
    SectionNode *node = dll->GetAtPos(i);

    if (node != NULL)
    {
        std::cout << " == " << node->GetAttributesCount() << std::endl;
    }
}

void CommandProcessor::PrintAttributeNForSectionI(CustomString &n, int i)
{
    SectionNode *node = dll->GetHead();
    int index = 0;

    if (node != NULL)
    {
        for (int i = 0; i < T; i++)
        {

            Section &section = node->GetSections()[i];
            if (section.Counts())
            {
                index++;

                if (index == i)
                {
                    DoublyLinkedAttribute *attributes = section.GetAttributes();

                    // Iterate through attributes
                    AttributeNode *attNode = attributes->GetHead();

                    while (attNode != NULL)
                    {
                        index++;

                        if (attNode->GetAttribute()->GetName()->Compare(n.GetString()))
                        {
                            std::cout << " == " << attNode->GetAttribute()->GetName()->GetString() << std::endl;
                            return;
                        }

                        attNode = attNode->GetNext();
                    }
                }
            }
        }
    }
}

void CommandProcessor::DeleteSectionI(int i)
{
    Section *section = dll->GetSectionAtPos(i);

    if (section != NULL)
    {
        section->SetDeleted();
    }
}

void CommandProcessor::DeleteAttributeNFromSectionI(CustomString &n, int i)
{
    Section *section = dll->GetSectionAtPos(i);

    if (section != NULL)
    {
        DoublyLinkedAttribute *attributes = section->GetAttributes();
        AttributeNode *tmp = attributes->GetHead();

        if (tmp->GetAttribute()->GetName()->Compare(n.GetString()))
        {
            tmp->GetAttribute()->SetDeleted();

            // Delete the whole section if no attributes are left
            if (!attributes->GetListLen())
            {
                section->SetDeleted();
            }

            return;
        }
    }
}

void CommandProcessor::PrintAttributeTotalCount(CustomString &n)
{
    int counter = 0;
    if (dll->GetHead() != NULL)
    {
        SectionNode *tmp = dll->GetHead();

        while (tmp != NULL)
        {
            Section *sections = tmp->GetSections();

            for (int i = 0; i < T; i++)
            {
                if (sections[i].Counts())
                {
                    DoublyLinkedAttribute *attributes = sections[i].GetAttributes();
                    AttributeNode *attNode = attributes->GetHead();

                    while (attNode != NULL)
                    {
                        Attribute *attribute = attNode->GetAttribute();

                        if (!attribute->GetDeleted() && attribute->GetName()->Compare(n.GetString()))
                        {
                            counter++;
                        }

                        attNode = attNode->GetNext();
                    }
                }
            }

            tmp = tmp->GetNext();
        }
    }

    std::cout << " == " << counter << std::endl;
}

void CommandProcessor::PrintSelectorTotalCount(CustomString &n)
{
    int counter = 0;
    if (dll->GetHead() != NULL)
    {
        SectionNode *tmp = dll->GetHead();

        while (tmp != NULL)
        {
            Section *sections = tmp->GetSections();

            for (int i = 0; i < T; i++)
            {
                if (sections[i].Counts())
                {
                    DoublyLinkedSelector *selectors = sections[i].GetSelectors();
                    SelectorNode *selNode = selectors->GetHead();

                    while (selNode != NULL)
                    {
                        CustomString *selector = selNode->GetSelector();

                        if (selector->Compare(n.GetString()))
                        {
                            counter++;
                        }

                        selNode = selNode->GetNext();
                    }
                }
            }

            tmp = tmp->GetNext();
        }
    }

    std::cout << " == " << counter << std::endl;
}

void CommandProcessor::PrintAttributeNForSelectorZ(CustomString &n, CustomString &z)
{
    if (dll->GetLast() != NULL)
    {
        SectionNode *tmp = dll->GetLast();

        while (tmp != NULL)
        {
            Section *sections = tmp->GetSections();

            for (int i = 0; i < T; i++)
            {
                if (sections[i].Counts())
                {
                    DoublyLinkedSelector *selectors = sections[i].GetSelectors();
                    SelectorNode *selNode = selectors->GetLast();

                    while (selNode != NULL)
                    {
                        CustomString *selector = selNode->GetSelector();

                        // Correct selector found
                        if (selector->Compare(n.GetString()))
                        {
                            DoublyLinkedAttribute *attributes = sections[i].GetAttributes();
                            AttributeNode *attNode = attributes->GetLast();

                            while (attNode != NULL)
                            {
                                Attribute *attribute = attNode->GetAttribute();

                                if (!attribute->GetDeleted() && attribute->GetName()->Compare(n.GetString()))
                                {
                                    std::cout << " == " << attribute->GetValue()->GetString() << std::endl;
                                }
                            }
                        }

                        selNode = selNode->GetPrevious();
                    }
                }
            }

            tmp = tmp->GetPrevious();
        }
    }
}

CommandProcessor::~CommandProcessor()
{
}