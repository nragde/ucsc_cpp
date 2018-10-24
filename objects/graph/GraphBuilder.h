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
    // Don't really need a destructor, but putting in for clarity
    ~GraphBuilder(){ }
    //Don't want copy or equal operator
    GraphBuilder(const GraphBuilder& builder) = delete;
    GraphBuilder& operator=(const GraphBuilder& builder) = delete;
private:
    //Private variables (both are references, assigned at instantiation)
    Graph& _g;
    const vector<string>& _s;
    
    //Private helper functions, to make the code more readable
    void _build_graph();
    int _attempt_to_add_node(const string& name);
};
#endif


//EOF
