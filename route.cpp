#include "route.h"

void Route::shortestRoute(Graph &city,int source,int destination)
{
    city.dijkstra(source,destination);
}