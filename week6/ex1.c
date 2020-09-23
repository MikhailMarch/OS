#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int)*n);
    int *b = malloc(sizeof(int)*n);
    for(int i = 0; i < n;i++){
        printf("arrival time of %d:",i+1);
        scanf("%d", &a[i]);
        printf("burst time of %d:",i+1);
        scanf("%d", &b[i]); 
    }
    int ct = 0,wt = 0;
    for(int i = 0; i < n;i++){
        if(a[i]<=ct)
            ct = ct + b[i];
        else
            ct = a[i] + b[i];
        wt = wt + ct - b[i] - a[i]; 
        printf("Completion time for process %d: %d\n",i+1, ct);
        printf("Turn around time for process %d: %d\n",i+1, b[i]);
        printf("Waiting time for process %d: %d\n",i+1, wt);
    }
    double avgtat = (double)ct/n;
    double avgwt = (double)wt/n;
    printf("Average Turnaround time: %f\n",avgtat);
    printf("Average waiting time: %f\n",avgwt);
}
