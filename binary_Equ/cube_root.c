#include <stdio.h>

int main()
{
    int n, low, high, mid, ans;

    printf("Enter a number: ");
    scanf("%d", &n);

    low = 0;
    high = n;
    ans = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (mid * mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid * mid < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Cube Root = %d", ans);

    return 0;
}
