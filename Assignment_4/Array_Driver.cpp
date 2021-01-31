#include <iostream>

using namespace std;

//Adds values into lists, using some kind of temp variable.

int* array_add(int n, int input_value, int arr[], int position) {
    int i;

    n++;

    for (i=n; i>=position; i--) {
        arr[i] = arr[i-1];

    }

    arr[position - 1] = input_value;

    return arr;
}

int* array_remove(int n, int arr[], int position) {
    int i;

    int *new_arr = new int[n];

    for (i = position - 1; i < n; i++) {
        arr[i] = arr[i+1];

    }
    

    std::copy(arr, arr+std::min(n, n-1), new_arr );
    delete [] arr;
    arr = new_arr;



    return arr;

}



void array_position(int *arr) {
    cout << arr[3];


}

int main(int argc, char** argv) {
    int i, position, n;
    int input_value;
    int choice_value;
    int add_value;
    int remove_value;
    int show_value;
    int index_value;

    cout << "Set array size: " << endl;
    cin >> n;

    int *num_array = new int[n] { };

    //Initialize array
    for (i = 0; i < n; i++) 
        num_array[i] = i + 1; 
    
    cout << "Would you like to add to, remove from, or show the contents of the array? (0 = Add, 1 = Remove, 2 Show)";
    cin >> choice_value;

    switch (choice_value)
    {
    case 0:
        cout << "Enter value to add to array: ";
        cin >> add_value;
        cout << "Enter index to add value to array: ";
        cin >> index_value;
        
        array_add(n, add_value, num_array, index_value);

        break;
    case 1:
        //cout << "Enter value to remove to array: ";
        //cin >> remove_value;
        cout << "Enter index to remove value from array: ";
        cin >> index_value;
        
        array_remove(n, num_array, 4);
        break;

    case 2:
        cout << "Enter index of array to show: ";
        cin >> show_value;
        break;

    default:
        break;
    }

    //Print array after
    for (i = 0; i < n + 1; i++) {
        cout << num_array[i] << " "; 
    }

    //array_remove(n, num_array, 4);

    cout << endl <<  "Goodbye.";

    return 0;
}