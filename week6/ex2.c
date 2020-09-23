#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int)*n);
    int *b = malloc(sizeof(int)*n);
    for(int i = 0; i < n;i++){
        printf("arrival time of %d: ",i+1);
        scanf("%d", &a[i]);
        printf("burst time of %d: ",i+1);
        scanf("%d", &b[i]); 
    }
    int ct = 0,wt = 0, shortest = 10000, next;

    for(int i = 0; i < n;i++){
        for(int i = 0; i < n;i++){
            if(b[i] < shortest){
                shortest = b[i];
                next = i;
            } else if(b[i] == shortest){
                if(a[i]<a[next])
                    next = i;
            }
        }
        shortest = 10000;
        if(a[next]<=ct)
            ct = ct + b[next];
        else
            ct = a[next] + b[next];
        printf("Completion time for process %d: %d\n",next+1, ct);
        printf("Turn around time for process %d: %d\n",next+1, b[next]);
        printf("Waiting time for process %d: %d\n",next+1, ct - b[next] - a[next]);
        wt = wt + ct - b[next] - a[next]; 
        a[next] = 10000;
        b[next] = 10000;
    }
    double avgtat = (double)ct/n;
    double avgwt = (double)wt/n;
    printf("Average Turnaround time: %f\n",avgtat);
    printf("Average waiting time: %f\n",avgwt);

}
