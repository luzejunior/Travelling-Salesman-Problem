#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph/graph.h"

using namespace std;

int main(int argc, char* argv[]){
  Graph g1;

  //Use archive input to create graph
  ifstream file("Samples/dij10.txt");
  string line;
  getline(file, line);
  stringstream ss(line);

  int i;
  ss >> i;

  for(int j=0; j<i; j++){
    g1.createGraph(new Node(to_string(j)));
  }

  int lineCounter = 0;
  int columnCounter = 1;
  while(getline(file, line)){
    int value;
    int auxiliaryColumnCounter = columnCounter;
    stringstream ss1(line);
    while(ss1 >> value){
      g1.nodeVector[lineCounter]->createEdge(value, g1.nodeVector[auxiliaryColumnCounter]);
      g1.nodeVector[auxiliaryColumnCounter]->createEdge(value, g1.nodeVector[lineCounter]);
      auxiliaryColumnCounter++;
    }
    columnCounter++;
    lineCounter++;
  }

  return 0;
}
