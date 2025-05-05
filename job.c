#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Job structure
typedef struct Job {
    char id[10];
    int deadline;
    int profit;
} Job;

// Comparator for sorting jobs by profit in descending order
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Find the maximum deadline among all jobs
int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

void jobScheduling(Job jobs[], int n) {
    // Sort jobs by profit (descending)
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[MAX];
    memset(slot, -1, sizeof(slot));

    int totalProfit = 0;
    int jobCount = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (latest possible before deadline)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // Assign job to this slot
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    // Output scheduled jobs
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("Time Slot %d: Job %s (Profit: %d)\n",
                   i + 1, jobs[slot[i]].id, jobs[slot[i]].profit);
        }
    }

    printf("\nTotal Jobs Scheduled: %d\n", jobCount);
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    int n;
    Job jobs[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter Job ID, Deadline and Profit for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobScheduling(jobs, n);

    return 0;
}
