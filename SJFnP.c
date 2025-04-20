#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
    int done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].id = i+1;
        printf("Enter arrival and burst time for P%d: ", i+1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].done = 0;
    }

    int completed = 0, current_time = 0;
    float total_waiting = 0, total_turnaround = 0;
    printf("\nExecution Order: ");
    
    while (completed < n) {
        int idx = -1, min_burst = 99999;
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= current_time && p[i].burst < min_burst) {
                min_burst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            current_time++;
            continue;
        }

        current_time += p[idx].burst;
        p[idx].completion = current_time;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        total_waiting += p[idx].waiting;
        total_turnaround += p[idx].turnaround;
        p[idx].done = 1;
        completed++;

        printf("P%d ", p[idx].id);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround/n);
    return 0;
}
