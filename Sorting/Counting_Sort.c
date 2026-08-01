#include <stdio.h>

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i, max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    for (i = 0; i <= max; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    int index = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
