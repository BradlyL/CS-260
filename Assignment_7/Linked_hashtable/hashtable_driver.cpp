#include "hashtable.h"

int main () {
    HT ht;

    ht.hash_insert("bob");//Remainder 7
    ht.hash_insert("draven");
    ht.hash_insert("k");
    ht.hash_search("draven");//Finds value in location
    ht.hash_search("k");
    ht.hash_remove("k");
    ht.hash_search("k");

    cout << endl << "Tests below:" << endl << endl;

    ht.test_hash_insert();
    ht.test_hash_search();
    ht.test_hash_remove();

    return 0;
}

