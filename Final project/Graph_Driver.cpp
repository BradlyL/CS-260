#include <stdio.h>
#include "Graph.h"

//Only issue currently is you have to redefine the global variable V within graph.h in order to change the size of the 2d array that defines the graph.
//I assume there is a better way to do this such as using vectors that can be dynamically allocated, but I ran out of time and resources to try to figure out
//A better solution. Hopefully this does well enough to demonstrate I understand the concepts! This is the running code, but I also attached some of my other attempts.
int main() 
{ 
	graph g;
	/*int graph1[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
	*/

	int graph[V][V];

	bool menu = true;
	int matrix_creation = 0;

	do {
		int choice;
		cout << "Menu:\n1: Create matrix\n2: Add edge\n3: Shortest paths\n4: Minimum spanning tree\n5: Leave menu\n6: Print matrix\nEnter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (matrix_creation !=1){
				g.create_matrix();
				cout << "Matrix created.\n";
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
				cout << "Edge added.";
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
			cout <<"Working: MST"; //g.mst();
			menu = false;
			break;

		case 5:
			cout << "Goodbye";
			menu = false;
			break;
		case 6:
			if (matrix_creation !=1) {
				cout << "Please create a matrix before attempting to print it.";
				break;
			}
			else {
				g.printer();
				break;
			}

		default:
			cout << "No input try again.";
			break;
		}
	} while (menu == true);

	return 0; 
} 
