#include <iostream>
#include <vector>

using namespace std;

int maxCrossingSubarray(const vector<int> &array, int left, int mid, int right) {
    int left_sum = 0;
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = 0;
    sum = 0;
    for (int j = mid + 1; j <= right; j++) {
        sum += array[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    int maxcrossing = left_sum + right_sum;
    return maxcrossing;
}

int maxSubarray(const vector<int>& array, int left, int right) {
    if (left == right) {
        return array[left];
    }

    int mid = (left + right) / 2;

    int left_max = maxSubarray(array, left, mid);
    int right_max = maxSubarray(array, mid + 1, right);
    int cross_max = maxCrossingSubarray(array, left, mid, right);

    if (left_max > cross_max && left_max > right_max) {
        return left_max;
    } else if (cross_max > right_max && cross_max > left_max) {
        return cross_max;
    } else {
        return right_max;
    }
}

int main() {

    int size;
    cin >> size;

    vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    int max_sum = maxSubarray(array, 0, size - 1);
    cout << max_sum;

    return 0;
}
