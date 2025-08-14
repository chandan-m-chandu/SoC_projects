/*
// testbench.cpp
#include <iostream>
#include "matrix_mult.h"

using namespace std;

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[N][N];

    matrix_multiply(A, B, C);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

// testbench.cpp
#include <iostream>
#include "matrix_mult.h"

using namespace std;

int main() {
    int A[N * N] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    int B[N * N] = {
        9, 8, 7,
        6, 5, 4,
        3, 2, 1
    };

    int C[N * N] = {0};

    matrix_multiply(A, B, C);

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i * N + j] << " ";
        }
        cout << endl;
    }

    return 0;
}
