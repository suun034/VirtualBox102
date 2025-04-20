//non preemtive

#include <stdio.h>

void sort(int bt[], int p[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], p[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        p[i] = i+1;
        printf("Enter burst time for P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    sort(bt, p, n);
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    return 0;
}
