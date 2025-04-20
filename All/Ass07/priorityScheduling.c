#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
} Process;

// Function to compare processes by arrival time
int compareArrivalTime(const void *a, const void *b) {
    return ((Process*)a)->arrivalTime - ((Process*)b)->arrivalTime;
}

// Function to compare processes by priority
int comparePriority(const void *a, const void *b) {
    return ((Process*)a)->priority - ((Process*)b)->priority;
}

void calculateTimes(Process processes[], int n) {
    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Process execution order
    for (int i = 0; i < n; i++) {
        // Select the next process with the highest priority
        if (processes[i].arrivalTime > currentTime) {
            currentTime = processes[i].arrivalTime;  // If the process arrives later, wait for it
        }

        processes[i].startTime = currentTime;
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].startTime - processes[i].arrivalTime;

        // Update the current time
        currentTime = processes[i].completionTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Calculate average times
    printf("\nProcess ID | Arrival Time | Burst Time | Priority | Waiting Time | Turnaround Time | Completion Time\n");
    for (int i = 0; i < n; i++) {
        printf("   %d       |     %d       |     %d     |    %d     |     %d      |       %d        |      %d\n",
               processes[i].processID, processes[i].arrivalTime, processes[i].burstTime, processes[i].priority,
               processes[i].waitingTime, processes[i].turnaroundTime, processes[i].completionTime);
    }

    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Input data for each process
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("\nEnter details for Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    // Sort processes by arrival time first
    qsort(processes, n, sizeof(Process), compareArrivalTime);

    // Sort processes by priority (within the same arrival time)
    qsort(processes, n, sizeof(Process), comparePriority);

    // Calculate and display times
    calculateTimes(processes, n);

    return 0;
}
