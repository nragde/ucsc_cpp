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
    _generate_dot_file();
}

void GraphDot::_generate_dot_file(){
    ofstream dotfile;
    dotfile.open(_f);
    
    //Write the opening
    _write_line(dotfile, "digraph g {");
#ifdef _TEST_WRITE
    dotfile.close();
#else
    
    //Determine whether you need to have arrows or not
    string edge_direction = "forward";
    bool is_undirected = false;
    GraphType::Type type = _g.getType();
    if(type == GraphType::Type::UNDIRECTED or type == GraphType::Type::WEIGHTED_UNDIRECTED){
        is_undirected = true;
        edge_direction = "none";
    }
    //Determine if we're weighted or not
    bool is_weighted = false;
    if(type == GraphType::Type::WEIGHTED_UNDIRECTED or type == GraphType::Type::WEIGHTED_DIRECTED){
        is_weighted = true;
    }
    string edge_color = "red";
    string edge_define_line = "edge [dir=" + edge_direction + " color=" + edge_color + "]";
    _write_line(dotfile, edge_define_line);
//    _write_line(dotfile, "edge [dir=", false);
//    _write_line(dotfile, edge_direction, false);
//    _write_line(dotfile, " color=", false);
//    _write_line(dotfile, edge_color, false);
//    _write_line(dotfile, "]");
    
    //Now the header has been written out, so the rest is writing out nodes properly.
    //For directed, just go from node to node and write fan-outs.
    int total_nodes = _g.getnumV();
    for(int cur_node = 0; cur_node < total_nodes; ++cur_node){
        //Get the acutal name of the node
        string cur_node_name = _g.getNodeRealName(cur_node);
        //Look at each edge/node in the fanouts
        int num_fanout = _g.numFanout(cur_node);
        for(int cur_edge=0; cur_edge < num_fanout; ++cur_edge){
            //If directed, draw all fan outs
            //If undirected, only draw the fan outs whose node # is strictly greater than the current node
            //Get the edge
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
                //write the line
                _write_graph_line(dotfile, cur_node_name, cur_edge_name, edge_weight, is_weighted);
            }
//            int getNodeFanout(int n, int e) const
//            double getNodeFanoutEdgeWeight(int n, int e) const {
//            int numFanout(int i) const {


            
        }
    }
    
    
    
    
    //Write the end
    _write_line(dotfile, "}");
    //Close the ofstream
    dotfile.close();
#endif
    
    
    
}

void GraphDot::_write_line(ofstream& o, const string& s, bool print_newline){
    o << s;
    if(print_newline){
        o << "\n";
    }
}

void GraphDot::_write_graph_line(ofstream& o, const string& from, const string& to, const double weight, const bool print_label){
    _write_line(o, from + " -> " + to, false);
//    _write_line(o, " -> ", false);
//    _write_line(o, to, false);
    if(print_label){
        _write_line(o, " [label = ", false);
        o << weight;
        _write_line(o, "]", false);
    }
    //Print the new line
    _write_line(o, "");
    
    
}
//EOF
