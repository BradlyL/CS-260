#include <iostream>
#include "node.h"
using namespace std;

class BST {
    public:

        void insert(int input);
    private:
        void add_tree(int input, node *new_node);
        void remove_tree(int input);
        node *root;

};

//Public insert function, this allows us to access our private data within the class. In this all inputs are put through it to determine if it's created the root, or adding
//onto additional nodes.
void BST::insert(int input) {
    if (root !=nullptr) {
        add_tree(input, root);
    } else {
        root = new node;
        root->value = input;
        root->left = nullptr;
        root->right = nullptr;
    }
}

//This is the private function that creates the tree.
void BST::add_tree(int input, node *new_node){
    if (input < new_node->value) {
        if (new_node->left == nullptr) {
            add_tree(input, new_node->left);
        } else {
            new_node->left = new node;
            new_node->left->value = input;
            new_node->left->left = nullptr;
            new_node->left->right = nullptr;

        }
    } else {
        if (new_node->right == nullptr) {
            add_tree(input, new_node->right);
        } else {
            new_node->right = new node;
            new_node->right->value = input;
            new_node->right->left = nullptr;
            new_node->right->right = nullptr;
        }
    }
}   


//Remove function
void BST::remove_tree(int input){
}
