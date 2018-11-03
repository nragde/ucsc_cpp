/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphDfs.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDfs class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "GraphDfs.h"

/*----------------------------------------------------------------
                         DFS called from graph
-----------------------------------------------------------------*/
void Graph::dfs(const char* t, const string& s, bool& cycle, int& work, vector<string>& ans) {
    //WRITE CODE
    GraphDfs d(*this, t, s, cycle, work, ans);
    
}

// Description of inputs
//string s1 : the starting node (real name)
//vector<string> ans : a vector that should list topology, when appropriate
//bool cycle : true if there's a cycle in the loop, false if there isn't
//int work: number of "hops" you must make to perform the DFS
GraphDfs::GraphDfs(Graph& gin, const char* tin, const string& sin, bool& cycle_in, int& work_in, vector<string>& ans_in):
_g(gin), _t(tin), _s(sin), _cycle(cycle_in), _work(work_in), _ans(ans_in) {
    //Do the DFS work
    _perform_dfs();
    //If valid, do the DFS assert check
    // Valid if we're a directed graph, and there's no cycle
    GraphType::Type g_type = _g.getType();
    if((g_type == GraphType::Type::DIRECTED or g_type == GraphType::Type::WEIGHTED_DIRECTED) and not _cycle){
        bool proper_topology = _verify_dfs_topology();
        assert(proper_topology);
    }
    //Print if the first string is not empty!
    if(*_t){
        cout << _t << endl;
        cout << "Num Vertices = " << _g.getnumV() << endl;
        cout << "Num Edges = " << _g.getnumE() << endl;
        cout << "Work done = " << _work << endl;
        cout << "Has Cycle = ";
        if(_cycle){ cout << "YES" << endl;}
        else{ cout << "NO" << endl;}
        cout << "DFS topological order = ";
        for(int i = 0 ; i < _ans.size(); ++i){
            cout << _ans[i] << " ";
        }
        if(_cycle){
            cout << endl << "This order has no meaning" << endl;
        }
        if((g_type == GraphType::Type::DIRECTED or g_type == GraphType::Type::WEIGHTED_DIRECTED) and not _cycle){
            //We will only get here if it's a valid DFS check and the assert passed when the method was initially run
            cout << endl << "dfs assert passed" << endl;
        }
        
        cout << endl;
    }
}


//Private methods
void GraphDfs::_perform_dfs(){
    // This should be done to make sure we're in a known state
    _set_to_unvisited();
    int start_node = _g.graphHasNode(_s);
    assert(start_node != -1);
    //Recursively perform the DFR in a helper function
    _dfs_r(start_node);
}

//We're "coloring" the nodes as we visit them
//  Green - unvisited (i.e. initial); note that this is NOT a default value of 0
//  Blue - visited, but not all of its fanouts have been visited
//  Red - visited, and all of its fan outs have been visited as well
void GraphDfs::_dfs_r(int node_num){
    //Increment our work counter
    ++_work;
    //If it's green, make it blue since we've visited
    if(_g.getTemp(node_num) == NodeColor::GREEN){
        _g.setTemp(node_num, NodeColor::BLUE);
        //This node is visited, so visit all of its fanout nodes next
        int num_fanouts = _g.numFanout(node_num);
        for(int f = 0; f < num_fanouts; ++f){
            int fanout_node = _g.getNodeFanout(node_num, f);
            //Do the same thing for each fanout node
            _dfs_r(fanout_node);
        }
        //We've visited all fanouts, so we should now be RED
        _g.setTemp(node_num, NodeColor::RED);
        //Add to the topology vector
        string node_real_name = _g.getRealName(node_num);
        _ans.push_back(node_real_name);
    }
    //If it's red, no need to visit so do nothing
    else if(_g.getTemp(node_num) == NodeColor::RED){
    }
    //If it's blue, we have a cycle
    else if(_g.getTemp(node_num) == NodeColor::BLUE){
        _cycle = true;
    }
}


void GraphDfs::_set_to_unvisited(){
    for(int i = 0; i < _g.getnumV(); ++i){
        _g.setTemp(i, NodeColor::GREEN);
    }
}

bool GraphDfs::_verify_dfs_topology(){
    bool proper_top = true;
    //Make a vector that's as long as the number of nodes
    vector<bool> have_visited;
    for(int i = 0; i < _g.getnumV(); ++i){
        have_visited.push_back(false);
    }
    //Now go through the order, backwards (use std::reverse from algorithm.h)
    reverse(_ans.begin(), _ans.end());
    //Now go from the beginning to the end, looking at fan ins
    // If our order is correct, all fanins should be true when we visit a node
    for(int n = 0; n < _ans.size(); ++n){
        //Get the node num
        int cur_node = _g.graphHasNode(_s);
        assert(cur_node != -1);
        //Look at all fanins
        int num_fanins = _g.numFanin(cur_node);
        for(int f = 0; f < num_fanins; ++f){
            int fanin_node = _g.getNodeFanin(cur_node, f);
            if(not have_visited[fanin_node]){
                proper_top = false;
                break;
            }
            
        }
    }
    //Reverse it back to the original
    reverse(_ans.begin(), _ans.end());
    
    return proper_top;
}

//EOF

