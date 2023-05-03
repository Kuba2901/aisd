#include "Processor.h"

int main()
{
    Processor *processor = new Processor;
    processor->GetDimensions();
    processor->LoadMap();
    processor->FindCities();
    processor->bfs();
    processor->GetFlights();
    processor->GetResults();

    return 0;
}