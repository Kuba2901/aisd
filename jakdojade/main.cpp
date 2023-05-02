#include "Processor.h"

int main()
{
    Processor *processor = new Processor;
    processor->GetDimensions();
    processor->LoadMap();
    processor->FindCities();
    processor->bfs();

    return 0;
}