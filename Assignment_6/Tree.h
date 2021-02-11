#include <iostream>
#include "node.h"
using namespace std;

//test_add
void test_add() {
    
}
//test_remove
void test_remove() {

}

//test_traverse


//Add function
int add_tree(int input){
    node *new_node = new node;

    if (new_node->value > input) {
        if (new_node->right == nullptr) {
            new_node->right->value = input;
        }
        
    }
    printf("%i ", new_node->right->value);
}
//Remove function
int remove_tree(){

}
//Possible traversal function