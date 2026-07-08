#ifndef ROUTE_H
#define ROUTE_H

#include "graph.h"

class Route
{
public:
    static void shortestRoute(Graph &city,int source,int destination);
};

#endif