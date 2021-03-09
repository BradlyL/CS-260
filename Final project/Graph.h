#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class graph {
    public:
        void add_vertex(int value);
        void new_edge(int source, int dest);
        void shortest_path(int source, int dest);
        void mst();

    private:
        void printer();
};

//Creates new vertices
void graph::add_vertex(int value) {
}
//Creates edge from vertex to vertex, if same = loop
void graph::new_edge(int source, int dest) {
}
//Shows shortest path from source node to destination node
void graph::shortest_path(int source, int dest) {
}
//Minimum spanning tree shows the minimum distance to get to every vertex.
void graph::mst() {
}
//Going to be used to reprint matrix after every feature.
void graph::printer() {
}