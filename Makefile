CC = g++
CFLAGS = -g -Wall -pthread
STD11 = --std=gnu++11
STD17 = --std=gnu++17
all: main test

MaxCliqueFinder.o: MaxCliqueFinder.h MaxCliqueFinder.cpp
	$(CC) $(CFLAGS) $(STD11) -c MaxCliqueFinder.cpp

MaxClique_Sim.o: MaxClique_Sim.cpp MaxCliqueFinder.h
	$(CC) $(CFLAGS) $(STD11) -c MaxClique_Sim.cpp

Test.o: Test.cpp MaxCliqueFinder.h
	$(CC) $(CFLAGS) $(STD17) -c Test.cpp

generate_graph: GenerateGraph.cpp
	$(CC) $(CFLAGS) $(STD11) GenerateGraph.cpp -o generate_graph

main: MaxClique_Sim.o MaxCliqueFinder.o
	$(CC) $(CFLAGS) $(STD11) MaxClique_Sim.o MaxCliqueFinder.o -o main

test: Test.o generate_graph
	$(CC) $(CFLAGS) $(STD17) MaxCliqueFinder.o Test.o -o test

clean:
	rm -f *~ *.o main generate_graph test

