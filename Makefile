Graph: main.o Graph.o
	g++ main.o Graph.o -o Graph

main.o: main.cpp InputMode.h
	g++ -c -Wall main.cpp 

Graph.o: Graph.cpp Graph.h InputMode.h
	g++ -c -Wall Graph.cpp