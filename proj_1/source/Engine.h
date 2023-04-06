#pragma once
#include "DoublyLinkedSection.h"
#include "CommandProcessor.h"
#include "SectionNode.h"
#include "CustomString.h"

class DoublyLinkedSection;
class CommandProcessor;
class SectionNode;
class CustomString;

class Engine
{
private:
    DoublyLinkedSection *dll;
    CommandProcessor *processor;

public:
    // * @brief The main application engine constructor
    Engine();

    // @brief The main DLL getter
    virtual DoublyLinkedSection *GetDLL();

    // Determines the SectionNode that the newly loaded section will be stored in
    SectionNode *DetermineSectionNode();

    /*
     * @brief Gets the head of the main engine DLL
     * @details A shortcut to an already define function from the DoublyLinkedSection class
     */
    virtual SectionNode *GetHead();

    // Print out the number of sections
    virtual void PrintSectionsCount();

    // Determines which command should be executed
    virtual void DetermineCommand(CustomString cs);

    // Loads in a new section
    virtual void GetSection();
};