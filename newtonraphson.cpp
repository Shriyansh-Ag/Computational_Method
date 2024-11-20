#include <stdio.h>
#include <math.h>

// Function definition
double f(double x) {
    return x * x - 4; // Example: f(x) = x^2 - 4
}

double df(double x) {
    return 2 * x; // Derivative: f'(x) = 2x
}

int main() {
    double x0, x1, tolerance = 0.0001;
    int max_iter = 100, iter = 0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    do {
        x1 = x0 - f(x0) / df(x0);
        if (fabs(x1 - x0) < tolerance) {
            break;
        }
        x0 = x1;
        iter++;
    } while (iter < max_iter);

    if (iter < max_iter)
        printf("Root: %.6lf\n", x1);
    else
        printf("Solution did not converge.\n");

    return 0;
}