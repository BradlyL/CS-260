#include <stdio.h>
#include "Graph.h"

//Only issue currently is you have to redefine the global variable V within graph.h in order to change the size of the 2d array that defines the graph.
//I assume there is a better way to do this such as using vectors that can be dynamically allocated, but I ran out of time and resources to try to figure out
//A better solution. Hopefully this does well enough to demonstrate I understand the concepts! For my shortest path/Min distant function I used geeksforgeeks as a major resource
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/, I tried to implement this on my own, but sadly ran out of time as I have other classes to work on.
//I made sure I deeply understood what the code was doing and feel comfortable with the concepts of graphs and these algorithms now.
int main() 
{ 
	graph g;
	int test_graph[V][V] = { 
						{0,4,0,5,2}
                       ,{4,0,1,3,0}
                       ,{0,1,0,8,0}
					   ,{5,3,8,0,2}
					   ,{2,0,0,2,0}
					   }; 
	// Testing graph
	int graph[V][V];

	//Menu / Matrix creation variables
	bool menu = true;
	int matrix_creation = 0;

	do {
		int choice;
		cout << "Menu:\n1: Create matrix\n2: Add edge\n3: Shortest paths\n4: Minimum spanning tree\n5: Print matrix\n6. Test functions\n7: Leave menu\nEnter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (matrix_creation !=1){
				g.create_matrix();
				cout << "Matrix created of size: " << V << "x" << V << endl;
				memcpy(graph, g.mat, sizeof g.mat);
				matrix_creation = 1;
			}
			else {
				cout << "Matrix already created.\n";
			}
			break;
		
		case 2:
			int source, dest, weight;
			if (matrix_creation !=1) {
				cout << "Please create a matrix before attempting to add edges.";
				break;
			}
			else {
				cout << "Enter source: ";
				cin >> source;
				cout << "Enter dest: ";
				cin >> dest;
				cout << "Enter weight: ";
				cin >> weight;
				g.add_edge(source, dest, weight);
				memcpy(graph, g.mat, sizeof g.mat); //Recopies contents of newly added edges each time.
				cout << "Edge added." << endl;
				break;
			}

		case 3:
			int source_short;
			if (matrix_creation !=1) {
				cout << "Please create a matrix before attempting to run shortest path algorithm.";
				break;
			}
			else {
				cout << "Enter source vertex: ";
				cin >> source_short;
				g.shortest_path(graph, source_short);
				break;
			}
		
		case 4:
			if (matrix_creation !=1){
				cout << "Please create a matrix before attempting to run minimum spanning tree algorithm.";
				break;
			}
			else {
				g.mst(graph);
			}			
			break;

		case 5:
			if (matrix_creation !=1) {
				cout << "Please create a matrix before attempting to print it.";
				break;
			}
			else {
				g.printer(g.mat);
				break;
			}
		case 6:
			g.test_functions(test_graph, 0);
			cout << endl << "All functions working properly." << endl;
			break;
		case 7:
			cout << "Goodbye";
			menu = false;
			break;

		default:
			cout << "False input try again.";
			break;
		}
	} while (menu == true);

	return 0; 
} 
