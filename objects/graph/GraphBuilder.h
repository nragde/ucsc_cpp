/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphBuilder.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphBuilder class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef GraphBuilder_H
#define GraphBuilder_H

#include "Graph.h"

/*----------------------------------------------------------------
Declaration of GraphBuilder class
WRITE CODE
-----------------------------------------------------------------*/
class GraphBuilder {
public:
    GraphBuilder(Graph& gin, const vector<string>& sin);
private:
    Graph& _g;
    const vector<string>& _s;
    
    void _build_graph();
    int _attempt_to_add_node(const string& name);
};
#endif


//EOF
