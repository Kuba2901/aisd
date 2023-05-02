#include "Processor.h"
#include "const.h"

Processor::Processor()
{
    this->width = 0;
    this->height = 0;
}

void Processor::FindRoute()
{

    // CustomString *start = new CustomString{"GDANSK"};
    // CustomString *end = new CustomString{"KRAKOW"};

    // std::cout << "Looking for GDANSK..." << std::endl;
    // Position *c1 = DeterminePosition(*start);

    // std::cout << "Looking for KRAKOW..." << std::endl;
    // Position *c2 = DeterminePosition(*end);
}

void Processor::GetDimensions()
{
    CustomString cs;
    std::cin >> cs;

    char *str = cs.GetString();

    int i = 0;
    CustomString *buffer = new CustomString[MAX_NAME_SIZE];
    char *ptr;

    ptr = strtok(str, " ");

    while (ptr != NULL)
    {
        if (i == 0)
        {
            this->width = atoi(ptr);
        }
        else
        {
            this->height = atoi(ptr);
        }

        ptr = strtok(NULL, " ");
        i++;
    }

    std::cout << "W: " << width << ", height: " << height << std::endl;
}

void Processor::LoadMap()
{

    char c;

    std::cout << map[0]->getSize() << std::endl;
    std::cout << map[0]->getSize() << std::endl;
    map[0]->push_back(new Position(0, 0, false, 'c'));
    map[0]->push_back(new Position(0, 1, false, 'c'));
    map[0]->push_back(new Position(0, 2, false, 'c'));

    map[1]->push_back(new Position(0, 20, false, 'c'));
    // map[1].push_back(new Position(0, 22, false, 'c'));

    for (auto y : map[0][0])
    { // Copy of 'x', almost always undesirable
        std::cout << y->y << " ";
    }

    // for (int y = 0; y < height; y++)
    // {
    //     for (int x = 0; x < width; x++)
    //     {
    //         c = getchar();
    //         map[y].push_back(new Position(x, y, false, c));
    //     }
    // }

    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         printf("%c", map[i][j]->character);
    //     }

    //     printf("\n");
    // }
}

// Position *Processor::DeterminePosition(CustomString &cityName)
// {
//     for (int y = 0; y < height; y++)
//     {
//         for (int i = 0; i < width - strlen(cityName.GetString()); i++)
//         {
//             CustomString *cs = new CustomString(*map[y].GetSubstring(i, i + strlen(cityName.GetString())));
//             if (cs->Compare(cityName.GetString()))
//             {

//                 Position *pos = FindAsterisk(i, y, cityName);
//                 std::cout << cs->GetString() << " exit found (" << pos->x << "," << pos->y << ")" << std::endl;

//                 // Set initial values of the pawn
//                 pawn->x = pos->x;
//                 pawn->y = pos->y;

//                 return pos;
//             }

//             delete cs;
//         }
//     }
// }

// Position *Processor::FindAsterisk(int x, int y, CustomString &cityName)
// {
//     int startX = x, endX = x + strlen(cityName.GetString());
//     Position *pos = new Position;

//     if (x != 0)
//     {
//         for (int i = startX - 1; i <= endX; i++) // TODO: Change later if segfault (out of bounds on right side)
//         {
//             // Not at the top
//             if (y != 0)
//             {
//                 if (map[y - 1].GetString()[i] == '*')
//                 {

//                     pos->x = i;
//                     pos->y = y - 1;
//                     return pos;
//                 }
//             }

//             if (map[y].GetString()[i] == '*')
//             {
//                 pos->x = i;
//                 pos->y = y;
//                 return pos;
//             }

//             if (y != height - 1)
//             {
//                 if (map[y + 1].GetString()[i] == '*')
//                 {
//                     pos->x = i;
//                     pos->y = y + 1;
//                     return pos;
//                 }
//             }
//         }
//     }
//     else if (x != width - 1)
//     {
//         for (int i = startX; i < endX + 1; i++)
//         {
//             // Not at the top
//             if (y != 0)
//             {
//                 if (map[y - 1].GetString()[i] == '*')
//                 {
//                     pos->x = i;
//                     pos->y = y - 1;
//                     return pos;
//                 }
//             }

//             if (map[y].GetString()[i] == '*')
//             {
//                 pos->x = i;
//                 pos->y = y;
//                 return pos;
//             }

//             if (y != height - 1)
//             {
//                 if (map[y + 1].GetString()[i] == '*')
//                 {
//                     pos->x = i;
//                     pos->y = y + 1;
//                     return pos;
//                 }
//             }
//         }
//     }

//     else
//     {
//         for (int i = startX; i < endX; i++)
//         {
//             // Not at the top
//             if (y != 0)
//             {
//                 if (map[y - 1].GetString()[i] == '*')
//                 {
//                     pos->x = i;
//                     pos->y = y - 1;
//                     return pos;
//                 }
//             }

//             if (map[y].GetString()[i] == '*')
//             {
//                 pos->x = i;
//                 pos->y = y;
//                 return pos;
//             }

//             if (y != height - 1)
//             {
//                 if (map[y + 1].GetString()[i] == '*')
//                 {
//                     pos->x = i;
//                     pos->y = y + 1;
//                     return pos;
//                 }
//             }
//         }
//     }
// }

// Type *Processor::GetRoadType(Position *pos)
// {
//     Type *t = new Type;
//     if (pos->x >= 0 && pos->x < width && pos->y >= 0 && pos->y < height)
//     {
//         char element = map[pos->y].GetString()[pos->x];
//         if (element == '#' || element == '*')
//         {
//             t->code = 1;
//             return t;
//         }

//         return NULL;
//     }

//     return NULL;
// }

// void Processor::FindCities()
// {
//     for (int y = 0; y < height; y++)
//     {
//         for (int x = 0; x < width; x++)
//         {
//             if (map[y].GetString()[x] >= 65 && map[y].GetString()[x] <= 90)
//             {
//                 int i = x;
//                 char buff[20] = "";
//                 while (map[y].GetString()[i] >= 65 && map[y].GetString()[i] <= 90)
//                 {
//                     CustomString().Append(buff, map[y].GetString()[i]);
//                     i++;
//                 }

//                 CustomString *cityName = new CustomString(buff);

//                 // Find corresponding asterisk
//                 Position *asPosition = FindAsterisk(x, y, *cityName);
//                 City *city = new City(cityName, asPosition);

//                 city->toString();

//                 // Push the city to the back of the vector
//                 cities.push_back(city);

//                 break;
//             }
//         }
//     }
// }

// void Processor::PrintCities()
// {
//     for (int i = 0; i < cities.getSize(); i++)
//     {
//         cities[i]->toString();
//     }
// }

// bool Processor::InBounds(Position *pkt)
// {
//     return pkt->x >= 0 && pkt->x < width && pkt->y >= 0 && pkt->y < height;
// }

// bool Processor::Traversable(Position *pkt)
// {
//     int x = pkt->x;
//     int y = pkt->y;

//     char c = map[y].GetString()[x];

//     return !(c > 'A' && c < 'Z' || c == '.');
// }

// CustomVector<City *> Processor::GetCities()
// {
//     return this->cities;
// }

// int Processor::GetHeight()
// {
//     return this->height;
// }

// int Processor::GetWidth()
// {
//     return this->width;
// }

// void Processor::SetVisited(Position *pos, bool visited)
// {
// }