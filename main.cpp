#include <iostream>
#include <fstream>
#include <sstream>
#include "src/graph.h"
#include "src/salesMan.h"

using namespace std;

int main(int argc, char* argv[]){
  Graph* g1 = new Graph();

  //Use archive input to create graph
  ifstream file("samples/dij15.txt");
  string line;
  getline(file, line);
  stringstream ss(line);

  int i;
  ss >> i;

  for(int j=0; j<i; j++){
    g1->createGraph(new Node(to_string(j)));
  }

  int lineCounter = 0;
  int columnCounter = 1;
  while(getline(file, line)){
    int value;
    int auxiliaryColumnCounter = columnCounter;
    stringstream ss1(line);
    while(ss1 >> value){
      g1->nodeVector[lineCounter]->createEdge(value, g1->nodeVector[auxiliaryColumnCounter]);
      g1->nodeVector[auxiliaryColumnCounter]->createEdge(value, g1->nodeVector[lineCounter]);
      auxiliaryColumnCounter++;
    }
    columnCounter++;
    lineCounter++;
  }

  SalesMan* s1 = new SalesMan(g1);

  //s1->startedNodeIndex = 0;
  //vector<int> vector;
  //int j = 1;
  //cout << "name: " << s1->graph->nodeVector[0]->name << " value: " << s1->graph->nodeVector[0]->vVector[j].value << " going to name: " << s1->graph->nodeVector[0]->vVector[j].nextNode->name << endl;
  s1->startAlgorithm(0);
  cout << "The value is: " << s1->minorPath << endl;

  return 0;
}
