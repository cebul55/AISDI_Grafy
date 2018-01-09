#include <iostream>
#include "Graph.h"
#include "InputMode.h"

int main(int argc, char ** argv) {
    InputMode input(argc, argv);
    Graph g(input.getNumberOfNodes(),input.getNumberOfEdges(),input.getEdgesVector());
    bool visited[input.getNumberOfNodes()];
    for(int i = 0 ; i<input.getNumberOfNodes();i++)
        visited[i]=false;
    g.DFS(0,visited);
    for(int i = 0 ; i<input.getNumberOfNodes();i++) {
        if (visited[i] == false){
            std::cout << "Graf nie jest spojny";
            return 0;
    }
    }
    std::cout<<"Graf jest spojny";
    /*std::cout << "add graph" << std::endl;
    int n;
    std::cin >> n;
    Graph g(n);
    int a ,b;
    while(n > 0){
        std::cin>>a>>b;
        g.addEdge(a,b);
        --n;
    }
    g.writeEdges();*/
    return 0;
}