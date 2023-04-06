#include "CustomString.h"
#include "Attribute.h"
#include "DoublyLinked.h"
#include "AttributeNode.h"
#include "SelectorNode.h"
#include "DoublyLinkedAttribute.h"

CustomString &CustomString::Add(CustomString &a, CustomString &b)
{
    char result[10000]; // array to hold the result.

    strcpy(result, a.GetString()); // copy string one into the result.
    strcat(result, b.GetString()); // append string two to the result.

    CustomString *cs = new CustomString(result);

    return *cs;
}

// Return the list of custom string
void CustomString::SplitAttributes(DoublyLinkedAttribute *dll)
{
    // // std::cout  << "Getting attributes..." << std::endl;
    Attribute *attributes = new Attribute[MAX_NAME_SIZE];

    int i = 0;
    int j = 0;

    // Seperate attributes
    char *ptr;

    ptr = strtok(str, ":;");

    while (ptr != NULL)
    {
        if (i % 2 == 0)
        {
            attributes[j].SetName(ptr);
            attributes[j].GetName()->Trim();
        }
        else
        {
            attributes[j].SetValue(ptr);
            attributes[j].GetValue()->Trim();

            // Append to the DLL
            AttributeNode *attNode = new AttributeNode;
            attNode->SetAttribute(&attributes[j]);

            AttributeNode *originalNode = dll->CheckIfAttributeExists(attNode);

            if (originalNode != NULL && originalNode != nullptr)
            {
                originalNode->GetAttribute()->SetValue(attNode->GetAttribute()->GetValue()->GetString());
                originalNode = dll->CheckIfAttributeExists(attNode);
            }
            else
            {
                dll->AppendToTheBack(attNode);
            }

            if (i != 0)
            {
                j++;
            }
        }

        ptr = strtok(NULL, ":;");
        i++;
    }
}

// Return the list of custom string
void CustomString::SplitSelectors(DoublyLinkedSelector *dll)
{

    CustomString *buffer = new CustomString[MAX_NAME_SIZE];
    CustomString *newBuffer = new CustomString[MAX_NAME_SIZE];
    int i = 0;

    char *ptr;

    ptr = strtok(str, ";");

    while (ptr != NULL)
    {
        buffer[i].SetString(ptr);
        ptr = strtok(NULL, ";");
        i++;
    }

    // Reset the value
    ptr = strtok(buffer[i - 1].GetString(), ",");
    // [!] Testing
    // delete [] buffer;
    i = 0;

    while (ptr != NULL)
    {
        newBuffer[i].SetString(ptr);
        newBuffer[i].Trim();
        SelectorNode *selNode = new SelectorNode;
        selNode->SetSelector(&newBuffer[i]);
        dll->AppendToTheBack(selNode);
        ptr = strtok(NULL, ",");
        i++;
    }
}

// Check if a section is being opened/closed
int CustomString::SectionOpened(int open)
{
    int len = strlen(str);

    // { - 123
    // } - 125

    for (int i = 0; i < len; i++)
    {
        int charCode = int(str[i]);

        // Opening the section
        if (!open && charCode == 123)
        {
            open = 1;
        }
        else if (open && charCode == 125)
        {
            open = 0;
        }
    }

    return open;
}

void CustomString::Trim()
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if (str != NULL && str[0] != '\0')
    {
        len = strlen(str);
        endp = str + len;

        /* Move the front and back pointers to address the first non-whitespace
         * characters from each end.
         */
        while (isspace((unsigned char)*frontp))
        {
            ++frontp;
        }
        if (endp != frontp)
        {
            while (isspace((unsigned char)*(--endp)) && endp != frontp)
            {
            }
        }

        if (frontp != str && endp == frontp)
            *str = '\0';
        else if (str + len - 1 != endp)
            *(endp + 1) = '\0';

        /* Shift the string so that it starts at str so that if it's dynamically
         * allocated, we can still free it on the returned pointer.  Note the reuse
         * of endp to mean the front of the string buffer now.
         */
        endp = str;
        if (frontp != str)
        {
            while (*frontp)
            {
                *endp++ = *frontp++;
            }
            *endp = '\0';
        }
    }
}

// Appending (for Trimming)
void CustomString::Append(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

// Overloading the assignment operator
CustomString &CustomString::operator=(
    const CustomString &cs)
{
    if (this == &cs)
        return *this;
    // delete [] str;
    str = new char[strlen(cs.str) + 1];
    strcpy(str, cs.str);
    return *this;
}

// String getter
char *CustomString::GetString()
{
    return this->str;
}

// String setter
void CustomString::SetString(char *newStr)
{
    // TODO: Change?
    delete[] str;
    // delete str;
    // str = NULL;
    str = new char[strlen(newStr) + 1];
    strcpy(str, newStr);
}

// Function to illustrate Constructor
// with no arguments
CustomString::CustomString()
    : str{nullptr}
{
    str = new char[1];
    str[0] = '\0';
}

// Overload the << operator
std::ostream &operator<<(std::ostream &os, CustomString &customString)
{
    std::cout << customString.str;
    return os;
}

// Overload the >> operator for cin
std::istream &operator>>(std::istream &is,
                         CustomString &cs)
{
    char *buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    is.getline(buff, 1000);
    cs = CustomString{buff};
    // delete [] buff;
    return is;
}

// Function to illustrate Constructor
// with one arguments
CustomString::CustomString(char *val)
{
    if (val == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }

    else
    {

        str = new char[strlen(val) + 1];

        // Copy character of val[]
        // using strcpy
        strcpy(str, val);
        str[strlen(val)] = '\0';
    }
}

// Function to illustrate
// Copy Constructor
CustomString::CustomString(const CustomString &source)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    str[strlen(source.str)] = '\0';
}

// Function to illustrate
// Move Constructor
CustomString::CustomString(CustomString &&source)
{
    str = source.str;
    source.str = nullptr;
}

void CustomString::EmptyString()
{
    memset(this->str, 0, sizeof this->str);
}

SplitCommands *CustomString::SplitForCommands()
{
    int i = 0;

    SplitCommands *commands = new SplitCommands;
    CustomString *buffer = new CustomString[MAX_NAME_SIZE];
    commands->count = 0;
    commands->elements = buffer;

    char *ptr;

    ptr = strtok(str, ", ");

    while (ptr != NULL)
    {
        buffer[i].SetString(ptr);
        buffer[i].Trim();
        // // std::cout  << "Command element: " << buffer[i] << std::endl;

        ptr = strtok(NULL, ", ");
        commands->count++;
        i++;
    }

    // [!] Testing
    // delete[] buffer;

    return commands;
}

int CustomString::IsNumber()
{
    int flag = 1;

    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]) && str[i] != '\n')
        {
            flag = 0;
        }
    }

    return flag;
}

int CustomString::Compare(char *second)
{
    if (!strcmp(str, second))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Empty
int CustomString::Empty()
{
    if (strlen(str) == 0 || str[0] == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

CustomString::~CustomString()
{
}