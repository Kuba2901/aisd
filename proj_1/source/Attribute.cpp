#include "Attribute.h"

Attribute::Attribute()
{
    this->name = new CustomString;
    this->value = new CustomString;
    this->deleted = 0;
}

void Attribute::SetDeleted()
{
    this->deleted = 1;
}

void Attribute::SetName(char *newName)
{
    this->name = new CustomString(newName);
}

void Attribute::SetValue(char *newValue)
{
    this->value = new CustomString(newValue);
}

CustomString *Attribute::GetName()
{
    return this->name;
}

CustomString *Attribute::GetValue()
{
    return this->value;
}

int Attribute::GetDeleted()
{
    return this->deleted;
}

void Attribute::toString()
{
    std::cout << name->GetString() << ": " << value->GetString() << std::endl;
}

Attribute::~Attribute()
{
}
