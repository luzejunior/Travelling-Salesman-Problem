# Travelling-Salesman-Problem

The travelling salesman problem (TSP) is a famous mathematical problem which answers the following question: *"Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?"*. It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science. - *Wikipedia.*

This is a Travelling-Salesman-Problem algorithm implementation for graphs using C++ and it is part of an assignment for APA (Analise de Projetos de Algoritmos) class at UFPB (Universidade Federal da Paraiba).

## Requirements:

- Ubuntu 17.04 or above.
- MacOSX 10.12 or above.
- GCC 6.3.0 or above.
- CLang 900.0.37 or above.

## Compiling:

To compile you have to simple invoke make on your console:
```sh
$ make
```

## Running:

To run you have only to invoke make run on your console:
```sh
$ make run
```

You can change the sample archive by modifying the `samples/pcv10.txt` at **Main.cpp**.
```sh
41 ifstream file("samples/pcv10.txt");
```
You can find some more samples in folder [samples](https://github.com/luzejunior/Travelling-Salesman-Problem/tree/master/samples)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
