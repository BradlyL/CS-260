#include <stdio.h>
#include <iostream>

using namespace std;

class graph {
    public:
        int add_vertex();
        void new_edge(int source, int dest, int weight);
        void shortest_path(int graph[5][5], int source);
        void mst();
        void printer();
        void create_matrix(int size);
        
    private:
        struct path {
                int value = -1;
                path* next = NULL; //Creates path
            };

        struct verteces {
                bool checked = false; //IF checked by algo
                int cost = 999; //Sets cost to "infinity" unless has touched node
                path* previous = NULL; //Keeps track of past vertex checked
        };        
        int mindistance(int tweight[], bool visited[]);
        path* mat[100][100]; //Double array for matrix
        verteces* vert[100]; //Array of edges
        int mat_size = 0; //Current size of matrix - add_vertex() adds 1 to this each time (expanding)
};

int graph::mindistance(int tweight[], bool visited[]) {
    int minimum = 999;
    int index, i;

    for (i=0; i<5; i++) {
        if (visited[i] == false && tweight[i] < minimum){
            minimum = tweight[i];
            index = i;
        }
    }
    return index;
}

//Creates matrix of x size (Max 100)
void graph::create_matrix(int size) {
    int i, j;

    for (i=1;i<=size;i++) {
        for (j=1;j<=size;j++) {
                mat[i][j] = new path; //Creates 100 possible vertex matrix (Not created yet)
        }
    }

    for (i=0;i<size;i++){
        vert[i] = new verteces; //Creates 100 empty edges
    }
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

//Shows shortest path from source node
void graph::shortest_path(int graph[5][5], int source) {
    int i, j;
    int tweight[5];
    bool visited[5];


    for(int i = 0; i<5; i++)
	{
		tweight[i] = 999;
		visited[i] = false;	
	}
    
    tweight[source] = 0;
   
    for(int i = 0; i<5; i++)                           
	{
		int m=mindistance(tweight,visited); // vertex not yet included.
		visited[m]=true;// m with minimum distance included in Tset.
		for(int i = 0; i<5; i++)                  
		{
			// Updating the minimum distance for the particular node.
			if(!visited[i] && graph[m][i] && tweight[m]!=INT_MAX && tweight[m]+graph[m][i]<tweight[i])
				tweight[i]=tweight[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<5; i++)                      
	{ //Printing
		char str=65+i; // Ascii values for pritning A,B,C..
		cout<<str<<"\t\t\t"<<tweight[i]<<endl;
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
            cout << mat[i][j]->value << "   ";
        }
        cout << "\n";
    }
    cout << "\n";
}