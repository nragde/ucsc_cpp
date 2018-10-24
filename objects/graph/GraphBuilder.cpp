/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphBuilder.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphBuilder class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "GraphBuilder.h"

/*----------------------------------------------------------------
WRITE CODE HERE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
            DFS called from graph
Build graph from string
-----------------------------------------------------------------*/
void Graph::buildGraph(const vector<string>& s) {
  //WRITE CODE
  GraphBuilder b(*this, s);
}

// https://stackoverflow.com/questions/6576109/initialising-reference-in-constructor-c
GraphBuilder::GraphBuilder(Graph& gin, const vector<string>& sin):
_g(gin), _s(sin){
    _build_graph();
}

void GraphBuilder::_build_graph(){
    // enum Type { NONE = 0, UNDIRECTED, DIRECTED, WEIGHTED_UNDIRECTED, WEIGHTED_DIRECTED };
    GraphType::Type type = _g.getType();
    // If it's undirected, we need to make sure to write info in both directions
    bool is_undirected = false;
    if(type == GraphType::Type::UNDIRECTED or type == GraphType::Type::WEIGHTED_UNDIRECTED){
        is_undirected = true;
    }
    //Weights are either 0 or the expected weight
    double weight = 0;
    //Need to determine if we're reading strings by 2 or 3 (if weighted)
    int mod_step = 2;
    if(type == GraphType::Type::WEIGHTED_UNDIRECTED or type == GraphType::Type::WEIGHTED_DIRECTED){
        mod_step = 3;
    }
    //Create nodes and edges and put into our graph _g
    unsigned long info_size = _s.size();
    for(int x = 0; x < info_size/mod_step; ++x){
        //Take out the strings of information from the inputted info string
        int from_ind = x*mod_step;
        int to_ind = from_ind + 1;
        int weight_ind = from_ind + 2;
        string from = _s[from_ind];
        string to = _s[to_ind];
        string sweight = "0";
        if(mod_step == 3){
            sweight = _s[weight_ind];
        }
        weight = _g.string2double(sweight);
        
        // Add nodes if necessary and get the num value of each
        int from_num = _attempt_to_add_node(from);
        int to_num = _attempt_to_add_node(to);
        
        //Add the edges
        // For directed, from->to should be added to from's fan-out
        //               to->from should be added to to's fan-in
        _g.createEdge(from_num, to_num, weight, true);
        _g.createEdge(to_num, from_num, weight, false);
        //If undirected, we also need to add edges the other way as well
        // BUT, not if it's a self-loop (as this would make it seem like a double loop!)
        if(is_undirected and from_num != to_num){
            _g.createEdge(from_num, to_num, weight, false);
            _g.createEdge(to_num, from_num, weight, true);
        }
    }
}

int GraphBuilder::_attempt_to_add_node(const string& node_name){
    int node_num = _g.graphHasNode(node_name);
    //If it already exists, just return the number
    if(node_num == -1){
        //The node doesn't exist yet, so add it
        node_num = _g.insertOrFind(node_name, false);
    }
    return node_num;
}

//EOF





