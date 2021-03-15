#include <limits.h> 
#include <stdio.h>
#include <iostream>

using namespace std;

//Adjusts vertices in graph
#define V 5 

class graph
{
private:
	int mindist_dijkstras(int dist[], bool visited[]);

public:
	int mat[V][V];
	void create_matrix();
	void add_edge(int source, int dest, int weight);
	void shortest_path(int graph[V][V], int src);
	void mst(int mat_1[V][V]);
	void printer(int graph[V][V]);

	//Tests
	void test_functions(int graph[V][V], int source);
};
//Creates blank matrix so that edges can be included
void graph::create_matrix() {
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++) {
			mat[i][j] = 0;
		}
	}
}

//Adds bidirectional edges at [source][dest] & [dest][source]
void graph::add_edge(int source, int dest, int weight) {
	mat[source][dest] = weight;
    mat[dest][source] = weight;
}

//Finds min value out of unvisited vertices
int graph::mindist_dijkstras(int dist[], bool visited[]) 
{ 
	//Set min value for evaluation of dist array and bool array
	int min = INT_MAX;
	int min_index; 

	for (int v = 0; v < V; v++) {
		if (visited[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index; 
} 

//Finds shortest path to all nodes in graph.
void graph::shortest_path(int graph[V][V], int source) 
{ 
	//Holds shortest paths from source
	int dist[V];
	//Holds visited values
	bool visited[V];

	//Initializes all distances as infinity and sets the visited set to be false as nothing has ran.
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX, visited[i] = false; 
	}
	//Source distance is always 0 as it has no where to travel.
	dist[source] = 0; 

	for (int i = 0; i < V - 1; i++) { 
		//Find min distance
		int min = mindist_dijkstras(dist, visited); 
		//Sets index to be true at min value
		visited[min] = true; 

		for (int j = 0; j < V; j++) {
			//Updates path from u to v by checking conditions, if not part of set (false), and graph[min][j] and the connecting edges don't equal infinity, and the
			//created edge for that current spot dist(first one is 0) + graph(0,0) < dist[0] = 0, therefore 0 + 0 is not less than 0, so move on to next. 
			if (!visited[j] && (graph[min][j] && dist[min] != INT_MAX) && (dist[min] + graph[min][j] < dist[j])) {
				dist[j] = dist[min] + graph[min][j]; 
			}
		}
	} 

	//Prints shortest paths
	cout << "Vertex \t\t Distance from Source" << endl; 
	for (int i = 0; i < V; i++) {
		cout << i << "\t\t" << dist[i] << endl;
	}
} 

void graph::mst(int mat_1[V][V]) {
	//Visited array that keeps track of variables that have already been checked for min
	bool visited[V];
	//Min tree starts at arbitrary value
	int source = 0;
	//These variables I use to control how the information is passed around. Vital part of algorithm as it holds old and new information to keep my if statements/loops in tact
	int tmp = source;
	int old_tmp = source;
	int new_tmp;
	//Switches from i - tmp after first round so it can go through path.
	bool first_round = true;
	//Total weight of min span tree
	int totalweight = 0;

	for (int i=0;i<V;i++) {
		visited[i] = false;
	}

	visited[source] = true;

	for (int i=0;i<V-1;i++){
		int min = INT_MAX; //Resets to infinity every iteration of finding next min value
		if (first_round != false) { //Checks round count
			for (int j=0; j<V;j++) {
				if (mat_1[i][j] != 0 && visited[j] != true) { //Checks if it's not 0 and if it hasn't been visited
					if (mat_1[i][j] <= min) { //If true and value is less than current min, set min to value and store the column value in tmp var
						min = mat_1[i][j];
						new_tmp = j;
						first_round = false;
					}
				}
			}
		}
		else {
			for (int j=0; j<V;j++) {
				if (mat_1[tmp][j] != 0 && visited[j] != true) {
					if (mat_1[tmp][j] <= min) { ////If true and value is less than current min, set min to value and store the column value in tmp var
						min = mat_1[tmp][j];
						new_tmp = j;
					}
				}

			}
		}
		cout << tmp << "--" << new_tmp << ": " << min << endl; //Prints value and connecting vertices
		visited[tmp] = true;
		old_tmp = tmp; //Rearranging tmp variables to store so for next iteration they aren't replaced
		tmp = new_tmp;
		totalweight += min; //Creating total weight
	}

	cout << "Total weight of graph is: " << totalweight << endl;
}

void graph::printer(int graph[V][V]) {
	cout << endl;
	//Printing graph for testing : []
	for (int i = 0; i < V; i++){
		cout << endl;
		for (int j = 0; j < V; j++) {
			cout << graph[i][j] << "  ";
		}
	}
	cout << endl;
}

//Testing functions
void graph::test_functions(int graph[V][V], int source) {
	create_matrix();
	shortest_path(graph, source);
	mst(graph);
	printer(graph);
}