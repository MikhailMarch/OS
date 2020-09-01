#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}   

void bubble_sort(int a[],int n){
    for (int i = 0; i < n-1; i++)         
        for (int j = 0; j < n-i-1; j++)  
            if (a[j] > a[j+1]) 
                swap(&a[j], &a[j+1]);

}

void print(int a[], int n) 
{  
    for (int i=0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 

int main(){
    int n;
    scanf("%d", &n);
    int *a= malloc(n * sizeof(int));
    for(int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    print(a, n); 
    return 0;
}
