//
// Created by Bartosz Cybulski on 08.01.2018.
//

#ifndef GRAFY_GRAPH_H
#define GRAFY_GRAPH_H

#include <iostream>
#include <vector>
#include <assert.h>

class Graph{
    int nodes_;
    std::vector <int> *edge_;
    int DFS(int node);

public:
    Graph(int nodes) {
        this->nodes_=nodes;
        edge_ = new std::vector<int> [nodes_];
    }
    ~Graph() {
        delete [] edge_;
    }
    void addEdge(int v, int w);
    void writeEdges();
};



#endif //GRAFY_GRAPH_H
