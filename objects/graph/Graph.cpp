/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: Graph.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has Graph class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
        CANNOT ADD or Change anything in this file
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "Graph.h"

/*----------------------------------------------------------------
if s is there return small number
-----------------------------------------------------------------*/
int Graph::graphHasNode(const string& s) const {
  auto it = _hm.find(s);
  if (it != _hm.end()) {
    //Is there
    int n = it->second;
    return n;
  }
  return -1;
}

/*----------------------------------------------------------------
if s is there return small number
else put in hash and return small number
-----------------------------------------------------------------*/
int Graph::insertOrFind(const string& s, bool mustbethere) {
  int si = graphHasNode(s);
  if (si != -1) {
    return si;
  }
  if (mustbethere) {
    assert(0);
  }
  //Not in the hash. Insert in map
  _hm[s] = _numV;
  //Given an unique number you can get name
  _nodeNames.push_back(s);
  //add a node
  node n(_numV);
  //store i nodes
  _nodes.push_back(n);
  _numV++;
  assert(_hm.size() == _numV);
  assert(_nodes.size() == _numV);
  return (_numV - 1); //added at position numV
}

/*----------------------------------------------------------------
fanout true: create a fanout edge from from to to
fanout false: create a fanin edge from from to to
-----------------------------------------------------------------*/
void Graph::createEdge(int from, int to, double w, bool fanout) {
  assert(getNodeName(from) == from);
  edge e(to, w);
  if (fanout == true) {
    _numE++;
    addFanoutEdge(from, e);
  } else {
    addFaninEdge(from, e);
  }
}



