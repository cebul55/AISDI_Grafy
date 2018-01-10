//
// Created by Bartosz Cybulski on 08.01.2018.
//

#include "Graph.h"

void Graph::addEdge(int v, int w) {
    /*check if number of node is less than total number of nodes */
    /*check if v & w are different*/
    assert( numberOfNodes_!=0 && v<numberOfNodes_ && w <numberOfNodes_ && v!=w);
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
/*algorytm wybiera każdą krawędź po kolei w ten sposób że z grafu bierze połączenie gdzie pierwsza liczba jest mniejsza od drugiej*/
/*nastepnie w tablicy odwiedzonych zaznacza te dwa wierzchołki jako odwiedzone i wywołuje algorytm DFS dla najmniejszego nieodwiedzonego wierzch*/
/*jeżeli DFS odwiedzi wszystkie krawędzie to znaczy że wybrana krawędź nie jest mostem, w.p.p. jest mostem */
void Graph::findBridges() {
    bool visited[numberOfNodes_];
    int node1, node2 , tmp;
    for(int i = 0 ; i<numberOfNodes_ ; i++){
        for(std::vector<int>::iterator it = edge_[i].begin() ; it != edge_[i].end() ; ++it) {
            if (i < *it) {
                node1 = i;
                node2 = *it;
                for (int j = 0; j < numberOfNodes_; j++) { visited[j] = false; }
                visited[node1] = visited[node2] = true;
                tmp = 0;
                while (visited[tmp] == true) { ++tmp; }
                DFS(tmp, visited);
                for (int k = 0; k < numberOfNodes_; k++) {
                    if (visited[k] == false) {
                        std::cout << node1 << " " << node2 << std::endl;
                        break;
                    }
                }
            }
        }
    }
    std::cout<<std::endl;
}