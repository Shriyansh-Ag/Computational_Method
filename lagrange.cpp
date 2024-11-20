#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10], xp, yp = 0, p;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &x[i], &y[i]);

    printf("Enter value of x to interpolate: ");
    scanf("%f", &xp);

    for (i = 0; i < n; i++) {
        p = 1;
        for (j = 0; j < n; j++) {
            if (i != j) p *= (xp - x[j]) / (x[i] - x[j]);
        }
        yp += p * y[i];
    }

    printf("Interpolated value at x = %.2f is %.6f\n", xp, yp);
    return 0;
}