#include <stdio.h>
int main()
{
    int arr[100], key, n;
    int low, high, mid;
    int found = 0;
    printf("Enter the the number of element of array:");
    scanf("%d", &n);
    printf("enter %d element:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            found = 1;
            printf("element found at the position%d", mid + 1);
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (found == 0)
    {
        printf("Element not found!");
    }
    return 0;
}
