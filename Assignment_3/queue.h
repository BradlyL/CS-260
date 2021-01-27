#include <iostream>
#include "node.h"

using std::cout;
using std::cin;
using std::endl;

//Checks to see if queue is empty. If there is no node currently created, returns true value.

bool empty_check(){
    if(front == NULL && back == NULL) {
        return true;
    }
    else {
        return false;
    }

}

//Enqueue Function. If no nodes exist it creates front and rear. Otherwise creates new node and moves it.

void enqueue(int input){

    //Creating a node struct called new_node

    node *new_node = new node();

    new_node->value = input;
    new_node->next = NULL;

    if(front == NULL){

        front = new_node;
        back = new_node;

    }

    else {

        back->next = new_node;
        back = new_node;

    }


}

//Dequeue function. Checks to see if queue is empty and than if not checks to see if there is a single node in queue. Then frees current new node and moves it.

void dequeue(){
    if(empty_check()){
        cout << "Queue is empty.";

    }

    else {
        if (front == back) {
            free(front);
            front = NULL;
            back = NULL;
        }

        else {
            node *new_node = front;
            front = front->next;
            cout << "Removing: " << front->value << " value from queue." << endl;
            free(new_node);
            
    }

    }


}

int peek(){
    if (front == NULL) {
        cout << "Queue is empty.";
        return -1;
    }

    else {
        cout <<"Value at front: ";
        return front->value;
    }
}

//These functions runs and tests to see if the function is running properly.

void test_enqueue(int input){
    enqueue(input);

    cout << "Enqueue function running properly.";

}

void test_dequeue(){
    dequeue();

    cout << "Dequeue function running properly.";

}

