#include <stdio.h>
#include <string.h>

int main()
{
    char mainString[] = "Sylhet Engineering College";
    char subString[] = "llege";

    int i, j;
    int count = 0;
    int flag = 0;
    int subIndex = -1;

    for (i = 0; i < strlen(mainString); i++)
    {
        count = 0;

        for (j = 0; j < strlen(subString); j++)
        {
            if (mainString[i + j] == subString[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }

        if (count == strlen(subString))
        {
            flag = 1;
            subIndex = i;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Substring found at index %d", subIndex);
    }
    else
    {
        printf("Substring not found");
    }

    return 0;
}
