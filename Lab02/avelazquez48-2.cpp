#include <iostream>
using namespace std;
#include <vector>


void merge (vector<int>& array, int left, int right, int middle) {
    
    // Starting points for the sub arrays
    int s1 = middle - left + 1;
    int s2 = right - middle;

    // Temory vectors to hold values
    vector<int> leftsub(s1);
    vector<int> rightsub(s2);

    // Copying values over to the temporary arrays
    for (int i = 0; i < s1; i++) {
        leftsub[i] = array[left + i];
    }
    for (int j = 0; j < s2; j++) {
        rightsub[j] = array[middle + 1 + j];
    }

    // Merge the temporary arrays
    int i = 0, j = 0, k = left;
    // Checking bounds and choose while indicie to fill array with.
    while (i < s1 && j < s2) {
        if (leftsub[i] <= rightsub[j]) {
            array[k] = leftsub[i];
            i++;
        } else {
            array[k] = rightsub[j];
            j++;
        }
        k++;
    }

    // Auto filling the array with any numbers remaining for left sub array
    while (i < s1) {
        array[k] = leftsub[i];
        i++;
        k++;
    }
    
    // Auto filling the array with any numbers remaining for right sub array
    while (j < s2) {
        array[k] = rightsub[j];
        j++;
        k++;
    }

}

void mergesort (vector<int>& array, int left, int right) {

    // Finding the mid point to create subarrays.
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Recursivley calling the merge sort function
        mergesort(array, left, middle);
        mergesort(array, middle + 1, right);

        merge(array, left, right, middle);

    }
}

int main () {
    
    int size; 
    cin >> size;

    // Allowing user to input numbers until their input is equal to the declared size
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Calling merge sort on the givven array
    mergesort(array, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << ";";
        }
    }
    cout << ";";

    return 0;
}
