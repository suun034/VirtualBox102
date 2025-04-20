#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid;
    int bt;     // Burst Time
    int at;     // Arrival Time
    int rt;     // Remaining Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
    int completed;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time and arrival time for P%d: ", i + 1);
        scanf("%d%d", &p[i].bt, &p[i].at);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
        p[i].completed = 0;
    }

    int time = 0, completed = 0;
    printf("\nGantt Chart:\n");

    while (completed < n) {
        int idx = -1;
        int min_rt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= time && p[i].rt < min_rt && p[i].rt > 0) {
                min_rt = p[i].rt;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        printf("| %d - P%d ", time, p[idx].pid);
        p[idx].rt--;
        time++;

        if (p[idx].rt == 0) {
            p[idx].completed = 1;
            completed++;
            p[idx].tat = time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }

    printf("| %d\n", time);

    float avg_wt = 0, avg_tat = 0;
    printf("\nProcess\tBT\tAT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
