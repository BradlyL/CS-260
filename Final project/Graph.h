#include <limits.h> 
#include <stdio.h>
#include <iostream>

using namespace std;

//Adjusts vertices in graph
#define V 3 

class graph
{
private:
	int mindist(int dist[], bool visited[]);

public:
	int mat[V][V];
	void create_matrix();
	void add_edge(int source, int dest, int weight);
	void shortest_path(int graph[V][V], int src);
	void mst();
	void printer();
};
//Creates blank matrix so that edges can be included
void graph::create_matrix() {
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++) {
			mat[i][j] = 0;
		}
	}
}

void graph::add_edge(int source, int dest, int weight) {
	mat[source][dest] = weight;
    mat[dest][source] = weight;

}

//Finds min value out of unvisited vertices
int graph::mindist(int dist[], bool visited[]) 
{ 
	//Set min value for evaluation of dist array and bool array
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) {
		if (visited[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}
	return min_index; 
} 

//Finds shortest path to all nodes in graph.
void graph::shortest_path(int graph[V][V], int src) 
{ 
	int dist[V]; //Holds shortest paths from source

	bool visited[V]; //Holds visited values

	//Initializes all distances as infinity and sets the visited set to be false as nothing has ran.
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX, visited[i] = false; 
	}
	//Source distance is always 0 as it has no where to travel.
	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) { 
		//Find min distance
		int min = mindist(dist, visited); 
		//Sets index to be true at min value
		visited[min] = true; 

		for (int v = 0; v < V; v++) {

			//Updates path from u to v by checking conditions, if not part of set (false), and graph[min][v] and the connecting edges don't equal infinity, and the
			//created edge for that current spot dist(first one is 0) + graph(0,0) < dist[0] = 0, therefore 0 + 0 is not less than 0, so move on to next. 
			if (!visited[v] && (graph[min][v] && dist[min] != INT_MAX) && (dist[min] + graph[min][v] < dist[v])) {
				dist[v] = dist[min] + graph[min][v]; 
			}
		}
	} 

	//Prints shortest paths
	cout << "Vertex \t\t Distance from Source" << endl; 
	for (int i = 0; i < V; i++) {
		cout << i << "\t\t" << dist[i] << endl;
	}
} 

void graph::printer() {
	cout << endl;
	//Printing graph for testing : []
	for (int i = 0; i < V; i++){
		cout << endl;
		for (int j = 0; j < V; j++) {
			cout << mat[i][j] << "  ";
		}
	}
	cout << endl;
}