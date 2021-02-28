#include <iostream>
#include <stdio.h>
using namespace std;

class HT {
    public:
        void hash_insert(int value);
        void hash_search(int value);
        int hash_remove(int value);

        void test_hash_insert();
        void test_hash_search();
        void test_hash_remove();
    private: 
        int hasher(int hash_val);
};

//Function to hash_1
int HT::hasher(int hash_val) {

    return hash_val;
}

//Function to insert
void HT::hash_insert(int value) {
}

//Function to search
void HT::hash_search(int value) {
}

//Function to possibly remove values
int HT::hash_remove(int value){

    return value;
}

//Tests

void HT::test_hash_insert() {
}

void HT::test_hash_search() {
}

void HT::test_hash_remove() {
}