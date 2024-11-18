#include <iostream>
#include <cmath>

using namespace std;

// Константы для системы уравнений
const int N1 = 3; // Размерность первой системы
const int N2 = 4; // Размерность второй системы
const int N3 = 5; // Размерность третьей системы

// Функция для печати решения
void printSolution(const double solution[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

// Основная функция, реализующая метод Зейделя
void solveSeidelMethod(const double A[][5], const double B[], double X[], int n, double tolerance, int maxIterations) {
    double X_prev[5];

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        for (int i = 0; i < n; ++i) {
            X_prev[i] = X[i];
        }

        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i)
                    sigma += A[i][j] * X[j];
            }
            X[i] = (B[i] - sigma) / A[i][i];
        }

        double diff = 0.0;
        for (int i = 0; i < n; ++i) {
            diff += fabs(X[i] - X_prev[i]);
        }

        if (diff < tolerance) {
            cout << "Converged in " << iteration + 1 << " iterations." << endl;
            return;
        }
    }

    cout << "Reached maximum iterations without converging." << endl;
}

int main() {
    double tolerance = 1e-4;
    int maxIterations = 1000;

    // Ввод данных для системы a)
    double A1[N1][5] = {
        {22.52, -4.62, -1.41, 0, 0},
        {-5.10, -28.37, 4.58, 0, 0},
        {4.68, -1.91, 23.85, 0, 0}
    };
    double B1[N1] = { 0.53, -8.79, 5.14 };
    double X1[N1] = { 0, 0, 0 }; // Начальные приближения

    cout << "Solving system a)..." << endl;
    solveSeidelMethod(A1, B1, X1, N1, tolerance, maxIterations);
    printSolution(X1, N1);

    // Ввод данных для системы б)
    double A2[N2][5] = {
        {-23.98, -1.50, -8.78, 7.74, 0},
        {8.70, -23.88, -7.87, 1.26, 0},
        {1.62, 3.88, -18.17, 8.68, 0},
        {-6.97, 1.96, 1.55, -29.54, 0}
    };
    double B2[N2] = { -0.04, -0.44, -0.44, -2.02 };
    double X2[N2] = { 0, 0, 0, 0 }; // Начальные приближения

    cout << "Solving system b)..." << endl;
    solveSeidelMethod(A2, B2, X2, N2, tolerance, maxIterations);
    printSolution(X2, N2);

    // Ввод данных для системы в)
    double A3[N3][5] = {
        {-17.01, 6.28, -8.25, -2.57, 3.05},
        {7.98, 18.40, -7.82, -1.51, 0.20},
        {-2.43, 2.49, 20.13, 5.37, -8.46},
        {5.82, -1.48, 1.13, -2.62, 2.27},
        {0, 0, 0, 0, 0} // Заполните правильные коэффициенты, если необходимо
    };
    double B3[N3] = { -6.47, 0.03, 2.49, 0.55, 0 }; // Заполните правую часть, если необходимо
    double X3[N3] = { 0, 0, 0, 0, 0 }; // Начальные приближения

    cout << "Solving system c)..." << endl;
    solveSeidelMethod(A3, B3, X3, N3, tolerance, maxIterations);
    printSolution(X3, N3);

    return 0;
}
