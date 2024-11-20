#include <stdio.h>

#define MAX 10

// Function to calculate the divided difference table
void divided_difference_table(float x[], float y[][MAX], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to evaluate the polynomial using Newton's Divided Difference
float newton_divided_difference(float x[], float y[][MAX], int n, float value) {
    float result = y[0][0];
    float product;

    for (int i = 1; i < n; i++) {
        product = 1;
        for (int j = 0; j < i; j++) {
            product *= (value - x[j]);
        }
        result += product * y[0][i];
    }

    return result;
}

int main() {
    int n, i, j;
    float x[MAX], y[MAX][MAX], value, result;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x and y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // Generate the divided difference table
    divided_difference_table(x, y, n);

    printf("\nDivided Difference Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("%10.4f ", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &value);

    // Interpolate the value using the formula
    result = newton_divided_difference(x, y, n, value);

    printf("The interpolated value at x = %.4f is y = %.4f\n", value, result);

    return 0;
}