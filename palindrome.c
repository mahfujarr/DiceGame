#include<stdio.h>
#include<string.h>

int isMirrored(char a[])
{
    int i, j, size = strlen(a);
    for ( i = 0; i < size; i++)
    {
        if (a[i] == '3')
        {
            a[i] = 'E';
        }
        if (a[i] == '0')
        {
            a[i] = 'O';
        }
        if (a[i] == '5')
        {
            a[i] = 'Z';
        }
        if (a[i] == '2')
        {
            a[i] = 'S';
        }
    }
    for (i = 0, j = size - 1; i <= j; i++, j--)
            {
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    for (int i = 0; i < size-1; i++)
    {
        if(a[i] == 'B' || a[i] == 'C' || a[i] == 'D' || a[i] == 'F' || a[i] == 'G' || a[i] == 'K' ||
           a[i] == 'N' || a[i] == 'P' || a[i] == 'Q' || a[i] == 'R' || a[i] == '4' || a[i] == '6' ||
           a[i] == '7' || a[i] == '9')
        {
            return 0;
            goto S;
        }
    }
    for ( i = 0, j = size - 1; i <= j; i++, j--)
    {
        if ((a[i] == 'A' && a[j] == 'A') || (a[i] == 'E' && a[j] == 'E') || (a[i] == 'H' && a[j] == 'H') ||
            (a[i] == 'I' && a[j] == 'I') || (a[i] == 'M' && a[j] == 'M') || (a[i] == 'O' && a[j] == 'O') ||
            (a[i] == 'T' && a[j] == 'T') || (a[i] == 'U' && a[j] == 'U') || (a[i] == 'V' && a[j] == 'V') ||
            (a[i] == 'W' && a[j] == 'W') || (a[i] == 'X' && a[j] == 'X') || (a[i] == 'Y' && a[j] == 'Y') ||
            (a[i] == '1' && a[j] == '1') || (a[i] == '8' && a[j] == '8') || (a[i] == 'S' && a[j] == 'S'))
        {
            return 1;
        }
    }
    S:
}

void isPalindrome(char a[])
{
    char b[100];
    strcpy(b,a);
    int i, j, pal, mir, size = strlen(a);

    pal = strcmp(a,b);
    mir = isMirrored(a);
    // strrev(b);
    for (i = 0, j = size - 1; i <= j; i++, j--)
    {
        if (b[i] != b[j])
        {
            pal = 1;
        }
    }
    if (pal == 0 && mir == 1)
    {
        printf("%s -- is a mirrored palindrome.\n",b);
    }
    if (pal == 0 && mir != 1)
    {
        printf("%s -- is a regular palindrome.\n",b);
    }
    if (pal != 0 && mir == 1)
    {
        printf("%s -- is a mirrored string.\n",b);
    }
    if (pal != 0 && mir != 1)
    {
        printf("%s -- is not a palindrome.\n",b);
    }
}

int main()
{
    S:
    char arr[100];
    printf("Enter a string: ");
    gets(arr);
    isPalindrome(arr);
    printf("\n");
    goto S;
    return 0;
}
