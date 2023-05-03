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
    char c;
    int x = 0;
    int y = 0;

    while (c != EOF && y < height)
    {
        c = getchar();

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

    const int num_vertices = cities.getSize();
    
    for (int i = 0; i < num_vertices; i++) {
        vertices.push_back(new Vertex);
        vertices[i]->id = i;
    }

    // Initialize edge_weights array
    int edge_weights[num_vertices][num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            edge_weights[i][j] = 1000000;
            edge_weights[j][i] = 1000000;
        }
    }



    for (int cityNum = 0; cityNum < cities.getSize(); cityNum++)
    {

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

                    // Add to edge weights array
                    edge_weights[cityNum][i] = currBfs->GetDistance();
                    edge_weights[i][cityNum] = currBfs->GetDistance();

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

    
    // Create the adjacency list
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            int weight = edge_weights[i][j];
            if (weight != 0) {
                Edge neighbor = {j, weight};
                vertices[i]->neighbors.push_back(neighbor);
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

PQElement Processor::dijkstra(int source, int destination) {
    // Set up distances and visited array
    const int num_vertices = cities.getSize();
    PQElement distances[num_vertices];
    bool visited[num_vertices];

    for (int i = 0; i < num_vertices; ++i) {
        distances[i].i = 1000000;
    }

    // Set distance to source vertex as 0
    distances[source].i = 0;
    distances[source].ids.push_back(source); // add source ID to its route

    // Create priority queue
    CustomQueue<PQElement> pq;
    pq.push(source);

    // Traverse graph
    while (!pq.empty()) {
        // Get vertex with minimum distance from priority queue
        PQElement u = pq.front();
        pq.pop();

        // Mark vertex as visited
        visited[u.i] = true;

        // Update distance of neighboring vertices
        for (int i = 0; i < vertices[u.i]->neighbors.getSize(); ++i) {
            // iterate over neighbors
            int v = vertices[u.i]->neighbors[i].neighbor;

            // Get the weight of each edge
            int weight = vertices[u.i]->neighbors[i].weight;

            // Get the id of the vertice
            int id = vertices[u.i]->id;

            // Check if theres a shorter route
            if (!visited[v] && distances[u.i].i != 1000000 && distances[u.i].i + weight < distances[v].i) {
                // Update the edge weight
                distances[v].i = distances[u.i].i + weight;
                distances[v].ids.push_back(id);

                for (int k = 0; k < distances[u.i].ids.getSize(); k++)
                {
                    distances[v].ids.push_back(distances[u.i].ids[k]);
                }
                

                PQElement elem{v};
                pq.push(elem);
            }
        }
    }    

    return distances[destination];
}




void Processor::GetFlights() {
    int flightsNum = 0;
    std::cin >> flightsNum;

    for (int i = 0; i < flightsNum; i++)
    {
        CustomString buff;
        std::cin >> buff;


        char *token = std::strtok(buff.GetString(), " ");


        int source = FindCityIndex(token);
        int destination;
        int time;

        int j = 0;

        while (token != nullptr)
        {
            token = std::strtok(nullptr, " ");

            // destination
            if (j == 0)
            {
                destination = FindCityIndex(token);
            } 
            // time
            else {
                time = atoi(token);
            }

            j++;
        }

        vertices[source]->neighbors.push_back(Edge{destination, time});
        vertices[destination]->neighbors.push_back(Edge{source, time});
    }    
}

int Processor::FindCityIndex(char* name) {
    for (int i = 0; i < cities.getSize(); i++)
    {
        if (cities[i]->GetName()->Compare(name) ) {
            return i;
        }
    }

    return NULL;
}


void Processor::GetResults() {
    int questions = 0;
    std::cin >> questions;

    for (int i = 0; i < questions; i++)
    {
        char from[20], to[20];
        int type;

        // Get the input
        std::cin >> from >> to >> type;

        int source = FindCityIndex(from);
        int destination = FindCityIndex(to);

        std::cout << "Source id: " << source << ", destination index: " << destination << std::endl;
        
        PQElement time = dijkstra(source, destination);
        
        std::cout << time.i << " ";

        if (type == 1) {
            std::cout << "Type 1" << std::endl;
            for (int routeElement = 0; routeElement < time.ids.getSize(); routeElement++)
            {
                int id = time.ids[routeElement];
                std::cout << cities[id]->GetName()->GetString() << " ";
            }
            
        }

        std::cout << std::endl;
    }
}