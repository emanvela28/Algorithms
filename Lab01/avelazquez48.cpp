
#include <iostream>
using namespace std;

int main() {
    int size;
    //cout << "Input" << endl;

    // taking user input and assigning it to size then creating array using the size
    cin >> size;
    int array[size];

    //taking users inputs based on the size they declared
    for (int i = 0; i < size; i++) {
        cin >> array[i];
        // if (i == size - 1) {
        //     cout << "\nOutput" << endl;
        // }
    }

    //insertion sort set i eqaul to the second term assuming that the first is sorted
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        
        // nest the loop and 
        while (array[j] > key && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;

        for (int k = 0; k <= i; k++) {
            cout << array[k];
                if (k < i) {
                    cout << ";";

            }
        }

        cout << ";" << endl;
    }

    return 0;
}