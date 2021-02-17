#include <iostream>
using namespace std;
#include "tree.h"

int main(){
    //Initializing our binary search tree class in order to access public functions.
    BST bst;

    node* root = new node();
    
    //Test Functions
    bst.test_insert();
    bst.test_remove();

    bst.insert(7, root);
    bst.insert(9, root);
    bst.insert(15, root);
    bst.insert(6, root);
    bst.insert(5, root);
    bst.insert(1, root);
    bst.insert(4, root);
    bst.remove(4, root);
    bst.remove(6, root);
    bst.remove(7, root);

    return 0;
}