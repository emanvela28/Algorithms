#include <iostream>
#include <stdio.h>
#include <vector>
#include <sys/time.h>
#include <climits>

using namespace std;

// Global Variables
vector<vector<int> > m;
vector<vector<int> > s;
int size;

// Function Declaration
void MatrixChainOrder(int *p);
void PrintOptimalParens(int i, int j);

int main() { 
    int *p = NULL;

    // Get number of matrices in the input
    cin >> size;

    // We have one more dimension than matrices
    p = new int[size+1];
    
    // Read each dimension and store in array
    for(int i = 0; i < size+1; i++)
        cin >> p[i];

    // Set up our scratch matrices
    m.clear(); s.clear(); // Make sure that the matrices are empty
    m.resize(size, vector<int>(size, 0));
    s.resize(size, vector<int>(size, 0));

    // Compute matrix chain order through dynamic programming
    MatrixChainOrder(p);
    
    // Output Minimum Number of Computations
    cout << m[0][size-1] << endl;

    // Output Sequence
    PrintOptimalParens(0, size-1);
    cout << endl;

    // Remove allocated space
    delete[] p;
    
    return 0;
}

void MatrixChainOrder(int *p) {
    for (int L = 2; L <= size; L++) {
        for (int i = 0; i < size - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

void PrintOptimalParens(int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        PrintOptimalParens(i, s[i][j]);
        PrintOptimalParens(s[i][j] + 1, j);
        cout << ")";
    }
}
