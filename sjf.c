#include <stdio.h>

int main() 
{
    int n, i, j, completed = 0, time = 0;
    int bt[20], at[20], wt[20], tat[20], ct[20], p[20], done[20] = {0};
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT & BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i + 1;
    }

    // SJF with Arrival Time (Non-preemptive)
    while(completed < n) 
    {
        int idx = -1;
        int min_bt = 9999;

        // Find process with shortest BT among arrived processes
        for(i = 0; i < n; i++) 
        {
            if(!done[i] && at[i] <= time && bt[i] < min_bt) 
            {
                min_bt = bt[i];
                idx = i;
            }
        }

        if(idx == -1) 
        {
            time++; // No process has arrived yet, CPU idle
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
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
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
