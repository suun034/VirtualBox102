#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
};

void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (p[i].arrival > p[j].arrival) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].id = i+1;
        printf("Enter arrival and burst time for P%d: ", i+1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }

    sortByArrival(p, n);

    int current_time = 0;
    float total_waiting = 0, total_turnaround = 0;
    printf("\nExecution Order: ");
    
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival)
            current_time = p[i].arrival;
        
        current_time += p[i].burst;
        p[i].completion = current_time;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
        total_waiting += p[i].waiting;
        total_turnaround += p[i].turnaround;

        printf("P%d ", p[i].id);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround/n);
    return 0;
}
