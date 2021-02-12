#include <iostream>
#include "node.h"
using namespace std;


//From my understanding so far it seems that using classes is a great way to structure your code and to make certain things solidified into your code. 

class BST {
    public:
        node* insert(int input, node* root); //Insert values.
    private:
        node* create_node(int input);
        void remove_tree(int input);
        node *root = NULL; // Set root to null, and make it unchangeable. So that the tree starts off empty.

};

//Node creation function.

node* BST::create_node(int input) {
    node* new_node = new node();
    new_node->value = input;
    new_node->left = new_node->right = NULL;

    return new_node;
}


//Public insert function, this allows us to access our private data within the class. In this all inputs are put through it to determine if it's created the root, or adding
//onto additional nodes.

node* BST::insert(int input, node* root) {
    if (root == NULL) {
        root = create_node(input);
    } else if (input <= root->value){
        root->left = insert(input, root->left);
        //cout << root->left->value << endl; //test
    } else {
        root->right = insert(input, root->right);
        //cout << root->right->value << endl;  //test
    }
    return root;
}


//Remove function
void BST::remove_tree(int input){
}
