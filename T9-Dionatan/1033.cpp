#include <iostream>

using namespace std;

typedef long long int64;

struct Matrix {
    int64 mat[2][2];
};

Matrix initialize_matrix(int64 a, int64 b, int64 c, int64 d) {
    Matrix m;
    m.mat[0][0] = a;
    m.mat[0][1] = b;
    m.mat[1][0] = c;
    m.mat[1][1] = d;
    return m;
}

Matrix multiply_matrices(Matrix a, Matrix b, int64 m) {
    Matrix result;
    for (int row = 0; row < 2; ++row) {
        for (int column = 0; column < 2; ++column) {
            result.mat[row][column] = 0;
            for (int index = 0; index < 2; ++index) {
                result.mat[row][column] += (a.mat[row][index] * b.mat[index][column]) % m;
            }
        }
    }
    return result;
}

int64 matrix_power(Matrix base, int64 exponent, int64 m) {
    Matrix result = initialize_matrix(1, 0, 0, 1);
    while (exponent) {
        if (exponent & 1) {
            result = multiply_matrices(result, base, m);
        }
        base = multiply_matrices(base, base, m);
        exponent >>= 1;
    }
    return result.mat[0][0];
}

int main() {
    int case_num = 1;
    int64 a, b;
    while (cin >> a >> b && a + b) {
        Matrix base = initialize_matrix(1, 1, 1, 0);
        if (a <= 1) {
            cout << "Case " << case_num++ << ": " << a << " " << b << " 1\n";
        } else {
            cout << "Case " << case_num++ << ": " << a << " " << b << " " << (2 * matrix_power(base, a, b) - 1) % b << endl;
        }
    }
    return 0;
}