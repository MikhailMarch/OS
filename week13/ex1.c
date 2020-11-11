#include <stdio.h>
#include <stdlib.h>
int main() {
    //inputing
    // n - number of processes
    // m - number of existing resources 
    int m = 3, n = 5;
    int **c, **r;
    int* e = malloc(m * sizeof(int));
    int* a = malloc(m * sizeof(int));

    // c - current resources
    // r - required resources

    c = malloc(n * sizeof(*c));
    r = malloc(n * sizeof(*r));
    for (int i = 0; i < n; i++)
    {
        c[i] = malloc(m * sizeof(*c[i]));
        r[i] = malloc(m * sizeof(*r[i]));
    }
    FILE *file_in = fopen("input_ok.txt", "r");
    for (int i = 0; i < m; i++)
        fscanf(file_in, "%1d", &e[i]);

    for (int i = 0; i < m; i++)
        fscanf(file_in, "%1d", &a[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(file_in, "%1d", &c[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(file_in, "%1d", &r[i][j]);
    fclose(file_in);

    //calculations
    int have_dl = 0;
    int dl = 0;
    int *p_dl = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        have_dl = 0;
        for (int j = 0; j < n; j++) {
            if (p_dl[j])
                continue;
            int run = 1;
            for (int k = 0; k < m; k++) {
                if (c[j][k] + a[k] < r[j][k]){
                    run = 0;
                    break;
                }
            }
            if (run == 0){
                p_dl[j] = 1;
                have_dl = 1;
                for (int k = 0; k < m; k++){
                    a[k] += c[j][k];
                    c[j][k] = 0;
                }
                break;
            }
        }
        if (have_dl == 0)
            dl = 1;
    }
    //outputing
    
    if (dl){
        FILE *file_out = fopen("output_dl.txt", "w");
        fprintf(file_out, "Deadlocks:\n");
        for (int i = 0; i < n; i++){
            if (!p_dl[i])
                fprintf(file_out, "%d\n", i);
        }
        fclose(file_out);
    } else{
        FILE *file_out = fopen("output_ok.txt", "w");
        fprintf(file_out, "No deadlock\n");
        fclose(file_out);
    }
    return 0;

}