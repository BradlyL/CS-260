#include <iostream>
#include "node.h"
using namespace std;


//From my understanding so far it seems that using classes is a great way to structure your code and to make certain things solidified into your code. 

class BST {
    public:
        node* insert(int input, node* root); //Insert values.
        node* remove_tree(int input, node* root); //Delete values.
    private:
        node* create_node(int input);
        node* minimum(node* root);
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


//Public remove function. Works recursively to find value to delete and re arrange sub tree.
node* BST::remove_tree(int input, node* root){
    if (root == NULL) {
        return root; //Case where tree is empty.
    } else if (input < root->value) { //Runs recursively on left side to find value.
        root->left = remove_tree(input, root->left);
    } else if (input > root->value) { //Runs recursively on right side to find value.
        root-> right = remove_tree(input, root->right);
    } else {
        if (root->left == NULL & root->right == NULL) { //If it has no child then it frees the memory of node.
            delete root;
            root = NULL;
            return root;
        } else if (root->left == NULL) { //In case of one child to the right.
            node* tmp = root;
            root = root->right;
            delete tmp;
        } else if (root->right == NULL) { //In case of one child to the left.
            node* tmp = root;
            root = root->left;
            delete tmp;
        } else { //In case that node to be deleted has children nodes.
            node* tmp = minimum(root->right);
            root->value = tmp->value;
            root->right = remove_tree(tmp->value, root->right);
        }
    }

}

node* BST::minimum(node* root){
    node* current = root;

}
