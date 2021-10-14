#include <stdio.h>
#include <string.h>

int main()
{
    char x[100],y[100];
     printf("Enter first unary number (III...) : ");
    scanf("%s", x);
    printf("Enter second unary number (III...) : ");
    scanf("%s", y);
    int xl = strlen(x);
    int yl = strlen(y);

    printf("Product of above number is : ");
    for(int i=1;i<=(xl*yl);i++){
        printf("I");
    }
    return 0;
}