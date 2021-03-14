#include <stdio.h>
#include "graph.h"

//Only issue currently is you have to redefine the global variable V within graph.h in order to change the size of the 2d array that defines the graph.
//I assume there is a better way to do this such as using vectors that can be dynamically allocated, but I ran out of time and resources to try to figure out
//A better solution. Hopefully this does well enough to demonstrate I understand the concepts! This is the running code, but I also attached some of my other attempts.
//And here are the links to my resources I used to help me finish this project!
int main() 
{ 
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	shortest_path(graph, 0); 

	return 0; 
} 
