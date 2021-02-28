#include "hashtable.h"

int main () {
    HT ht;

    ht.hash_insert("bob");//Remainder 7
    ht.hash_insert("draven");
    ht.hash_insert("k");//Overwrites @ 7
    ht.hash_search("k");//Finds location of value
    ht.hash_remove(40);//Removes value at index 40, in this case "Draven"

    cout << endl << "Tests below" << endl;

    ht.test_hash_insert();
    ht.test_hash_search();
    ht.test_hash_remove();

    return 0;
}

