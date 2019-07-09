#include <stdio.h>
#include <math.h>
int a(int num)
{
    int i;
    for(i=sqrt(num);i>1&& num%i;i--);
    if(i>1) return 0;
    return 1;
}
int main()
{
    printf("%d",a(7));  
    return 0;
}