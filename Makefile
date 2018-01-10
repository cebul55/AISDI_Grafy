a.out: main.o Graph.o
	g++ main.o Graph.o

main.o: main.cpp InputMode.h
	g++ -c -Wall main.cpp 

Graph.o: Graph.cpp Graph.h InputMode.h
	g++ -c -Wall Graph.cpp