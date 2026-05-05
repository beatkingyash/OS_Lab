#include <stdio.h>

int main() 
{
    int n, i, j, time = 0, completed = 0;
    int bt[20], at[20], pr[20], ct[20], wt[20], tat[20], p[20], done[20] = {0};
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time and Priority:\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d AT BT PR: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    // Non-preemptive Priority Scheduling with Arrival Time
    while(completed < n) 
    {
        int idx = -1;
        int highest_pr = 9999; // smaller number = higher priority

        // Find process with highest priority among arrived processes
        for(i = 0; i < n; i++) 
        {
            if(!done[i] && at[i] <= time && pr[i] < highest_pr) 
            {
                highest_pr = pr[i];
                idx = i;
            }
        }

        if(idx == -1) 
        {
            time++; // CPU idle if no process has arrived yet
            continue;
        }

        // Schedule process
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    // Display table
    printf("\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Calculate averages
    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
