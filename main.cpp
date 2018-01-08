#include <iostream>
#include "Graph.h"

int main() {
    std::cout << "add graph" << std::endl;
    int n;
    std::cin >> n;
    Graph g(n);
    int a ,b;
    while(n > 0){
        std::cin>>a>>b;
        g.addEdge(a,b);
        --n;
    }
    g.writeEdges();
    return 0;
}