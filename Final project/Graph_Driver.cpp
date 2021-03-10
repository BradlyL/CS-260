#include "Graph.h"

int main (){
    //Adjacency Matrix used to define graph.
    graph g;
    g.create_matrix(5);
    g.var_fill();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.new_edge(1, 2);
    g.new_edge(1, 3);
    g.new_edge(2, 4);
    g.new_edge(3, 5);
    g.new_edge(4, 5);
    g.printer();
    g.shortest_path(1,5);

    return 0;
}