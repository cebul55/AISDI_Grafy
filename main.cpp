#include <iostream>
#include "Graph.h"
#include "InputMode.h"

int main(int argc, char ** argv) {
    InputMode input(argc, argv);
    Graph g(input.getNumberOfNodes(),input.getNumberOfEdges(),input.getEdgesVector());
    g.findBridges();
    return 0;
}