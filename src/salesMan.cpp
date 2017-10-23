/*

Author: Luzenildo de Sousa Batista Junior
E-Mail: luzejunior94@gmail.com

License:

MIT License

Copyright (c) 2017 Luzenildo de Sousa Batista Junior

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "salesMan.h"

SalesMan::SalesMan(Graph* graph){
  this->graph = graph;
}

int SalesMan::calculateMin(vector<int> values){
  int minorValue = 999999999;
  for(int i = 0; i < values.size(); i++){
    if (values[i] < minorValue)
      minorValue = values[i];
  }
  return minorValue;
}

void SalesMan::copyVectors(vector<int> v1, vector<int>* v2, int value){
  for (int i = 0; i < v1.size(); i++){
    if(v1[i] != value)
      (*v2).push_back(v1[i]);
  }
}

int SalesMan::executeAlgorihm(int nodeIndex, vector<int> nextNodesIndex){
  vector<int> *NextNodeMinusOne;
  vector<int> distances;
  int minorLocalPath = 0;

  if(nextNodesIndex.size() == 0){
    return this->graph->nodeVector[this->startedNodeIndex]->vVector[nodeIndex].value;
  }

  for(int i = 0; i < nextNodesIndex.size(); i++){
    copyVectors(nextNodesIndex, NextNodeMinusOne, i);
    distances.push_back(executeAlgorihm(nextNodesIndex[i], *NextNodeMinusOne));
  }

  return minorLocalPath + calculateMin(distances);
}

void SalesMan::startAlgorithm(int starting_with){
  vector<int> indexes;
  this->startedNodeIndex = starting_with;
  for (int i = 0; i < this->graph->nodeVector.size(); i++){
    if(starting_with != i)
      indexes.push_back(i);
  }
  int minorPath = executeAlgorihm(this->startedNodeIndex, indexes);
}
