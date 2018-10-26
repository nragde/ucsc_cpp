/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: Graph.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has Graph class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef Graph_H
#define Graph_H

#include "../util/util.h"

/*----------------------------------------------------------------
All forward declarations
-----------------------------------------------------------------*/
class node;
class edge;
class GraphTest;

/*----------------------------------------------------------------
Declaration of node class
-----------------------------------------------------------------*/
class GraphType {
public:
  enum Type { NONE = 0, UNDIRECTED, DIRECTED, WEIGHTED_UNDIRECTED, WEIGHTED_DIRECTED };
};

/*----------------------------------------------------------------
Declaration of node class
-----------------------------------------------------------------*/
class node {
public:
  node(int name) :_name(name), _temp(0) {}
  ~node() {}
  //Let node do shallow copy and equal
  //Functions
  void setTemp(int x) { _temp = x; }
  int getTemp() const { return _temp; }
  int name() const { return _name; }
  int numfanouts() const { return int(_fanouts.size()); }
  int numfanins() const { return int(_fanins.size()); }

  const edge& getFaninEdge(int i) const {
    assert(i >= 0 && i < _fanins.size());
    return _fanins[i];
  }
  const edge& getFanoutEdge(int i) const {
    assert(i >= 0 && i < _fanouts.size());
    return _fanouts[i];
  }
  void addFanoutEdge(const edge& u) {
    _fanouts.push_back(u);
  }
  void addFaninEdge(const edge& u) {
    _fanins.push_back(u);
  }
private:
  int _name;
  int _temp;
  vector<edge> _fanins;
  vector<edge> _fanouts;
};

/*----------------------------------------------------------------
Declaration of edge class
-----------------------------------------------------------------*/
class edge {
public:
  edge(int o, double c) :_other(o), _cost(c) {}
  ~edge() {}
  //Let edge  do shallow copy and equal
  int other() const { return _other; }
  double cost() const { return _cost; }
  void setCost(double d) { _cost = d; }
private:
  int _other;
  double _cost;

  //Functions

};

/*----------------------------------------------------------------
Declaration of Graph class
-----------------------------------------------------------------*/
class Graph {
public:
  Graph(GraphType::Type t) :_numV(0), _numE(0), _type(t) {}
  ~Graph() {}
  Graph(const Graph& from) = delete;
  Graph& operator=(const Graph& from) = delete;

  double string2double(const string& s) const {
    std::string::size_type sz;     // alias of size_t
    return std::stod(s, &sz);
  }

  int getnumV() const { return _numV; }
  int getnumE() const { return _numE; }
  int getNodeName(int i) const {
    const node& n = _getNode(i);
    return n.name();
  }
  const string& getRealName(int i) const {
    assert(i >= 0 && i < _nodeNames.size());
    return _nodeNames[i];
  }
  const string& getNodeRealName(int i) const {
    int x = getNodeName(i);
    return getRealName(x);
  }
  int numFanout(int i) const {
    const node& n = _getNode(i);
    int s = n.numfanouts();
    return s;
  }
  int numFanin(int i) const {
    const node& n = _getNode(i);
    int s = n.numfanins();
    return s;
  }
  void setTemp(int i, int v) {
    assert(i >= 0 && i < getnumV());
    node& n = _nodes[i];
    n.setTemp(v);
  }
  int getTemp(int i) const {
    const node& n = _getNode(i);
    return n.getTemp();
  }
  int getNodeFanout(int n, int e) const {
    const edge& ei = _getNodeFanoutEdge(n, e);
    return ei.other();
  }
  int getNodeFanin(int n, int e) const {
    const edge& ei = _getNodeFanInEdge(n, e);
    return ei.other();
  }
  void addFanoutEdge(int i, const edge& u) {
    assert(i >= 0 && i < getnumV());
    node& n = _nodes[i];
    n.addFanoutEdge(u);
  }
  void addFaninEdge(int i, const edge& u) {
    assert(i >= 0 && i < getnumV());
    node& n = _nodes[i];
    n.addFaninEdge(u);
  }
  double getNodeFanoutEdgeWeight(int n, int e) const {
    const edge& ei = _getNodeFanoutEdge(n, e);
    return ei.cost();
  }

  GraphType::Type getType() const { return _type; }
  int graphHasNode(const string& s) const;
  int insertOrFind(const string& s, bool mustbethere);
  void createEdge(int from, int to, double w, bool fanout);

  /*   FUNCTIONS THAT YOU WILL BE WRITING. Remove {} */
  void buildGraph(const vector<string>& s) ;
  void writeDot(const string& f) const ;
  void dfs(const char* t, const string& s, bool& cycle, int& work, vector<string>& ans);
private:
  int _numV; // Number of nodes
  int _numE; // Number of edges
  GraphType::Type _type; //Graph type
  vector<string> _nodeNames; //Node names given by the user
  map<string, int> _hm; //String to Integer mapping
  vector<node> _nodes; //Array of all nodes

  //Functions
  const node& _getNode(int i) const {
    assert(i >= 0 && i < getnumV());
    const node& n = _nodes[i];
    return n;
  }

  const edge& _getNodeFanoutEdge(int n, int e) const {
    const node& no = _getNode(n);
    int size = numFanout(n);
    return no.getFanoutEdge(e);
  }
  const edge& _getNodeFanInEdge(int n, int e) const {
    const node& no = _getNode(n);
    int size = numFanin(n);
    return no.getFaninEdge(e);
  }
};

#endif

//EOF
