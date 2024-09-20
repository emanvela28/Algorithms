#include <iostream>
#include <vector>
using namespace std;

int cutRod(const vector<int>& p, int n, vector<int>& a) {
    vector<int> r(n + 1, 0);
    a.assign(n + 1, 0); 

    for (int j = 1; j <= n; j++) {
        int sum = -1;
        for (int i = 1; i <= j; i++) {
            if (sum < p[i] + r[j - i]) {
                sum = p[i] + r[j - i];
                a[j] = i;
            }
        }
        r[j] = sum;
    }
    return r[n];
}


void printCutRodSolution(const vector<int>& a, int n) {
    while (n > 0) {
        cout << a[n] << " ";
        n = n - a[n];
    }
    cout << "-1\n";
}


int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> c; // Will store the lengths of cuts
    int sum = cutRod(p, n, c);

    cout << sum << "\n";
    printCutRodSolution(c, n);

    return 0;
}
