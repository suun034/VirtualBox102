#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
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
        p[i].remaining = p[i].burst;
    }

    int completed = 0, current_time = 0, prev = -1;
    float total_waiting = 0, total_turnaround = 0;
    printf("\nExecution Order: ");
    
    while (completed < n) {
        int idx = -1, min_remaining = 99999;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && p[i].remaining > 0 && p[i].remaining < min_remaining) {
                min_remaining = p[i].remaining;
                idx = i;
            }
        }

        if (idx == -1) {
            current_time++;
            continue;
        }

        if (prev != idx)
            printf("P%d ", p[idx].id);
        
        p[idx].remaining--;
        current_time++;

        if (p[idx].remaining == 0) {
            completed++;
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            total_waiting += p[idx].waiting;
            total_turnaround += p[idx].turnaround;
        }
        prev = idx;
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround/n);
    return 0;
}
