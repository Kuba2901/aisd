#include "Processor.h"

int main()
{
    Processor *processor = new Processor;
    processor->GetDimensions();
    processor->LoadMap();
    processor->FindCities();
    processor->PrintCities();
    
    return 0;
}