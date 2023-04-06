#pragma once
#include "CustomString.h"
#include "DoublyLinkedSection.h"

class CustomString;
class DoublyLinkedSection;

class CommandProcessor
{
private:
    DoublyLinkedSection *dll;

public:
    // Constructor
    CommandProcessor(DoublyLinkedSection *initializer);

    // Wypisz liczbę selektorów dla sekcji nr i (numery zaczynają się od 1), jeśli nie ma takiego bloku pomiń
    virtual void PrintSelectorsCountForSectionI(int i);

    // Wypisz j-ty selector dla i-tego bloku (numery sekcji oraz atrybutów zaczynają się od 1) jeśli nie ma sekcji lub selektora pomiń
    virtual void PrintSelectorJForSectionI(int j, int i);

    // Wypisz liczbę atrybutów dla sekcji nr i, jeśli nie ma takiego bloku lub sekcji pomiń
    virtual void PrintAttributesCountForSectionI(int i);

    // Wypisz dla i-tej sekcji wartość atrybutu o nazwie n, jeśli nie ma takiego pomiń
    virtual void PrintAttributeNForSectionI(CustomString &n, int i);

    // Usuń całą sekcję nr i (tj. separatory+atrybuty), po poprawnym wykonaniu wypisz deleted
    virtual void DeleteSectionI(int i);

    // Usuń z i-tej sekcji atrybut o nazwie n, jeśli w wyniku operacji pozostaje pusta sekcja powinna zostać również usunięta (wraz z ew. selektorami), po poprawnym wykonaniu wypisz deleted.
    virtual void DeleteAttributeNFromSectionI(CustomString &n, int i);

    // Wypisz łączną (dla wszystkich bloków) liczbę wystąpień atrybutu nazwie n. (W ramach pojedynczego bloku duplikaty powinny zostać usunięte na etapie wczytywania). Możliwe jest 0;
    virtual void PrintAttributeTotalCount(CustomString &n);

    // Wypisz łączną (dla wszystkich bloków) liczbę wystąpień selektora z. Możliwe jest 0;
    virtual void PrintSelectorTotalCount(CustomString &n);

    // Wypisz wartość atrybutu o nazwie n dla selektora z, w przypadku wielu wystąpień selektora z bierzemy ostatnie. W przypadku braku pomiń
    virtual void PrintAttributeNForSelectorZ(CustomString &n, CustomString &z);

    // Command processor destructor
    ~CommandProcessor();
};