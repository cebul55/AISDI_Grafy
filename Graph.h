//
// Created by Bartosz Cybulski on 08.01.2018.
//

#ifndef GRAFY_GRAPH_H
#define GRAFY_GRAPH_H

#include <iostream>
#include <vector>
#include <assert.h>

class Graph{
    int numberOfNodes_;
    int numberOfEdges_;
    std::vector <int> *edge_;
public:
    void DFS(int node , bool visited[]);
public:
    Graph(int numberOfNodes , int numberOfEdges, std::vector<int> *edgesVector){
        numberOfNodes_ = numberOfNodes;
        numberOfEdges_ = numberOfEdges;
        edge_ = new std::vector<int> [numberOfNodes_];
        for(int i = 0 ; i < numberOfEdges ; i++)
            addEdge(edgesVector[i][0],edgesVector[i][1]);
        //writeEdges();
    }
    Graph(int nodes, int edges) {
        this->numberOfNodes_=nodes;
        this->numberOfEdges_=edges;
        edge_ = new std::vector<int> [numberOfNodes_];
    }
    ~Graph() {
        delete [] edge_;
    }
    void addEdge(int v, int w);
    void writeEdges();
    void findBridges();
};



#endif //GRAFY_GRAPH_H
