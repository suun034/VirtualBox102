#include <stdio.h>

#define MAX 100

typedef struct {
    int pid;    // Process ID
    int bt;     // Burst Time
    int at;     // Arrival Time
    int rt;     // Remaining Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
} Process;

int main() {
    int n, quantum;
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
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int time = 0, completed = 0, queue[MAX], front = 0, rear = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("\nGantt Chart:\n");

    // Enqueue processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (p[i].at == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && p[i].at <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];
        printf("| %d - P%d ", time, p[idx].pid);

        int exec_time = (p[idx].rt > quantum) ? quantum : p[idx].rt;
        p[idx].rt -= exec_time;
        time += exec_time;

        // Enqueue new arrivals
        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].at <= time) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (p[idx].rt > 0) {
            queue[rear++] = idx;
        } else {
            completed++;
            p[idx].tat = time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }

    printf("| %d\n", time);

    // Output results
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