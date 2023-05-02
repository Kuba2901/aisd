#include "Processor.h"

Processor::Processor()
{
    this->map = new Point *;
    this->height = 0;
    this->width = 0;
}

void Processor::GetDimensions()
{
    CustomString buff;
    std::cin >> buff;
    char *token = std::strtok(buff.GetString(), " ");

    int i = 0;

    while (token != nullptr)
    {
        if (i == 0)
        {
            width = atoi(token);
            i++;
        }

        height = atoi(token);

        token = std::strtok(nullptr, " ");
    }
}

void Processor::LoadMap()
{

    // Allocate the memory
    map = new Point *[height];
    for (int i = 0; i < height; i++)
    {
        map[i] = new Point[width];
    }

    // Load and fill the map
    char c = getchar();
    int x = 0;
    int y = 0;

    while (c != EOF && y < height)
    {

        if (c != '\n')
        {
            map[y][x].SetCharacter(c);
            map[y][x].SetVisited(false);
            map[y][x].SetX(x);
            map[y][x].SetY(y);

            x++;
        }
        // New line detected
        else
        {
            x = 0;
            y++;
        }

        c = getchar();
    }
}

void Processor::PrintMap()
{
    std::cout << "Printing map" << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j].toString();
        }

        std::cout << std::endl;
    }
}

Point *Processor::FindAsterisk(int x, int y, CustomString &cityName)
{
    int startX = x, endX = x + strlen(cityName.GetString());
    Point *pos = new Point;

    if (x != 0)
    {
        for (int i = startX - 1; i <= endX; i++) // TODO: Change later if segfault (out of bounds on right side)
        {
            // Not at the top
            if (y != 0)
            {
                if (map[y - 1][i].GetCharacter() == '*')
                {
                    pos->SetX(i);
                    pos->SetY(y - 1);
                    return pos;
                }
            }

            if (map[y][i].GetCharacter() == '*')
            {
                pos->SetX(i);
                pos->SetY(y);
                return pos;
            }

            if (y != height - 1)
            {
                if (map[y + 1][i].GetCharacter() == '*')
                {

                    pos->SetX(i);
                    pos->SetY(y + 1);
                    return pos;
                }
            }
        }
    }
    else if (x != width - 1)
    {
        for (int i = startX; i < endX + 1; i++)
        {
            // Not at the top
            if (y != 0)
            {
                if (map[y - 1][i].GetCharacter() == '*')
                {
                    pos->SetX(i);
                    pos->SetY(y - 1);
                    return pos;
                }
            }

            if (map[y][i].GetCharacter() == '*')
            {
                pos->SetX(i);
                pos->SetY(y);
                return pos;
            }

            if (y != height - 1)
            {
                if (map[y + 1][i].GetCharacter() == '*')
                {
                    pos->SetX(i);
                    pos->SetY(y + 1);
                    return pos;
                }
            }
        }
    }

    else
    {
        for (int i = startX; i < endX; i++)
        {
            // Not at the top
            if (y != 0)
            {
                if (map[y - 1][i].GetCharacter() == '*')
                {
                    pos->SetX(i);
                    pos->SetY(y - 1);
                    return pos;
                }
            }

            if (map[y][i].GetCharacter() == '*')
            {
                pos->SetX(i);
                pos->SetY(y);
                return pos;
            }

            if (y != height - 1)
            {
                if (map[y + 1][i].GetCharacter() == '*')
                {
                    pos->SetX(i);
                    pos->SetY(y + 1);
                    return pos;
                }
            }
        }
    }
}

void Processor::FindCities()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (map[y][x].GetCharacter() >= 65 && map[y][x].GetCharacter() <= 90)
            {
                int i = x;
                char buff[20] = "";
                while (map[y][i].GetCharacter() >= 65 && map[y][i].GetCharacter() <= 90)
                {
                    CustomString().Append(buff, map[y][i].GetCharacter());
                    i++;
                }

                CustomString *cityName = new CustomString(buff);

                // Find corresponding asterisk
                Point *asPosition = FindAsterisk(x, y, *cityName);
                City *city = new City(cityName, asPosition);

                // Push the city to the back of the vector
                cities.push_back(city);

                break;
            }
        }
    }
}

void Processor::PrintCities() {
    for (int i = 0; i < cities.getSize(); i++)
    {
        cities[i]->toString();
        std::cout << std::endl;
    }
    
}



// Getting neighbours
CustomVector<BFSPoint *> Processor::getNeighbors(BFSPoint *bfsP) {
    CustomVector<BFSPoint *> neighbors;
    Point *p = bfsP->GetPoint();

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {

            if (dx != dy && !(dx == -1 && dy == 1 ) && !(dx == 1 && dy == -1)) {
                int x_ = p->GetX() + dx;
                int y_ = p->GetY() + dy;

                Point *temp = new Point(x_, y_);

                if (inBounds(temp)) {
                    Point *neighbor = &(map[y_][x_]);
                    BFSPoint *nb = new BFSPoint(neighbor, 0);

                    if (neighbor->isTraversable())  {
                        neighbors.push_back(nb);
                    }
                        
                }
            
            }

        }
    }
    return neighbors;
}

// BFS function to find distances between chosen points
int Processor::bfs()
{       
    

    // Struct to hold the city object and custom vector of cities and distances
    for (int cityNum = 0; cityNum < cities.getSize(); cityNum++)
    {
        // Clear values of visited points
        // for (int y = 0; y < height; y++)
        // {
        //     for (int x = 0; x < width; x++)
        //     {
        //         // Set all to non-visited
        //         map[y][x].SetVisited(false);
        //     }
        // }

        // Define a queue
        CustomQueue<BFSPoint *> q;

        // mark as visited
        cities[cityNum]->GetPoint()->SetVisited(true);

        // Push the first city
        BFSPoint *start = new BFSPoint(cities[cityNum]->GetPoint(), 0);

        q.push(start);

        // Loop over the map until the queue is empty
        while (!q.empty()) {
            bool cityFound = false;

            // Get the first point
            BFSPoint *currBfs = q.front();
            Point *curr = currBfs->GetPoint();
            q.pop();

            for (int i = 0; i < cities.getSize(); i++)
            {
                if (cities[cityNum]->GetPoint()->GetX() == curr->GetX() && cities[cityNum]->GetPoint()->GetY() == curr->GetY()) 
                    currBfs->SetDistance(0);
                else if (cities[i]->GetPoint()->GetX() == curr->GetX() && cities[i]->GetPoint()->GetY() == curr->GetY()) {
                    cityFound = true;
                    std::cout << "Distance between " << cities[cityNum]->GetName()->GetString() << " and " << cities[i]->GetName()->GetString() << " = " << currBfs->GetDistance() << std::endl;
                    citiesDistance.push_back(new CityDistance(cities[cityNum], currBfs->GetDistance()));
                    break;
                }
            }

            if (!cityFound) {
                // Loop over the neighbors
                for (BFSPoint *neighbor: getNeighbors(currBfs))
                {
                    if (!neighbor->GetPoint()->GetVisited()) {
                        neighbor->SetDistance(currBfs->GetDistance() + 1);
                        q.push(neighbor);
                        neighbor->GetPoint()->SetVisited(true);
                    }

                }        
            }
            
        }
    }

    
    
}

CustomVector<City *>*Processor::GetCities() {
    return &this->cities;
}

bool Processor::inBounds(Point *pt) {
    return (pt->GetX() >= 0 && pt->GetX() < width && pt->GetY() >= 0 && pt->GetY() < height);
}