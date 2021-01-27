#include <iostream>
#include "queue.h"

using std::cout;
using std::cin;
using std::endl;

int main (int argc, char **argv){
    //Calling functions and tests

    //Change test

    //Tests
    cout << peek();
    cout << endl;
    test_enqueue(5);
    cout << endl;
    test_dequeue();
    cout << endl;


    //Running main functions
    enqueue(1);
    enqueue(2);
    cout << peek();
    cout << endl;
    enqueue(3);
    cout << peek();
    cout << endl;
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    cout << endl;

    return 0;
}