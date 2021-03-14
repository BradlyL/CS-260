#include <limits.h> 
#include <stdio.h>
#include <iostream>

#define V 5


using namespace std;

int main () {
    int val;
    
    int matrix[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j< V;j++) {
            cout << "Enter value to enter into matrix: " << endl;
            cin >> val;
            matrix[i][j] = val;
        }
    }

    return 0;
}