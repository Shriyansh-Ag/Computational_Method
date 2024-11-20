#include <stdio.h>

double f(double x) {
    return 1 / (1 + x * x); // Example: f(x) = 1 / (1 + x^2)
}

int main() {
    int n, i;
    double a, b, h, sum = 0;

    printf("Enter lower limit, upper limit, and subintervals (even n): ");
    scanf("%lf %lf %d", &a, &b, &n);

    h = (b - a) / n;
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }

    printf("Approximate integral using Simpson’s 1/3 rule: %.6lf\n", (h / 3) * sum);
    return 0;
}