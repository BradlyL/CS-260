// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <limits.h> 
#include <stdio.h>
#include <iostream>

using namespace std;

//Adjusts vertices in graph
#define V 9 

// This functions helps us find the minimum distance out of current distances not visited
int minDistance(int dist[], bool visited[]) 
{ 
	//Set min value for evaluation of dist array and bool array
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) {
		if (visited[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
			cout << "min: " << min << endl;
			cout << "distv: " << dist[v] <<endl;
		}
	}
	//cout << min_index; // Test
	return min_index; 
} 

//Finds shortest path to all nodes in graph.
void shortest_path(int graph[V][V], int src) 
{ 
	int dist[V]; // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	bool visited[V]; // sptSet[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	//Initializes all distances as infinity and sets the visited set to be false as nothing has ran.
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, visited[i] = false; 

	//Source distance is always 0 as it has no where to travel.
	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) { 
		//Find min distance
		int min = minDistance(dist, visited); 
		cout << "U: " << min << endl;
		//Sets index to be true at min value
		visited[min] = true; 

		for (int v = 0; v < V; v++) {

			//Updates path from u to v by checking conditions, if not part of set (false), and graph[min][v] and the connecting edges don't equal infinity, and the
			//created edge for that current spot dist(first one is 0) + graph(0,0) < dist[0] = 0, therefore 0 + 0 is not less than 0, so move on to next. First loop of
			//min finds there is a connection with edges 1/7.
			if (!visited[v] && (graph[min][v] && dist[min] != INT_MAX) && (dist[min] + graph[min][v] < dist[v])) {
				dist[v] = dist[min] + graph[min][v]; 
				cout << "BOb: " << v <<  endl;
			}
		}
	} 

	//Prints shortest paths
	cout << "Vertex \t\t Distance from Source" << endl; 
	for (int i = 0; i < V; i++) {
		cout << i << "\t\t" << dist[i] << endl;
	}
} 
