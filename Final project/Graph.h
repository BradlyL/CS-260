#include <stdio.h>
#include <iostream>

using namespace std;

class graph {
    public:
        int add_vertex();
        void new_edge(int source, int dest, int weight);
        int shortest_path(int source, int dest);
        void mst();
        void printer();
        void create_matrix(int size);

    private:
        struct path {
                int value = -1;
                //path* previous = NULL; //Not necessary to keep track of previous? Irrelevant

                path* next = NULL; //Creates path
            };

        struct verteces {
                bool checked = false; //IF checked by algo
                int cost = INT_MAX; //Sets cost to infinity unless has touched node
                verteces* previous = NULL; //Keeps track of past vertex checked
        };        
        path* mat[100][100]; //Double array for matrix
        verteces* vert[100]; //Array of edges
        int mat_size = 0; //Current size of matrix - add_vertex() adds 1 to this each time (expanding)
};

//Creates matrix of x size (Max 100)
void graph::create_matrix(int size) {
    int i, j;

    for (i=1;i<=size;i++) {
        for (j=1;j<=size;j++) {
                mat[i][j] = new path; //Creates 100 possible vertex matrix (Not created yet)
        }
    }

    //for (i=0;i<size;i++){
    //    vert[i] = new verteces; //Creates 100 empty edges
    //}
}

//Creates new vertices
int graph::add_vertex() {
    int i, j;
    mat_size += 1;

    for (i=1;i<mat_size+1;i++) {
        for (j=1;j<mat_size+1;j++) {
            if (mat[i][j]->value != 1 | mat[i][j]->value == -1) {
                mat[i][j]->value = 0; //Creates vertex
            }
            else {
                break;
            }    
        }
    }

    vert[mat_size] = new verteces; //Creates possible edge

    cout << "Constructing... please wait" << endl;
    printer();
    return mat_size;

}

//Creates edge from vertex to vertex, if same = loop
void graph::new_edge(int source, int dest, int weight) {

    mat[source][dest]->value = weight; //Creates edge between verteces, weight is cost to traverse
    mat[dest][source]->value = weight;

}

//Shows shortest path from source node to destination node
int graph::shortest_path(int source, int dest) {
    int i, j;
    int tmp = source;
    int var = 0;

    if (mat[tmp][dest]->value == 1) {
        var += 1;
        cout << var;
        return 0;
    }

    for (i=1;i<mat_size+1;i++) {
        for (j=1;j<mat_size+1;j++) {
            if (mat[tmp][j]->value != 0 || mat[tmp][j]->value != -1) {

                tmp = j;

                if (tmp == dest) {
                    cout << "Shortest path: " << var << endl;
                    return 0;
                }
                else {
                    var += 1;
                    cout << "\ntmp:" << tmp << endl;
                }
            }
        }    
    }
    return 0;

}
//Minimum spanning tree shows the minimum distance to get to every vertex.
void graph::mst() {
}
//Going to be used to reprint matrix after every feature.
void graph::printer() {
    int i, j;

    for (i=1;i<=mat_size;i++) {
        for (j=1;j<=mat_size;j++) {
            cout << mat[i][j]->value << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
}