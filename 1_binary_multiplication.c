#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void swap(char *c1, char *c2)
{
    char c3 = *c1;
    *c1 = *c2;
    *c2 = c3;
}
char *sum(char *a, char *b)
{
     char *c = (char *)calloc(5000, sizeof(char));
    int carry = -1;
    int l = strlen(a), k = 0;
    int lb = strlen(b);
    int i = l - 1, j = lb - 1;
    while (i >= 0 && j >= 0)
    {
        if (((a[i] - '0') + (b[j] - '0')) == 0)
        {
            if (carry == 1)
            {
                c[k] = '1';
                k++;
                carry = 0;
            }
            else
            {
                c[k] = '0';
                k++;
                carry = 0;
            }
        }
        else if (((a[i] - '0') + (b[j] - '0')) == 1)
        {
            if (carry == 1)
            {
                c[k] = '0';
                k++;
                carry = 1;
            }
            else
            {
                c[k] = '1';
                k++;
                carry = 0;
            }
        }
        else
        {
            if (carry == 1)
            {
                c[k] = '1';
                k++;
                carry = 1;
            }
            else
            {
                c[k] = '0';
                k++;
                carry = 1;
            }
        }
        i--;
        j--;
    }
    //---------------------------------

    while (i >= 0 && j < 0)
    {
        if (carry == 1)
        {
            if (a[i] == '0')
            {
                c[k] = '1';
                k++;
                carry = 0;
            }
            else
            {
                c[k] = '0';
                k++;
                carry = 1;
            }
            i--;
        }
        else
        {
            while (i >= 0)
            {
                c[k] = a[i];
                i--;
                k++;
            }
        }
    }
    //-----------------------
    while (i < 0 && j >= 0)
    {
        if (carry == 1)
        {
            if (b[j] == '0')
            {
                c[k] = '1';
                k++;
                carry = 0;
            }
            else
            {
                c[k] = '0';
                k++;
                carry = 1;
            }
            j--;
        }
        else
        {
            while (j >= 0)
            {
                c[k] = b[j];
                j--;
                k++;
            }
        }
    }

    //----------------------------
    if (carry == 1)
    {
        c[k] = '1';
    }
    // printf("\n%s",c);
    for (int w = 0; w < strlen(c) / 2; w++)
    {
        swap(c + w, c + strlen(c) - w - 1);
    }
    // printf("sum of above binary number is: ");
    // printf("%s", c);
    return c;
}

int main()
{
    char a[100], b[100];
    printf("Enter first binary number: ");
    scanf("%s", a);
    printf("Enter second binary number: ");
    scanf("%s", b);

    char *tempsame = (char *)calloc(5000, sizeof(char));
    strcpy(tempsame, a);
    char *tempzero = (char *)calloc(5000, sizeof(char));
    for (int q = 0; q < strlen(a); q++)
    {
        tempzero[q] = '0';
    }

    char *d = (char *)calloc(5000, sizeof(char));

    if (b[strlen(b) - 1] == '1')
    {
        d = tempsame;
    }
    if (b[strlen(b) - 1] == '0')
    {
        d = tempzero;
    }

    int k = strlen(a) - 1;
    for (int x = strlen(b) - 2; x >= 0; x--)
    {
        if (b[x] == '1')
        {
            k++;
            for (int f = strlen(tempsame); f <= k; f++)
            {
                tempsame[f] = '0';
            }
            d = sum(d, tempsame);
        }
        if (b[x] == '0')
        {
            k++;
            for (int f = strlen(tempsame); f <= k; f++)
            {
                tempzero[f] = '0';
            }
            d = sum(d, tempzero);
        }
    }
    printf("Binary multiplication of above number is : ");
    printf("%s", d);
    return 0;
}