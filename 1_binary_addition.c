#include <stdio.h>
#include <string.h>
#include<stdlib.h>
// char c[200];

void swap(char*c1,char*c2)
{
    char c3 =*c1;
    * c1= *c2;
    *c2 = c3;
}
int main()
{
    char a[100], b[100];
    char *c = (char *)calloc(100,sizeof(char));
    // static char c[200];
    printf("Enter first binary number: ");
    scanf("%s", a);
    printf("Enter second binary number: ");
    scanf("%s", b);
    int carry = -1;
    int l = strlen(a), k = 0;
    int lb = strlen(b);
    int i=l-1,j=lb-1;
    while(i>=0 && j>=0)
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
    for(int w=0;w<strlen(c) /2;w++)
    {
        swap(&c[w],&c[strlen(c)-w-1]);
    }
    printf("sum of above binary number is: ");
    printf("%s",c);
}