#include <stdio.h>

#define MAX 100

struct String
{
    char str[MAX];
};

int length(struct String s)
{
    int i = 0;

    while (s.str[i] != '\0')
        i++;

    return i;
}

void copy(struct String s1, struct String *s2)
{
    int i = 0;

    while (s1.str[i] != '\0')
    {
        s2->str[i] = s1.str[i];
        i++;
    }

    s2->str[i] = '\0';
}

void concatenate(struct String s1, struct String s2,
                 struct String *s3)
{
    int i = 0, j = 0;

    while (s1.str[i] != '\0')
    {
        s3->str[i] = s1.str[i];
        i++;
    }

    while (s2.str[j] != '\0')
    {
        s3->str[i] = s2.str[j];
        i++;
        j++;
    }

    s3->str[i] = '\0';
}

int compare(struct String s1, struct String s2)
{
    int i = 0;

    while (s1.str[i] != '\0' && s2.str[i] != '\0')
    {
        if (s1.str[i] != s2.str[i])
            return s1.str[i] - s2.str[i];

        i++;
    }

    return s1.str[i] - s2.str[i];
}

int main()
{
    struct String s1, s2, s3;

    printf("Enter first string: ");
    scanf("%s", s1.str);

    printf("Enter second string: ");
    scanf("%s", s2.str);

    printf("Length of first string = %d\n", length(s1));

    copy(s1, &s3);
    printf("Copied string = %s\n", s3.str);

    concatenate(s1, s2, &s3);
    printf("Concatenated string = %s\n", s3.str);

    if (compare(s1, s2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    return 0;
}
