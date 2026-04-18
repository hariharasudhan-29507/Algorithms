
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Global variables to match your Java structure
vector<int> x;
int n;

// Function to check if a queen can be placed at row k, column i
bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        // Check column and diagonals
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Function to print the solution in both vector and matrix format
void printSolution() {
    static int solutionCount = 0;
    cout << "\nSolution " << ++solutionCount << ":" << endl;

    // Print Vector
    cout << "Solution set: ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    // Print Matrix
    cout << "Matrix:" << endl;
    for (int i = 1; i <= n; i++) {       // Rows
        for (int j = 1; j <= n; j++) {   // Columns
            if (x[i] == j) {
                cout << "Q ";
            } else 
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

// Recursive function to solve N-Queens
void nQueens(int k) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printSolution();
            } else {
                nQueens(k + 1);
            }
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    // Initialize vector with size n+1 (to maintain 1-based indexing)
    x.resize(n + 1);

    cout << "Solutions:" << endl;
    nQueens(1);

    return 0;
}
