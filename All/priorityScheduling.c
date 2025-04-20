//non preemptive

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], bt[n], pr[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time and priority for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    // Sort based on priority
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (pr[i] > pr[j]) {
                int t = pr[i]; pr[i] = pr[j]; pr[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    return 0;
}
