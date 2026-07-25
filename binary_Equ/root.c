#include <stdio.h>

int main()
{
    int n;
    int low, high, mid;
    int ans = -1;

    printf("Enter a number: ");
    scanf("%d", &n);

    low = 0;
    high = n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (ans != -1)
        printf("Square Root = %d\n", ans);
    else
        printf("No Integer Square Root Found\n");

    return 0;
}
