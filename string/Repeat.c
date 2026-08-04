#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "SylhetSylhet";

    int n = strlen(str);
    int len, i, j, flag;

    for (len = 1; len <= n / 2; len++)
    {
        if (n % len == 0)
        {
            flag = 1;

            for (i = len; i < n; i++)
            {
                if (str[i] != str[i % len])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                printf("Repeated String\n");
                printf("Repeated Part: ");

                for (j = 0; j < len; j++)
                {
                    printf("%c", str[j]);
                }

                printf("\n");
                return 0;
            }
        }
    }

    printf("Not a Repeated String\n");

    return 0;
}
