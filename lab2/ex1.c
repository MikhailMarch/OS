#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("size of integer is: %lu\n",sizeof(a));
    printf("max value of integer: %d\n",a);
    printf("size of float is: %lu\n",sizeof(b));
    printf("max value of float: %.2f\n",b);
    printf("size of double is: %lu\n",sizeof(c));
    printf("max value of double: %lf\n",c);
    return 0;
}
