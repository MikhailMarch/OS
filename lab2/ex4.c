#include <stdio.h>
void swap(int*a , int*b){
    int t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int a,b;
    printf("Enter number 2 numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("your numbers are: %d and %d\n", a,b);
    swap(&a,&b);
    printf("your numbers are: %d and %d\n", a,b);
    return 0;
}
