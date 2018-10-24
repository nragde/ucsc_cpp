/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphDot.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDot class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef GraphDot_H
#define GraphDot_H

#include "Graph.h"

/*----------------------------------------------------------------
Declaration of GraphDot class
-----------------------------------------------------------------*/
class GraphDot {
public:
//    GraphDot(Graph& gin, const string& f);
//    GraphDot(Graph& gin, const string& fin);
    GraphDot(const Graph& gin, const string& fin);
private:
    const Graph& _g;
    const string& _f;
    
    void _generate_dot_file();
    void _write_line(ofstream& o, const string& s, bool print_newline = true);
    void _write_graph_line(ofstream& o, const string& from, const string& to, const double weight=0, const bool print_label=false);
//    void _build_graph();
//    int _attempt_to_add_node(const string& name);
};


#endif
