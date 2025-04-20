#include <stdio.h>
#include <stdbool.h>

// typedef struct {
//     char pid[5];
//     int arrival, burst, completion, waiting, turnaround;
//     bool done;
// } Process;

struct Process{
    char pid[5];
    int arrival, burst, completion, waiting, turnaround;
    bool done;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Process ID, Arrival Time, Burst Time: ");
        scanf("%s %d %d", p[i].pid, &p[i].arrival, &p[i].burst);
        p[i].done = false;
    }

    int time = 0, executed[n], execIndex = 0;
    float totalWT = 0, totalTAT = 0;

    for (int count = 0; count < n; count++) {
        int idx = -1, minArrival = 1e9;
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival < minArrival) {
                minArrival = p[i].arrival;
                idx = i;
            }
        }

        if (time < p[idx].arrival) time = p[idx].arrival;
        time += p[idx].burst;
        p[idx].completion = time;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        p[idx].done = true;
        totalWT += p[idx].waiting;
        totalTAT += p[idx].turnaround;
        executed[execIndex++] = idx;
    }

    printf("\nFCFS Schedule:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);

    printf("Average Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);

    printf("Execution Order: ");
    for (int i = 0; i < execIndex; i++) printf("%s ", p[executed[i]].pid);
    printf("\n");

    return 0;
}
