#include <iostream>
#include <stdio.h>
#include <string>
#include <list> //Now that we have learned these data structures I opted to get familiar with the list library. I find this to be a lot more fun than using a tree.
using namespace std;

class HT {
    public:
        void hash_insert(string val);
        void hash_search(string val);
        void hash_remove(string val);

        void test_hash_insert();
        void test_hash_search();
        void test_hash_remove();

    private: 
        int hasher(string val);
        
        list<string> *ht = new list<string>[100]; //Constructing 100 linked lists. Did some research on differences between the list and vector libraries.
        //https://thispointer.com/difference-between-vector-and-list-in-c/
};  

//Function to hash
//Same hash function as previous hash table.
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
//Essentially same as before.
void HT::hash_insert(string val) {
    int index = hasher(val);
    ht[index].push_back(val); //Pushes value to back of list.
}

//Function to search
void HT::hash_search(string val) {
    int index = hasher(val);
    list<string>::iterator i; 
    for (i = ht[index].begin(); i != ht[index].end(); i++) { 
      if (*i == val) {
        cout << "Found: " << *i << endl;
        return;
        }
    }
    cout << "Not found " << val << endl;
}

//Function to remove values
//Very similar to search function! Except it erases value.
void HT::hash_remove(string val){
    int index = hasher(val);
    list<string>::iterator i; 
    for (i = ht[index].begin(); i != ht[index].end(); i++) { 
      if (*i == val) {
        cout << "Deleting: " << *i << endl;
        ht[index].erase(i);
        cout << "Erased " << val << endl << endl;
        return;
        }
    }
    cout << "Not found.";
}

//Tests

void HT::test_hash_insert() {
    hash_insert("Tester string.");
    cout << "Insert function pass." << endl << endl;
}

void HT::test_hash_search() {
    hash_insert("jake");
    //Example of pass.
    hash_search("jake");
    //Example of fail.
    hash_search("joe");
    cout << endl << "Search function pass." << endl << endl;
}

void HT::test_hash_remove() {
    hash_remove("jake");
    cout << "Remove function pass." << endl << endl;
}