#include <iostream>
#include <cassert>
#include "Array_func.h"

using namespace std;

//I have the remove function that doesn't print the whole array to show what it's supposed to do which is make the array smaller.

int main(int argc, char** argv) {
    int i, position, n;
    int input_value;
    int choice_value;
    int add_value;
    int remove_value;
    int index_value;

    cout << "Set array size: ";
    cin >> n;

    int *num_array = new int[n] { };

    cout << endl;

    //Initialize array
    for (i = 0; i < n; i++)  {
        num_array[i] = i + 1; 

    }
    
    //Print array before
    for (i = 0; i < n-1; i++) {
        cout << num_array[i] << " "; 
    }
    
    cout << endl;
    cout << endl;

    cout << "Would you like to add to, remove from, or show the contents of the array? (0 = Add, 1 = Remove, 2 Show, 3 Test) ";
    cin >> choice_value;
    
    //Opted towards switch menu.
    switch (choice_value)
    {
    case 0:

        cout << "Enter value to add to array: ";
        cin >> add_value;
        cout << "Enter index to add value to array: ";
        cin >> index_value;
        
        array_add(n, add_value, num_array, index_value);

        //Print array after
        cout << "Resulting array: ";
        for (i = 0; i < n; i++) {
            cout << num_array[i] << " "; 
        }


        break;
    case 1:

        cout << "Enter index to remove value from array: ";
        cin >> index_value;
        array_remove(n, num_array, index_value);

        //Print array after
        cout << "Resulting array: ";
        for (i = 0; i < n; i++) {
            cout << num_array[i] << " "; 
        }

        break;

    case 2:

        cout << "Enter index of array to show: ";
        cin >> index_value;

        cout << "Position: ";
        array_position(num_array, index_value);

        break;

    case 3:

        cout << "Enter value to insert into test function to add: ";
        cin >> add_value;
        cout << "Enter index to add value to test function, same index will be removed, and then showed: ";
        cin >> index_value;

        test_add(n, add_value, num_array, index_value);

        cout << "Resulting array (Adding): ";

        for (i = 0; i < n; i++) {
            cout << num_array[i] << " "; 
        }

        test_remove(n, num_array, index_value);

        cout << "Resulting array (Removing): ";

        for (i = 0; i < n; i++) {
            cout << num_array[i] << " "; 
        }
        cout << endl << "Position: ";
        test_position(num_array, index_value);

        break;

    default:
        break;
    }


    cout << endl;

    //Print array after
    //cout << "Resulting array: ";
    //for (i = 0; i < n; i++) {
    //    cout << num_array[i] << " "; 
    //}

    cout << endl <<  "Goodbye.";

    return 0;
}