#include "table.h"

class HT {
    public:
        void hash_insert(int value);
        void hash_search(int value);
        int hash_remove(int value);

        void test_hash_insert();
        void test_hash_search();
        void test_hash_remove();

    private: 
        int hasher(string val);
};

//Function to hash
int HT::hasher(string val) {
    int hash=0;
    int index, i;
    int index_length = val.length();

    for(i=0;i<index_length; i++) {
        hash += val[i];
    }

    index = hash % 100;

    return index;
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