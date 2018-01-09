//
// Created by Bartosz Cybulski on 08.01.2018.
//

#include "Graph.h"

void Graph::addEdge(int v, int w) {
    assert( v<nodes_ || w < nodes_ );
    edge_[v].push_back(w);
    edge_[w].push_back(v);
}

void Graph::writeEdges() {
    for(int i = 0 ; i < nodes_ ; i++){
        std::cout<<i<<"->";
        for( auto it = edge_[i].begin() ; it != edge_[i].end() ; ++it) {
            std::cout<<" "<<*it;
        }
        std::cout<<std::endl;
    }
}

int Graph::DFS(int node) {
    //todo DFS
}