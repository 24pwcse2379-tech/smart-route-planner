#include <iostream>
#include "graph.h"
#include "route.h"

using namespace std;

int main()
{
    int vertices;
    int edges;

    cout << "========== SMART ROUTE PLANNER ==========\n\n";

    cout << "Enter Number of Locations: ";
    cin >> vertices;

    // Validate input
    if (vertices <= 0)
    {
        cout << "Invalid number of locations!\n";
        return 0;
    }

    Graph city(vertices);

    cout << "\nEnter Names of Locations\n";

    for (int i = 0; i < vertices; i++)
    {
        string name;

        cout << "Location " << i << ": ";
        cin >> name;

        city.setLocationName(i, name);
    }

    cout << "\nEnter Number of Roads: ";
    cin >> edges;

    if (edges < 0)
    {
        cout << "Invalid number of roads!\n";
        return 0;
    }

    cout << "\nEnter Roads (Source Destination Distance)\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;

        cout << "Road " << i + 1 << ": ";
        cin >> u >> v >> w;

        city.addEdge(u, v, w);
    }

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "      SMART ROUTE PLANNER\n";
        cout << "====================================\n";
        cout << "1. Display City Map\n";
        cout << "2. Find Shortest Route\n";
        cout << "3. Add New Road\n";
        cout << "4. Block Road\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            city.displayGraph();
            break;
        }

        case 2:
        {
            int source, destination;

            cout << "Enter Source: ";
            cin >> source;

            cout << "Enter Destination: ";
            cin >> destination;

            // You can also use:
            // Route::shortestRoute(city, source, destination);
            city.dijkstra(source, destination);

            break;
        }

        case 3:
        {
            int u, v, w;

            cout << "Enter Source Destination Distance: ";
            cin >> u >> v >> w;

            city.addEdge(u, v, w);

            cout << "Road Added Successfully!\n";

            break;
        }

        case 4:
        {
            int u, v;

            cout << "Enter Road To Block (u v): ";
            cin >> u >> v;

            city.removeEdge(u, v);

            break;
        }

        case 5:
        {
            cout << "\nThank You For Using Smart Route Planner!\n";
            break;
        }

        default:
        {
            cout << "Invalid Choice!\n";
        }
        }

    } while (choice != 5);

    return 0;
}