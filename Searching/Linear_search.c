#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    int found = 0;
    int v;

    printf("Enter the value you want to search: ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == v)
        {
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found\n");
    }

    return 0;
}
