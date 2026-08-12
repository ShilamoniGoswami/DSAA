#include <stdio.h>

void bucketSort(float a[], int n)
{
    float bucket[10][10];
    int count[10] = {0};
    int i, j, k;
    float temp;
    for (i = 0; i < n; i++)
    {
        int index = a[i] * 10;
        bucket[index][count[index]++] = a[i];
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i] - 1; j++)
        {
            for (k = j + 1; k < count[i]; k++)
            {
                if (bucket[i][j] > bucket[i][k])
                {
                    temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }
    k = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
}

int main()
{
    float a[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = 7;
    int i;

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    return 0;
}
