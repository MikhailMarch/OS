#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

// for different values of quantum output will be different
// if the quantum value is minimal the task destribution will be more fair
// if the quantum value is maximum the task destribution will be less fair and sometimes it can increase waiting time for other processes


int main(){
    int n,quantum;
    printf("Number of processors: ");
    scanf("%d", &n);
    printf("Quantum specification: ");
    scanf("%d", &quantum);
    int *a = malloc(sizeof(int)*n);
    int *b = malloc(sizeof(int)*n);
    int *burst = malloc(sizeof(int)*n);
    for(int i = 0; i < n;i++){
        printf("arrival time of %d:",i+1);
        scanf("%d", &a[i]);
        printf("burst time of %d:",i+1);
        scanf("%d", &b[i]); 
        burst[i] = b[i];
    }

    int time = 0, x = n,  counter = 0, i = 0;
    int tat = 0, wt = 0;
    while(x!=0){
        if(b[i] <= quantum && b[i] > 0){
                time = time + b[i];
                b[i] = 0;
                counter = 1;
        }else if(b[i] > 0){
                b[i] = b[i] - quantum;
                time = time + quantum;
        } if(b[i] == 0 && counter == 1) {
                x--;
                printf("Completion time for process %d: %d\n",i+1, time - a[i]);
                printf("Turn around time for process %d: %d\n",i+1, time - a[i]);
                printf("Waiting time for process %d: %d\n",i+1, time - a[i] - burst[i]);
                wt = wt + time - a[i] - burst[i];
                tat = tat + time - a[i];
                counter = 0;
        } if(i == n - 1) {
                i = 0;
        } else if(a[i + 1] <= time) {
                i++;
        } else {
                i = 0;
        }
    }
    double avgtat = (double)tat/n;
    double avgwt = (double)wt/n;
    printf("Average Turnaround time: %f\n",avgtat);
    printf("Average waiting time: %f\n",avgwt);

}

