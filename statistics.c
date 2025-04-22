#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-i-1; ++j)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

float calculate_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return (float)sum / n;
}

float calculate_median(int arr[], int n) {
    sort(arr, n);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

int calculate_mode(int arr[], int n) {
    int maxCount = 0, mode = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i+1; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *data = malloc(n * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &data[i]);

    printf("\nMean: %.2f", calculate_mean(data, n));
    printf("\nMedian: %.2f", calculate_median(data, n));
    printf("\nMode: %d\n", calculate_mode(data, n));

    free(data);
    return 0;
}
