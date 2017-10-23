CC = g++
FLAGS = -std=c++11

.PHONY: prim dijkstra

program: main.cpp src/*.cpp Makefile
	$(CC) $(FLAGS) main.cpp src/*.cpp -o program

run:
	./program
