#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class graph {
    public:
        int add_vertex();
        void new_edge(int source, int dest);
        void shortest_path(int source, int dest);
        void mst();
        void printer();
        void create_matrix(int size);
        void var_fill();

    private:
        //vector<vector<int>> mat;
        int mat[100][100];
        int mat_size = 0;
        int var[100];
};

void graph::var_fill() {
    int i;
    for (i=1;i<101;i++) {
        var[i] = 0;
    }
}

//Creates matrix of x size (Max 100)
void graph::create_matrix(int size) {
    int i, j;

    for (i=1;i<=size;i++) {
        for (j=1;j<=size;j++) {
                mat[i][j] = -1;
        }
    }
    //return var[size];

}

//Creates new vertices
int graph::add_vertex() {
    int i, j;
    mat_size += 1;

    for (i=1;i<mat_size+1;i++) {
        for (j=1;j<mat_size+1;j++) {
            if (mat[i][j] != 1 | mat[i][j] == -1) {
                mat[i][j] = 0;
            }
            else {
                break;
            }    
        }
    }

    cout << "Constructing... please wait" << "\n";
    printer();
    return mat_size;

}
//Creates edge from vertex to vertex, if same = loop
void graph::new_edge(int source, int dest) {

    mat[source][dest] = 1;
    mat[dest][source] = 1;

}
//Shows shortest path from source node to destination node
void graph::shortest_path(int source, int dest) {
    int i, j;
    for (i=1;i<mat_size+1;i++) {
        for (j=1;j<mat_size+1;j++) {
            if (mat[i][j] == 1) {
                var[i] += 1;
            }
        }    
    }
    for (i=1; i<mat_size+1;i++) {
        cout << var[i] << " ";
    }
}
//Minimum spanning tree shows the minimum distance to get to every vertex.
void graph::mst() {
}
//Going to be used to reprint matrix after every feature.
void graph::printer() {
    int i, j;

    for (i=1;i<=mat_size;i++) {
        for (j=1;j<=mat_size;j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}