#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Graph
{
private:
    vector<string> locationNames;
    int vertices;
    vector<vector<pair<int,int>>> adj;

    void printPath(vector<int>& parent, int node);

public:
    Graph(int v);

    void setLocationName(int index, string name);
    void addEdge(int u,int v,int weight);
    void removeEdge(int u,int v);
    void displayGraph();
    void dijkstra(int source,int destination);
};

#endif