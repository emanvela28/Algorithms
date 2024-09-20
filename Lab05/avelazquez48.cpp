#include <iostream>
using namespace std;
#include <cstdlib>


int Partition(int Array[], int p, int r) {
    int x = Array[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (Array[j] <= x) {
            i++;
            swap(Array[i], Array[j]);
        }
    }
    swap(Array[i + 1], Array[r]);
    return (i + 1);
}

int RandomizedPartition(int Array[], int p, int r) {
    int i = (p + rand() % (r - p + 1));
    swap(Array[r], Array[i]);
    return Partition (Array, p, r);
}

void RandomizedQuickSort(int Array[], int p, int r) {
    if (p < r) {
        int q = RandomizedPartition(Array, p, r);
        RandomizedQuickSort(Array, p, q - 1);
        RandomizedQuickSort(Array, q + 1, r);
    }
}

void print(int Array[], int r) {
    for (int i = 0; i < r; i++) {
        cout << Array[i] << ";";
    }
}

int main () {

    int n;
    cin >> n;

    int Array[n];
    for (int i = 0; i < n; i++) {
        cin >> Array[i];
    }

    RandomizedQuickSort(Array, 0, n - 1);
    print(Array, n);

    return 0;
}