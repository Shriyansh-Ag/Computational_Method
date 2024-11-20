#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 4; // Example: f(x) = x^2 - 4
}

int main() {
    double x0, x1, x2, tolerance = 0.0001;
    int max_iter = 100, iter = 0;

    printf("Enter two initial guesses: ");
    scanf("%lf %lf", &x0, &x1);

    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(x2 - x1) < tolerance) break;
        x0 = x1;
        x1 = x2;
        iter++;
    } while (iter < max_iter);

    if (iter < max_iter)
        printf("Root: %.6lf\n", x2);
    else
        printf("Solution did not converge.\n");

    return 0;
}