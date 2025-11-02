#include <stdio.h>

// Function to calculate mean
double mean(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

// Function to calculate covariance
double covariance(double x[], double y[], int n, double mean_x, double mean_y) {
    double cov = 0.0;
    for (int i = 0; i < n; i++)
        cov += (x[i] - mean_x) * (y[i] - mean_y);
    return cov;
}

// Function to calculate variance
double variance(double x[], int n, double mean_x) {
    double var = 0.0;
    for (int i = 0; i < n; i++)
        var += (x[i] - mean_x) * (x[i] - mean_x);
    return var;
}

int main() {
    int n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter input feature (e.g., rainfall, fertilizer amount):\n");
    for (int i = 0; i < n; i++) {
        printf("X[%d] = ", i + 1);
        scanf("%lf", &x[i]);
    }

    printf("Enter corresponding crop yields:\n");
    for (int i = 0; i < n; i++) {
        printf("Y[%d] = ", i + 1);
        scanf("%lf", &y[i]);
    }

    // Calculate means
    double mean_x = mean(x, n);
    double mean_y = mean(y, n);

    // Calculate coefficients
    double b1 = covariance(x, y, n, mean_x, mean_y) / variance(x, n, mean_x);
    double b0 = mean_y - b1 * mean_x;

    printf("\nThe linear regression model is:\n");
    printf("Crop Yield = %.3lf + %.3lf * (Feature)\n", b0, b1);

    // Predict yield for a new input
    double new_x;
    printf("\nEnter a new feature value to predict crop yield: ");
    scanf("%lf", &new_x);

    double predicted_y = b0 + b1 * new_x;
    printf("Predicted Crop Yield = %.3lf\n", predicted_y);

    return 0;
}