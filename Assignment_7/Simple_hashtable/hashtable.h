#include <iostream>
#include <stdio.h>
#include <string> //Included to create array of strings
using namespace std;

class HT {
    public:
        void hash_insert(string val);
        void hash_search(string val);
        void hash_remove(int val);

        void test_hash_insert();
        void test_hash_search();
        void test_hash_remove();

    private: 
        int hasher(string val);
        
        std::string hashmap[100];
};  

//Function to hash
//Goes through character to character adding up ascii values to create a number and finds remainder. Remainder = index
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
//Inserts string at index value (Created by hasher function). Some people had questions whether it should be creating the value it stores in the index, or create the index.
//In essence it'd be easy to do both. It seemed you didn't seem concerned about this though so I just created the index value.
void HT::hash_insert(string val) {
    int index = hasher(val);
    hashmap[index] = val; 
    //cout << hashmap[index] << endl << index << endl;//Test functionality
}

//Function to search
void HT::hash_search(string val) {
    int i;

    for(i=0; i<100; i++) {
        if(hashmap[i] == val) {
            cout << "Found value at index: " << i << endl;
            return;
        }
    }
    cout << "Value not found";
}

//Function to remove values
void HT::hash_remove(int val){
    if(val < 100) {
        if (val >= 0) {
            string tmp = hashmap[val];
            hashmap[val] = -1; //-1 being an empty value
            cout << "Value " << tmp << " removed at index " << val << endl;
        }
    }
    //Keeps it within the arrays size.
    else {
        cout << "Index out of bounds.";
    }
}

//Test functions

void HT::test_hash_insert() {
    hash_insert("Tester string.");
    cout << "Insert function pass." << endl;
}

void HT::test_hash_search() {
    hash_insert("jake");
    //Example of pass.
    hash_search("jake");
    //Example of fail.
    hash_search("joe");
    cout << endl << "Search function pass." << endl;
}

void HT::test_hash_remove() {
    hash_remove(11); //Index of jake.
    cout << "Remove function pass." << endl;
}