#include <stdio.h>
#include <string.h>


int main(){
    int n,k;
    printf("Enter number: ");
    scanf("%d", &n);
    for(int i = 1; i <= n;i++){
        k = 0;
        for(int j = 0; j < n - i;j++){
            printf(" ");
        }
        while(k != 2 * i - 1){
            printf("*");
            k++;
        }
        printf("\n");
    }
    return 0;
}
