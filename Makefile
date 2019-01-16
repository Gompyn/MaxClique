CC = g++
CFLAGS = -g -Wall --std=gnu++11

all: main

MaxCliqueFinder.o: MaxCliqueFinder.h MaxCliqueFinder.cpp
	$(CC) $(CFLAGS) -c MaxCliqueFinder.cpp

MaxClique_Sim.o: MaxClique_Sim.cpp MaxCliqueFinder.h
	$(CC) $(CFLAGS) -c MaxClique_Sim.cpp

generate_graph: GenerateGraph.cpp
	$(CC) $(CFLAGS) GenerateGraph.cpp -o generate_graph

main: MaxClique_Sim.o MaxCliqueFinder.o
	$(CC) $(CFLAGS) MaxClique_Sim.o MaxCliqueFinder.o -o main

clean:
	rm -f *~ *.o main

