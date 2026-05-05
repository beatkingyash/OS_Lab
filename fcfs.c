#include <stdio.h>

int main() 
{
    int n, i, j;
    int bt[20], at[20], wt[20], tat[20], ct[20], p[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d AT & BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i + 1;  // process IDs
    }

    // Sort processes by Arrival Time
    for(i = 0; i < n; i++) 
    {
        for(j = i + 1; j < n; j++) 
        {
            if(at[i] > at[j]) 
            {
                int temp;

                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i] = p[j];  p[j] = temp;
            }
        }
    }

    // Completion time calculation
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) 
    {
        if(at[i] > ct[i-1]) 
        {
            ct[i] = at[i] + bt[i];  // CPU idle until process arrives
        } 
        else 
        {
            ct[i] = ct[i-1] + bt[i];
        }
    }

    // Turnaround time & Waiting time
    for(i = 0; i < n; i++) 
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Display table
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
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
