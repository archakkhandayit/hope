#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Job {
    char id[10];
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

void jobScheduling(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[MAX];
    memset(slot, -1, sizeof(slot));

    int totalProfit = 0;
    int jobCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }
    
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






Enter number of jobs: 5
Enter Job ID, Deadline and Profit for each job:
Job 1: A 2 100
Job 2: B 1 19
Job 3: C 2 27
Job 4: D 1 25
Job 5: E 3 15
