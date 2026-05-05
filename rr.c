#include <stdio.h>

int main() 
{
    int n, i, time = 0, remain, tq;
    int bt[20], at[20], rt[20], ct[20], wt[20], tat[20], p[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d AT & BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        p[i] = i + 1;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done[20] = {0};
    while(remain > 0) {
        int flag = 0;
        for(i = 0; i < n; i++) 
        {
            if(rt[i] > 0 && at[i] <= time) 
            {
                flag = 1;
                if(rt[i] <= tq) 
                {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    avg_wt += wt[i];
                    avg_tat += tat[i];
                    printf("P%d finished at time %d\n", p[i], ct[i]);
                    remain--;
                } 
                else 
                {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
        if(flag == 0) time++; // CPU idle if no process has arrived yet
    }

    // Display results
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) 
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
