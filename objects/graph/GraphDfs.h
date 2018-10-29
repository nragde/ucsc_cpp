/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphDfs.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDfs class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef GraphDfs_H
#define GraphDfs_H

#include "Graph.h"

/*----------------------------------------------------------------
Declaration of GraphDfs class
-----------------------------------------------------------------*/
class GraphDfs {
public:
    //We need to make changes to the Graph (temp val in node), so don't want it const
    GraphDfs(Graph& gin, const char* tin, const string& sin, bool& cycle_in, int& work_in, vector<string>& ans_in);
private:
    Graph& _g;
    const char* _t;
    const string& _s;
    bool& _cycle;
    int& _work;
    vector<string>& _ans;
    bool _print;
    
    enum NodeColor { GREEN = 1, BLUE, RED,};
    
    //Private methods
    void _perform_dfs();
    void _dfs_r(int node_num);
    void _set_to_unvisited();
    bool _verify_dfs_topology();

};

#endif

//eof
