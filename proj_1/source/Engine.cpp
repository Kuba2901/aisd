#include "Engine.h"
#include "CommandProcessor.h"
#include <cstdlib>

Engine::Engine()
{
    this->dll = new DoublyLinkedSection;
    this->processor = new CommandProcessor(dll);
}

DoublyLinkedSection *Engine::GetDLL()
{
    return this->dll;
}

SectionNode *Engine::DetermineSectionNode()
{
    if (dll->GetHead() != NULL)
    {
        SectionNode *tmp = dll->GetHead();

        while (tmp != NULL)
        {
            Section *sections = tmp->GetSections();

            for (int i = 0; i < T; i++)
            {
                if (sections[i].Free())
                {
                    return tmp;
                }
            }

            tmp = tmp->GetNext();
        }

        // No free section was found in existing nodes ->> creating a new one
        SectionNode *newNode = new SectionNode;
        dll->AppendToTheBack(newNode);

        return newNode;
    }

    // There was no pre-existing section in the DLL
    SectionNode *newNode = new SectionNode;
    dll->AppendToTheBack(newNode);
    return newNode;
}

SectionNode *Engine::GetHead()
{
    return this->dll->GetHead();
}

void Engine::PrintSectionsCount()
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
                    counter++;
                ;
            }

            tmp = tmp->GetNext();
        }
    }

    std::cout << " == " << counter << std::endl;
}

void Engine::DetermineCommand(CustomString cs)
{
    SplitCommands *commands = cs.SplitForCommands();

    // Check whether the "?" command was used and print out counter of all the sections
    if (commands->count == 1)
    {
        if (!strcmp(commands->elements[0].GetString(), "?"))
        {
            PrintSectionsCount();
        }
    }
    // Execute other commands
    else
    {
        // Make sure the input has 3 arguments
        if (commands->count == 3)
        {
            CustomString first = commands->elements[0];
            CustomString second = commands->elements[1];
            CustomString third = commands->elements[2];
            // Check whether the first element is a digit
            if (first.IsNumber())
            {
                // Check if the second parameter is "S"
                if (!strcmp(second.GetString(), "S"))
                {
                    // 1. wypisz liczbę selektorów dla sekcji nr i (numery zaczynają się od 1), jeśli nie ma takiego bloku pomiń
                    if (!strcmp(third.GetString(), "?"))
                    {
                        // std::cout << "wypisz liczbę selektorów dla sekcji nr i (numery zaczynają się od 1), jeśli nie ma takiego bloku pomiń" << std::endl;
                        processor->PrintSelectorsCountForSectionI(atoi(first.GetString()));
                    }

                    // 3. wypisz j-ty selector dla i-tego bloku (numery sekcji oraz atrybutów zaczynają się od 1) jeśli nie ma sekcji lub selektora pomiń
                    else if (third.IsNumber())
                    {
                        // std::cout << "wypisz j-ty selector dla i-tego bloku (numery sekcji oraz atrybutów zaczynają się od 1) jeśli nie ma sekcji lub selektora pomiń;" << std::endl;
                        processor->PrintSelectorJForSectionI(atoi(first.GetString()), atoi(third.GetString()));
                    }
                }

                // Check if the second parameter is "A"
                else if (!strcmp(second.GetString(), "A"))
                {
                    // 2. wypisz liczbę atrybutów dla sekcji nr i, jeśli nie ma takiego bloku lub sekcji pomiń
                    if (!strcmp(third.GetString(), "?"))
                    {
                        // std::cout << "wypisz liczbę atrybutów dla sekcji nr i, jeśli nie ma takiego bloku lub sekcji pomiń" << std::endl;
                        processor->PrintAttributesCountForSectionI(atoi(first.GetString()));
                    }

                    // 4. wypisz dla i-tej sekcji wartość atrybutu o nazwie n, jeśli nie ma takiego pomiń
                    else if (!third.Empty())
                    {
                        // std::cout << "wypisz dla i-tej sekcji wartość atrybutu o nazwie n, jeśli nie ma takiego pomiń" << std::endl;
                        processor->PrintAttributeNForSectionI(third, atoi(first.GetString()));
                    }
                }

                // Check if the second parameter is "D"
                else if (!strcmp(second.GetString(), "D"))
                {
                    // 5. usuń całą sekcję nr i (tj. separatory+atrybuty), po poprawnym wykonaniu wypisz deleted
                    if (!strcmp(third.GetString(), "*"))
                    {
                        // std::cout << "usuń całą sekcję nr i (tj. separatory+atrybuty), po poprawnym wykonaniu wypisz deleted" << std::endl;
                        processor->DeleteSectionI(atoi(first.GetString()));
                    }

                    else if (!third.Empty())
                    {
                        // 6. usuń z i-tej sekcji atrybut o nazwie n, jeśli w wyniku operacji pozostaje pusta sekcja powinna zostać również usunięta (wraz z ew. selektorami), po poprawnym wykonaniu wypisz deleted
                        // std::cout << "usuń z i-tej sekcji atrybut o nazwie n, jeśli w wyniku operacji pozostaje pusta sekcja powinna zostać również usunięta (wraz z ew. selektorami), po poprawnym wykonaniu wypisz deleted" << std::endl;
                        processor->DeleteAttributeNFromSectionI(third, atoi(first.GetString()));
                    }
                }
            }

            // 7. wypisz łączną (dla wszystkich bloków) liczbę wystąpień atrybutu nazwie n. (W ramach pojedynczego bloku duplikaty powinny zostać usunięte na etapie wczytywania). Możliwe jest 0;
            else if (!strcmp(second.GetString(), "A") && !strcmp(third.GetString(), "?"))
            {
                // std::cout << "wypisz łączną (dla wszystkich bloków) liczbę wystąpień atrybutu nazwie " << first << ". (W ramach pojedynczego bloku duplikaty powinny zostać usunięte na etapie wczytywania). Możliwe jest 0" << std::endl;
                processor->PrintAttributeTotalCount(first);
            }

            // 8. wypisz łączną (dla wszystkich bloków) liczbę wystąpień selektora z. Możliwe jest 0;
            else if (!strcmp(second.GetString(), "S") && !strcmp(third.GetString(), "?"))
            {
                // std::cout << "wypisz łączną (dla wszystkich bloków) liczbę wystąpień selektora " << first << ". Możliwe jest 0;" << std::endl;
                processor->PrintSelectorTotalCount(first);
            }

            // 9. wypisz wartość atrybutu o nazwie n dla selektora z, w przypadku wielu wystąpień selektora z bierzemy ostatnie. W przypadku braku pomiń;
            else if (!strcmp(second.GetString(), "E"))
            {
                // std::cout << "wypisz wartość atrybutu o nazwie " << third << " dla selektora " << first <<  ", w przypadku wielu wystąpień selektora z bierzemy ostatnie. W przypadku braku pomiń;" << std::endl;
                processor->PrintAttributeNForSelectorZ(first, third);
            }
        }
    }
}

void Engine::GetSection()
{
    /*
    @brief
    The state defines whether the engine is processing CSS or taking commands
    @param 0 loading CSS
    @param 1 processing commands
    */
    int state = 0;

    // Getting section logic
    CustomString cs;
    CustomString sectionBuffer;
    int i = 0;
    int secIndex = 0;
    int sectionOpenIndex = -1;
    int sectionEndIndex = -1;

    while (std::cin >> cs)
    {
        CustomString newCs = cs;
        cs.Trim();
        char *str = cs.GetString();
        int css = strcmp(str, "****");
        int commands = strcmp(str, "????");

        if (!css)
        {
            state = 0;
        }
        else if (!commands)
        {
            state = 1;
        }
        else
        {
            if (state)
            {
                DetermineCommand(cs);
            }

            else if (strcmp(str, ""))
            {
                str = newCs.GetString();
                SectionNode *determinedSection = DetermineSectionNode();

                // Section instance that will take the data
                Section *section = new Section;

                // Define correct dlls
                DoublyLinkedSelector *selectorsDll = section->GetSelectors();
                DoublyLinkedAttribute *attributesDll = section->GetAttributes();

                // Append to the section buffer
                sectionBuffer = CustomString().Add(sectionBuffer, newCs);

                // Check whether the section has been opened and closed
                while (str[i] != '\0')
                {
                    if (str[i] == '{')
                    {
                        sectionOpenIndex = secIndex;
                    }
                    else if (str[i] == '}')
                    {
                        sectionEndIndex = secIndex;
                    }

                    i++;
                    secIndex++;
                }

                // End the section
                if (sectionOpenIndex != -1 && sectionEndIndex != -1)
                {
                    // Allocate the memory for selectors and attributes
                    char selectorsArea[1000] = "";
                    char attributesArea[1000] = "";

                    // Determine where selectors and attributes begin
                    int attBegin = sectionOpenIndex + 1;
                    int attEnd = sectionEndIndex - sectionOpenIndex - 1;

                    // Copy attributes to the buffer
                    strncpy(attributesArea, sectionBuffer.GetString() + attBegin, attEnd);
                    attributesArea[attEnd] = '\0';

                    // Copy selectors to the buffer
                    strncpy(selectorsArea, sectionBuffer.GetString(), sectionOpenIndex);
                    selectorsArea[sectionOpenIndex] = '\0';

                    // Create CustomString instances from buffers
                    CustomString *attr = new CustomString(attributesArea);
                    CustomString *sel = new CustomString(selectorsArea);

                    // Push selectors and attributes to correct DLLs
                    // Attribute *splitAttr = attr->SplitAttributes(attributesDll);
                    // CustomString *splitSel = sel->SplitSelectors(selectorsDll);
                    if (!sel->Empty() && !attr->Empty())
                    {
                        sel->SplitSelectors(selectorsDll);
                        attr->SplitAttributes(attributesDll);
                    }
                    else
                    {
                        if (!sel->Empty())
                        {
                            std::cout << "Selectors Empty" << std::endl;
                            sel->SplitSelectors(selectorsDll);
                        }
                        else
                        {
                            if (!attr->Empty())
                            {
                                attr->SplitAttributes(attributesDll);
                            }
                        }
                    }

                    // Set the section status as filled and push to the back
                    section->SetFilled();
                    determinedSection->AddSection(section);

                    // Reset the values
                    sectionBuffer.EmptyString();
                    secIndex = 0;
                    sectionOpenIndex = -1;
                    sectionEndIndex = -1;

                    // [!] Testing
                    // delete [] section;
                    // delete [] sel;
                    // delete [] attr;
                }

                i = 0;
            }
        }
    }
}
