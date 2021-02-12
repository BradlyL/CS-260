#include <iostream>
using namespace std;
#include "tree.h"

int main(){
    //Initializing our binary search tree class in order to access public functions.
    BST bst;

    node* root = new node();
    
    bst.insert(7, root);
    bst.insert(8, root);

    return 0;
}