#include "Processor.h"
#include "CustomQueue.h"

// CustomVector<Position> getNeighbors(Processor *processor, const Position &point)
// {
//     int row = point.y;
//     int x = point.x;
//     CustomVector<Position> neighbors;
//     int rowOffsets[] = {-1, 0, 1, 0};
//     int xOffsets[] = {0, 1, 0, -1};
//     for (int i = 0; i < 4; i++)
//     {
//         int newRow = row + rowOffsets[i];
//         int newx = x + xOffsets[i];
//         Position *pkt = new Position(newx, newRow);
//         if (processor->InBounds(pkt) && processor->Traversable(pkt))
//         {
//             neighbors.push_back(*pkt);
//         }
//     }

//     for (int i = 0; i < neighbors.getSize(); i++)
//     {
//         std::cout << neighbors[i].x << " " << neighbors[i].y << std::endl;
//     }

//     return neighbors;
// }

// void BFS(Processor *processor, const Position &start)
// {
//     CustomQueue<Position> queue;
//     queue.push(start);
//     processor->SetVisited(start, true);

//     while (!queue.empty())
//     {
//         Position current = queue.front();
//         queue.pop();

//         CustomVector<Position> neighbors = getNeighbors(processor, current);
//         for (int i = 0; i < neighbors.getSize(); i++)
//         {
//             Position neighbor = neighbors[i];
//             if (!processor->GetVisited(neighbor))
//             {
//                 processor->SetVisited(neighbor, true);
//                 queue.push(neighbor);
//             }
//         }
//     }
// }

int main()
{
    Processor *processor = new Processor;
    CustomString cs{"KRAKOW"};

    int w, h; // Szerokość i wysokość mapy
    std::cout << "[*] Ready" << std::endl;

    // Load in the dimensions of the map
    processor->GetDimensions();

    // Load the map itself
    processor->LoadMap();

    // // Find all cities and their exits
    // processor->FindCities();

    // processor->PrintCities();

    // // Run the bfs algorithm to create weighted a graph
    // // bfs(processor, *processor->GetCities()[0]->GetPosition(), *processor->GetCities()[1]->GetPosition());
    // getNeighbors(processor, *processor->GetCities()[1]->GetPosition());

    return 0;
}