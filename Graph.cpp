//
// Created by Bartosz Cybulski on 08.01.2018.
//

#include "Graph.h"

void Graph::addEdge(int v, int w) {
    /*check if number of node is less than total number of nodes */
    /*check if v & w are different*/
    assert( v<numberOfNodes_ && w <numberOfNodes_ && v!=w);
    edge_[v].push_back(w);
    edge_[w].push_back(v);
}

void Graph::writeEdges() {
    for(int i = 0 ; i < numberOfNodes_ ; i++){
        std::cout<<i<<"->";
        for( auto it = edge_[i].begin() ; it != edge_[i].end() ; ++it) {
            std::cout<<" "<<*it;
        }
        std::cout<<std::endl;
    }
}

/* DFS */
void Graph::DFS(int node , bool visited[]) {
    visited[node]=true;
    for(std::vector<int>::iterator it = edge_[node].begin(); it != edge_[node].end() ; ++it ){
        if(!visited[*it])
            DFS(*it,visited);
    }
}