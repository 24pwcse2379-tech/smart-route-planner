#include "graph.h"

// Constructor
Graph::Graph(int v)
{
    vertices = v;
    adj.resize(vertices);
    locationNames.resize(vertices);
}

// Set location name
void Graph::setLocationName(int index, string name)
{
    if (index >= 0 && index < vertices)
    {
        locationNames[index] = name;
    }
}

// Print shortest path
void Graph::printPath(vector<int>& parent, int node)
{
    if (node == -1)
        return;

    printPath(parent, parent[node]);

    cout << locationNames[node] << " ";
}

// Add a road
void Graph::addEdge(int u, int v, int weight)
{
    if (u < 0 || u >= vertices || v < 0 || v >= vertices)
    {
        cout << "Invalid location number!\n";
        return;
    }

    if (weight < 0)
    {
        cout << "Distance cannot be negative!\n";
        return;
    }

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

// Remove a road
void Graph::removeEdge(int u, int v)
{
    if (u < 0 || u >= vertices || v < 0 || v >= vertices)
    {
        cout << "Invalid location!\n";
        return;
    }

    adj[u].erase(
        remove_if(adj[u].begin(), adj[u].end(),
                  [v](pair<int, int> edge)
                  {
                      return edge.first == v;
                  }),
        adj[u].end());

    adj[v].erase(
        remove_if(adj[v].begin(), adj[v].end(),
                  [u](pair<int, int> edge)
                  {
                      return edge.first == u;
                  }),
        adj[v].end());

    cout << "\nRoad blocked successfully.\n";
}

// Display graph
void Graph::displayGraph()
{
    cout << "\n========== CITY MAP ==========\n";

    for (int i = 0; i < vertices; i++)
    {
        cout << locationNames[i] << " --> ";

        if (adj[i].empty())
        {
            cout << "No Roads";
        }
        else
        {
            for (auto edge : adj[i])
            {
                cout << "[" << locationNames[edge.first]
                     << " | " << edge.second << " km] ";
            }
        }

        cout << endl;
    }

    cout << "==============================\n";
}

// Dijkstra Algorithm
void Graph::dijkstra(int source, int destination)
{
    if (source < 0 || source >= vertices ||
        destination < 0 || destination >= vertices)
    {
        cout << "\nInvalid Source or Destination!\n";
        return;
    }

    vector<int> distance(vertices, INT_MAX);
    vector<int> parent(vertices, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int current = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        if (currentDistance > distance[current])
            continue;

        for (auto edge : adj[current])
        {
            int neighbour = edge.first;
            int weight = edge.second;

            if (distance[current] + weight < distance[neighbour])
            {
                distance[neighbour] = distance[current] + weight;
                parent[neighbour] = current;

                pq.push({distance[neighbour], neighbour});
            }
        }
    }

    if (distance[destination] == INT_MAX)
    {
        cout << "\nNo path exists between "
             << source << " and " << destination << ".\n";
    }
    else
    {
        cout << "\n========== SHORTEST ROUTE ==========\n";

        cout << "Source       : " << locationNames[source] << endl;
        cout << "Destination  : " << locationNames[destination] << endl;
        cout << "Total Cost   : " << distance[destination] << " km\n";

        cout << "Path         : ";

        printPath(parent, destination);

        cout << endl;
        cout << "====================================\n";
    }
}