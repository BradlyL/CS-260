#include "Graph.h"

int main (){
    //Adjacency Matrix used to define graph.
    graph g;
	int graph[5][5]={
		{0, 10, 20, 0, 0},
		{10, 0, 0, 50, 10},
		{20, 0, 0, 20, 33},
		{0, 50, 20, 0, 20},
		{0, 10, 33, 20, 0}};    
    g.create_matrix(7); //Create matrix of size 7
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.new_edge(1, 2, 5);
    g.new_edge(1, 3, 4);
    g.new_edge(2, 4, 11);
    g.new_edge(3, 6, 12);
    g.new_edge(4, 5, 5);
    g.new_edge(5, 6, 6);
    g.new_edge(6, 7, 8);
    g.printer();
    g.shortest_path(graph,1); //Find shortest path from 1-7
    //Graph created (node) - weight
    // (1) -------- (2)
    // |      5      |11
    // |4            |
    // |            (4)
    // |    12       |5
    // (3) -- (5)    |
    //      |  \6    |
    //     8|     \ (5)
    //     (7)

    return 0;
}