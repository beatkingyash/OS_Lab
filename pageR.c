#include <stdio.h>

#define MAX 50

// Function for FIFO
int fifo(int pages[], int n, int f) 
{
    int frames[10], pos = 0, faults = 0;
    for(int i = 0; i < f; i++) 
    frames[i] = -1;

    for(int i = 0; i < n; i++) 
    {
        int found = 0;
        for(int j = 0; j < f; j++) 
        {
            if(frames[j] == pages[i]) 
            {
                found = 1;
                break;
            }
        }

        if(!found) 
        {
            frames[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }
    return faults;
}

// Function for LRU
int lru(int pages[], int n, int f) 
{
    int frames[10], time[10], counter = 0, faults = 0;
    for(int i = 0; i < f; i++) 
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++) 
    {
        int found = 0;
        for(int j = 0; j < f; j++) 
        {
            if(frames[j] == pages[i]) 
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) 
        {
            if(i < f) 
            {
                frames[i] = pages[i];
                counter++;
                time[i] = counter;
            } 
            else 
            {
                int min = time[0], pos = 0;
                for(int j = 1; j < f; j++) 
                {
                    if(time[j] < min) 
                    {
                        min = time[j];
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }
            faults++;
        }
    }
    return faults;
}

// Function for Optimal
int optimal(int pages[], int n, int f) 
{
    int frames[10], faults = 0;
    for(int i = 0; i < f; i++) frames[i] = -1;

    for(int i = 0; i < n; i++) 
    {
        int found = 0;
        for(int j = 0; j < f; j++) 
        {
            if(frames[j] == pages[i]) 
            {
                found = 1;
                break;
            }
        }

        if(!found) 
        {
            if(i < f) 
            {
                frames[i] = pages[i];
            } 
            else 
            {
                int farthest = -1, pos = -1;
                for(int j = 0; j < f; j++) {
                    int found_future = 0;
                    for(int k = i + 1; k < n; k++) 
                    {
                        if(frames[j] == pages[k]) 
                        {
                            if(k > farthest) 
                            {
                                farthest = k;
                                pos = j;
                            }
                            found_future = 1;
                            break;
                        }
                    }

                    if(!found_future) 
                    {
                        pos = j;
                        break;
                    }
                }
                frames[pos] = pages[i];
            }
            faults++;
        }
    }
    return faults;
}

int main() 
{
    int pages[MAX], n, f, choice;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\nChoose Page Replacement Algorithm:\n");
    printf("1. FIFO\n2. LRU\n3. Optimal\n");
    scanf("%d", &choice);

    int faults = 0;
    switch(choice) 
    {
        case 1: faults = fifo(pages, n, f); 
        break;

        case 2: faults = lru(pages, n, f); 
        break;

        case 3: faults = optimal(pages, n, f); 
        break;

        default: printf("Invalid choice!\n"); 
        return 0;
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
