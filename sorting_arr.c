#include <stdio.h>

void sort(int *arr, int n) {
    int max, temp, m;

    for (int i = n - 1; i > 0; i--) {
        max = arr[0];
        m = 0;

        for (int j = 1; j <= i; j++) {
            if (arr[j] > max) {
                max = arr[j];
                m = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;
    }
}

int main() {
    int n;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
