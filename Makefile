CC = g++
FLAGS = -std=c++11

.PHONY: prim dijkstra

program: src/*.cpp Makefile
	$(CC) $(FLAGS) src/*.cpp -o program

run:
	./program
