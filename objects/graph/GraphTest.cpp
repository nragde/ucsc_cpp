/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphTest.cpp.cpp

On linux:
g++ ../util/util.cpp GraphDot.cpp GraphBuilder.cpp GraphDfs.cpp Graph.cpp GraphTest.cpp
valgrind a.out
==83493== All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test graph object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "Graph.h"


/*----------------------------------------------------------------
ONLY CHANGE HERE: Where do you want to write your graph dot file?
-----------------------------------------------------------------*/
#ifdef _WIN32
const char* dotFileBase = "C:\\junk\\";
#else
const char* dotFileBase = "/home/jag/junk/";
#endif

/*----------------------------------------------------------------
            YOU CANNOT CHANGE ANYTHING BELOW
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Declaration of GraphTest class
-----------------------------------------------------------------*/
class GraphTest {
public:
  GraphTest() {
    _testBed();
  }
private:
  void _testBed();
  const vector<string> _getGraphSpec(int i);
  void _testGraphRepresentation();
  void _u1();
  void _uw1();
  void _d1();
  void _dw1();
  void _testDFS();
};

/*----------------------------------------------------------------
Various graphs
-----------------------------------------------------------------*/
const vector<string> GraphTest::_getGraphSpec(int i) {
  const vector<string>  g0 = {
    "1","2",
    "1","3",
    "1","4",
    "2","5",
    "2","4",
    "3","6",
    "3","4",
    "4","5",
    "4","7",
    "7","5",
    "7","6",
    "6","4",
  };

  const vector<string> g1 = {
    "0", "5",
    "2", "4",
    "2", "3",
    "2", "5",
    "1", "2",
    "0", "1",
    "3", "4",
    "3", "5",
    "0", "2",
  };
  const vector<string> g2 = {
    "1", "2", "6.2",
    "1", "3", "1.2",
    "1", "4", "5",
    "2", "3", "5.2",
    "2", "5", "3.2",
    "3", "4", "5",
    "3", "5", "4",
    "3", "6", "4",
    "4", "6", "2",
    "5", "6", "6",
  };
  const vector<string> g3 = {
    "A", "B",
    "E", "F",
    "E", "D",
    "C", "E",
    "B", "C",
    "D", "B",
  };
  const vector<string> g4 = {
    "A", "C", "12.8",
    "A", "D", "60",
    "B", "A", "10",
    "C", "B", "20",
    "C", "D", "32.9",
    "E", "A", "7",
  };
  const vector<string> g5 = {
    "1", "2",
    "1", "3",
    "2", "4",
    "3", "4",
    "4", "5",
  };
  const vector<vector<string>>  g = { g0,g1,g2,g3,g4,g5 };
  return g[i];
}

/*----------------------------------------------------------------
undirected graph
-----------------------------------------------------------------*/
void GraphTest::_u1() {
  GraphType::Type t = GraphType::Type::UNDIRECTED;
  const vector<string> s = _getGraphSpec(0);
  Graph g(t);
  g.buildGraph(s);
  assert(g.getnumV() == 7) ;
  assert(g.getnumE() == 24) ;
  string fname = string(dotFileBase) + string("0.dot");
  g.writeDot(fname);
}

/*----------------------------------------------------------------
Weighted undirected graph
-----------------------------------------------------------------*/
void GraphTest::_uw1() {
  GraphType::Type t = GraphType::Type::WEIGHTED_UNDIRECTED;
  const vector<string> s = _getGraphSpec(2);
  Graph g(t);
  g.buildGraph(s);
  assert(g.getnumV() == 6) ;
  assert(g.getnumE() == 20) ;
  string fname = string(dotFileBase) + string("2.dot");
  g.writeDot(fname);
}

/*----------------------------------------------------------------
undirected graph
-----------------------------------------------------------------*/
void GraphTest::_d1() {
  GraphType::Type t = GraphType::Type::DIRECTED;
  const vector<string> s = _getGraphSpec(3);
  Graph g(t);
  g.buildGraph(s);
  assert(g.getnumV() == 6) ;
  assert(g.getnumE() == 6) ;
  string fname = string(dotFileBase) + string("3.dot");
  g.writeDot(fname);
}

/*----------------------------------------------------------------
Weighted directed graph
-----------------------------------------------------------------*/
void GraphTest::_dw1() {
  GraphType::Type t = GraphType::Type::WEIGHTED_DIRECTED;
  const vector<string> s = _getGraphSpec(4);
  Graph g(t);
  g.buildGraph(s);
  assert(g.getnumV() == 5) ;
  assert(g.getnumE() == 6) ;
  string fname = string(dotFileBase) + string("4.dot");
  g.writeDot(fname);
}

/*----------------------------------------------------------------
Test various graph representation in memory
-----------------------------------------------------------------*/
void GraphTest::_testGraphRepresentation() {
  _u1();
  _uw1();
  _d1();
  _dw1();
  cout << "ALL Graph representation PASSED. Attach GraphBuider.h, GraphBuilder.cpp and all dot files as pdf\n";
  cout << "Do not attach dot files\n";
}

/*----------------------------------------------------------------
Testdfs
-----------------------------------------------------------------*/
void GraphTest::_testDFS() {
  {
    const vector<string> e = {
      "1","2",
      "1","3",
      "2","4",
      "3","4",
      "4","5",
    };

    GraphType::Type t = GraphType::Type::DIRECTED;
    Graph g(t);
    g.buildGraph(e);
    string fname = string(dotFileBase) + string("dfs1.dot");
    g.writeDot(fname);

    string s1 = "1"; //Starting city
    vector<string> ans;
    bool cycle = false;
    int work = 0;
    g.dfs("Example 1", s1, cycle, work, ans);
    //g.dfs("",s1,cycle,work,ans) ; //This will not print
  }
  {
    //Directed graph with cycle
    const vector<string> e = {
      "0","1",
      "0","2",
      "1","3",
      "2","3",
      "3","4",
      "4","2",
    };

    GraphType::Type t = GraphType::Type::DIRECTED;
    Graph g(t);
    g.buildGraph(e);
    string fname = string(dotFileBase) + string("dfs2.dot");
    g.writeDot(fname);

    string s1 = "0"; //Starting city
    vector<string> ans;
    bool cycle = false;
    int work = 0;
    g.dfs("Example 2", s1, cycle, work, ans);
  }

  {
    //UnDirected graph with cycle
    const vector<string> e = {
      "1","0",
      "1","2",
      "0","3",
      "0","2",
      "3","4",
    };
    GraphType::Type t = GraphType::Type::UNDIRECTED;
    Graph g(t);
    g.buildGraph(e);
    string fname = string(dotFileBase) + string("dfs3.dot");
    g.writeDot(fname);

    string s1 = "1"; //Starting city
    vector<string> ans;
    bool cycle = false;
    int work = 0;
    g.dfs("Example 3", s1, cycle, work, ans);
    //g.dfs("",s,cycle,work,ans) ; //This will not print
  }

  {
    //UnDirected graph with NO cycle
    const vector<string> e = {
      "1","2",
      "1","4",
      "1","3",
    };
    GraphType::Type t = GraphType::Type::UNDIRECTED;
    Graph g(t);
    g.buildGraph(e);
    string fname = string(dotFileBase) + string("dfs4.dot");
    g.writeDot(fname);

    string s1 = "1"; //Starting city
    vector<string> ans;
    bool cycle = false;
    int work = 0;
    g.dfs("Example 4", s1, cycle, work, ans);
    //g.dfs("",s,cycle,work,ans) ; //This will not print
  }

  {
    //Directed weighted Acyclic graph
    const vector<string> e = {
      "0","2","5",
      "0","3","3",
      "0","1","14",
      "1","6","6",
      "1","4","7",
      "2","5","2",
      "2","4","3",
      "3","2","11",
      "3","4","7",
      "3","1","6",
      "4","6","5",
      "5","6","7",
    };
    GraphType::Type t = GraphType::Type::WEIGHTED_DIRECTED;
    Graph g(t);
    g.buildGraph(e);
    string fname = string(dotFileBase) + string("dfs5.dot");
    g.writeDot(fname);

    string s1 = "0"; //Starting city
    vector<string> ans;
    bool cycle = false;
    int work = 0;
    g.dfs("Example 5", s1, cycle, work, ans);
  }
  cout << "ALL DFS PASSED. Attach GraphDfs.h, GraphDfs.cpp and output of the program\n";
}
/*----------------------------------------------------------------

-----------------------------------------------------------------*/
void GraphTest::_testBed() {
  _testGraphRepresentation();
  //_testDFS();  //Next assignment.
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int main() {
  GraphTest b;
  return 0;
}
