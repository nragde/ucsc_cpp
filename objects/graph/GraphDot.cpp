/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: GraphDot.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has GraphDot class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "GraphDot.h"

/*----------------------------------------------------------------
              write dot called from graph
write dot
-----------------------------------------------------------------*/
void Graph::writeDot(const string& f) const {
    //WRITE CODE HERE
    GraphDot b(*this, f);
}

//#define _TEST_WRITE

GraphDot::GraphDot(const Graph& gin, const string& fin): _g(gin), _f(fin){
    //Whenever an object is instantiated (i.e. when Graph::writeDot is called)
    // we should automatically write out the dot file of said Graph
    _generate_dot_file();
}

void GraphDot::_generate_dot_file(){
    //Create an output file handler and open the filename for writing
    ofstream dotfile;
    dotfile.open(_f);
    
    //Write the opening
    _write_line(dotfile, "digraph g {");
#ifdef _TEST_WRITE
    //This is for debugging - just write out the one line above and close
    // (to make sure file writes work)
    dotfile.close();
#else
    // enum Type { NONE = 0, UNDIRECTED, DIRECTED, WEIGHTED_UNDIRECTED, WEIGHTED_DIRECTED };
    GraphType::Type type = _g.getType();
    //This shouldn't be necessary, but if the GraphType is NONE, we should just hop right out
    // since we otherwise have no idea of how to handle this...
    if(type == GraphType::Type::NONE){
        //Write the end of the file (empty)
        _write_line(dotfile, "}");
        //Close the ofstream
        dotfile.close();
        return;
    }
    
    //Determine whether you need to have directional arrows (default) or not
    string edge_direction = "forward";
    bool is_undirected = false;
    if(type == GraphType::Type::UNDIRECTED or type == GraphType::Type::WEIGHTED_UNDIRECTED){
        is_undirected = true;
        edge_direction = "none";
    }
    //Determine if we're weighted or not (default)
    bool is_weighted = false;
    if(type == GraphType::Type::WEIGHTED_UNDIRECTED or type == GraphType::Type::WEIGHTED_DIRECTED){
        is_weighted = true;
    }
    //Write out the format line of the dot file
    string edge_color = "red";
    string edge_define_line = "edge [dir=" + edge_direction + " color=" + edge_color + "]";
    _write_line(dotfile, edge_define_line);
    
    //Now the header has been written out, so the rest is writing out nodes properly.
    // We only care about fan outs in this way of writing things (since we're writing "from" to "to")
    int total_nodes = _g.getnumV();
    for(int cur_node = 0; cur_node < total_nodes; ++cur_node){
        //Get the acutal name of the node
        string cur_node_name = _g.getNodeRealName(cur_node);
        //Look at each edge/node in the fanouts
        int num_fanout = _g.numFanout(cur_node);
        for(int cur_edge=0; cur_edge < num_fanout; ++cur_edge){
            //If directed, draw all fan outs
            //If undirected, only draw the fan outs whose node # is strictly greater than the current node
            //Get the node at the other end of the edge, the edge weight, and the string name of the node
            int other_node = _g.getNodeFanout(cur_node, cur_edge);
            double edge_weight = _g.getNodeFanoutEdgeWeight(cur_node, cur_edge);
            string cur_edge_name = _g.getNodeRealName(other_node);
            if(is_undirected){
                // We don't want to double up the lines since they're directionless in this case
                // However, we also want to draw if the node values are the same too (self-loops!)
                if(other_node >= cur_node){
                    _write_graph_line(dotfile, cur_node_name, cur_edge_name, edge_weight, is_weighted);
                }
            }
            else{
                //We're directed, so just go ahead and write out every fan out edge
                //  The assumption on the fan outs is that they are all validly added in the bridge
                // (so no duplicates, etc.)
                _write_graph_line(dotfile, cur_node_name, cur_edge_name, edge_weight, is_weighted);
            }
        }
    }
    //Write the end
    _write_line(dotfile, "}");
    //Close the ofstream
    dotfile.close();
#endif
}

//Write a general line to the file
// bool print_newline is OPTIONAL (defaults to TRUE)
void GraphDot::_write_line(ofstream& o, const string& s, bool print_newline){
    //Write the string to the file
    o << s;
    //Print the new line if specified (default is to print new line)
    if(print_newline){
        o << "\n";
    }
}

//Write a node-to-node line to the file
// double weight is OPTIONAL (defaults to 0)
// bool print_label is OPTIONAL (defaults to FALSE)
void GraphDot::_write_graph_line(ofstream& o, const string& from, const string& to, const double weight, const bool print_label){
    //Always write out the "{from} -> {to}" line first
    _write_line(o, from + " -> " + to, false);
    // If we have a weighted graph, label the edges with the proper weights
    // NOTE: We do not skip the label simply if the weight is 0, since it's theoretically possible for a weighted edge to weigh 0
    if(print_label){
        _write_line(o, " [label = ", false);
        //Can't user the helper function in this case because weight is of type double
        o << weight;
        _write_line(o, "]", false);
    }
    //Print the new line at the end of the current line
    _write_line(o, "");
}

//EOF
