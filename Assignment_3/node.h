//Separate file creating node struct and front and back of queue.

struct node {
    int value;
    node *next;
};

node *front = NULL;
node *back = NULL;