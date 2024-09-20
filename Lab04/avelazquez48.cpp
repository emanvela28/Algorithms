
#include <iostream>
using namespace std;
#include <vector>


void heapify (int arr[], int n, int i) {

    int max  = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) {
        max = left;
    }

    if (right < n && arr[right] > arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    } 
}

void heapsort (int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify (arr, i, 0);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }
}

int main () {

    int input;
    cin >> input;

    int arr[input];
    for (int i = 0; i < input; i++) {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);
    print(arr, n);

    return 0;
}