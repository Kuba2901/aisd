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
                    pos->SetX(x);
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
    // Initialize cities
    // this->cities = CustomVector<City*>();


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

bool Processor::inBounds(Point *pt) {
    return (pt->GetX() >= 0 && pt->GetX() < width && pt->GetY() >= 0 && pt->GetY() < height);
}

// BFS function to find distances between chosen points
int Processor::bfs(Point* start, Point* end)
{
    // Initialize visited array
    bool** visited = new bool*[height];
    for (int i = 0; i < height; i++)
    {
        visited[i] = new bool[width];
        for (int j = 0; j < width; j++)
        {
            visited[i][j] = false;
        }
    }

    // Initialize queue
    CustomQueue<Point> q;
    q.push(*start);
    visited[start->GetY()][start->GetX()] = true;
    start->SetVisited(true);

    // Initialize distance array
    CustomVector<CustomVector<int>> dist(height, CustomVector<int>(width, -1));
    dist[start->GetY()][start->GetX()] = 0;

    // BFS loop
    while (!q.empty())
    {
        Point curr = q.front();
        q.pop();

        // Check if we've reached the end point
        if (curr.GetX() == end->GetX() && curr.GetY() == end->GetY())
        {
            std::cout << "Distance from (" << start->GetX() << "," << start->GetY() << ") to (" 
                      << end->GetX() << "," << end->GetY() << "): " << dist[end->GetX()][end->GetY()] << std::endl;
            break;
        }

        // Iterate over neighboring points
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int x = curr.GetX() + dx[i];
            int y = curr.GetY() + dy[i];

            // Check if neighboring point is valid and not visited
            if (x >= 0 && x < height && y >= 0 && y < width && map[y][x].isTraversable() && !visited[y][x])
            {
                Point neighbor = map[x][y];
                q.push(neighbor);
                visited[y][x] = true;
                neighbor.SetVisited(true);
                dist[y][x] = dist[curr.GetY()][curr.GetX()] + 1;
            }
        }
    }

    // Free memory
    // for (int i = 0; i < height; i++)
    // {
    //     delete[] visited[i];
    // }
    // delete[] visited;
}

CustomVector<City *>*Processor::GetCities() {
    return &this->cities;
}