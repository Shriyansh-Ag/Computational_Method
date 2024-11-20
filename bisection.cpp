#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 4; // Example: f(x) = x^2 - 4
}

int main() {
    double a, b, c, tolerance = 0.0001;

    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    if (f(a) * f(b) >= 0) {
        printf("Invalid interval.\n");
        return 1;
    }

    do {
        c = (a + b) / 2;
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    } while (fabs(b - a) >= tolerance);

    printf("Root: %.6lf\n", c);
    return 0;
}