#include <iostream>
using namespace std;

//Adds values into lists, by shifting values and placing new value in the designated spot.
int* array_add(int n, int input_value, int arr[], int position) {
    int i;

    //Moves all values to right while enlarging array by 1.
    for (i=n+1; i>=position; i--) {
        arr[i] = arr[i-1];

    }
    //Sets value of inputted index to inputted value.
    arr[position - 1] = input_value;

    return arr;
}

int *array_remove(int n, int arr[], int position) {
    int i;
    //Making n value smaller for the course of the function in order to "make the list smaller".
    n--;
    //Shifting values backwards.
    for (i = position - 1; i < n; i++) {
        arr[i] = arr[i+1];

    }

    //Sets value to -1 to repersent array getting smaller.
    arr[n] = -1;
    
    return arr;

}

//Returns index locations value stays true to visual location.
void array_position(int *arr, int position) {
    cout << arr[position-1];
}

void test_add(int n, int input_value, int arr[], int position){
    array_add(n, input_value, arr, position);
    cout << endl;
}

void test_remove(int n, int arr[], int position){
    array_remove(n, arr, position);
    cout << endl;
}

void test_position(int *arr, int position) {
    array_position(arr, position);
    cout << endl;
}