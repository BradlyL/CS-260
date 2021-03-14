#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class graph {
    public:
        void create_matrix(int size);
        int add_vertex();
        void new_edge(int source, int dest, int weight);
        void printer();
        void shortest_path(int source);


    private:
        int mindist(int totalweight[], bool visited[]);
        int mat[100][100];
        int mat_size = 0;
};

//Creates matrix of x size (Max 100)
void graph::create_matrix(int size) {
    int i, j;

    for (i=1;i<=size;i++) {
        for (j=1;j<=size;j++) {
                mat[i][j] = -1;
        }
    }

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
void graph::new_edge(int source, int dest, int weight) {

    mat[source][dest] = weight;
    mat[dest][source] = weight;

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

//Finds minimum value path
int graph::mindist(int totalweight[], bool visited[]) {
    int min = INT_MAX;
    int current_min, i;

    for (i=0;i<7;i++){
        if(visited[i] == false && totalweight[i] <= min) {
            min = totalweight[i];
            current_min = i;
        }
    }
    cout << current_min;
    return current_min;
}

//Find shortest path from source to all created vertices, do this by creating list of untouched variables and running a function over and over to find
//minimum touching path and repeat
void graph::shortest_path(int source) {
    int totalweight[7];
    bool visited[7]; 
    int i, j;

    for (i=0;i<7;i++){
        totalweight[i] = INT_MAX;
        visited[i] = false;
    }

    totalweight[source] = 0;

    for (i=0; i<7;i++) {//possibly
        int min = mindist(totalweight, visited);
        visited[min] = true;
        for (j=0;j<7;j++) {
            if (!visited[j] && mat[min][j] && totalweight[min] != INT_MAX 
                && totalweight[min] + mat[min][j] < totalweight[j]) 
                totalweight[j] = totalweight[min] + mat[min][j];
        }
    }

    cout << ("Vertex \t\t Distance from Source\n"); 
    for (i = 0; i < 7; i++) 
        cout << i << "\t\t" << totalweight[i] <<endl;

}