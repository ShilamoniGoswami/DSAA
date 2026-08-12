#include <stdio.h>

long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    int n, r;
    long long permutation, combination;

    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);

    if (r > n)
    {
        printf("Invalid input: r cannot be greater than n.\n");
    }
    else
    {
        permutation = factorial(n) / factorial(n - r);
        combination = factorial(n) / (factorial(r) * factorial(n - r));

        printf("Permutation (nPr) = %lld\n", permutation);
        printf("Combination (nCr) = %lld\n", combination);
    }

    return 0;
}
