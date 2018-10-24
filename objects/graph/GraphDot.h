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
    //Need both to be const, as the input specifies that the Graph is const
    //  Also, it *should* be a const Graph& because we don't want to change
    //  it since we're only setting up for printing
    GraphDot(const Graph& gin, const string& fin);
    // Don't really need a destructor, but putting in for clarity
    ~GraphDot(){ }
    //Don't want copy or equal operator
    GraphDot(const GraphDot& dotter) = delete;
    GraphDot& operator=(const GraphDot& dotter) = delete;
private:
    //Private variables (both are references, assigned at instantiation)
    const Graph& _g;
    const string& _f;
    
    //Private helper functions, to make the code more readable
    void _generate_dot_file();
    void _write_line(ofstream& o, const string& s, bool print_newline = true);
    void _write_graph_line(ofstream& o, const string& from, const string& to, const double weight=0, const bool print_label=false);
};


#endif
