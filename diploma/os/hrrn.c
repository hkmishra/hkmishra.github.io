// C program for Highest Response Ratio Next (HRRN) Scheduling 
#include <stdio.h> 
  
// Defining process details 
struct process { 
    char name; 
    int at, bt, ct, wt, tt; 
    int completed; 
    float ntt; 
} p[10]; 
  
int n; 
  
// Sorting Processes by Arrival Time 
void sortByArrival() 
{ 
    struct process temp; 
    int i, j; 
  
    // Selection Sort applied 
    for (i = 0; i < n - 1; i++) { 
        for (j = i + 1; j < n; j++) { 
  
            // Check for lesser arrival time 
            if (p[i].at > p[j].at) { 
  
                // Swap earlier process to front 
                temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp; 
            } 
        } 
    } 
} 
  
void main() 
{ 
    int i, j, t, sum_bt = 0; 
    char c; 
    float avgwt = 0, avgtt = 0; 
    n = 5; 
    
    int arriv[100],burst[100];
    // predefined arrival times 
//    int arriv[] = { 0, 2, 4, 6, 8 }; 
  
    // predefined burst times 
//    int burst[] = { 3, 6, 4, 5, 2 }; 
  
    
    printf("Enter no of processes : ");
    scanf("%d",&n);
    
    for(i = 0; i < n; i++)
    {
            printf("\nEnter Arrival Time P%d:\t",i);
            scanf("%d", &arriv[i]);
            printf("Enter Burst Time P%d  :\t",i);
            scanf("%d", &burst[i]);
    }
    i=0;
    
    // Initializing the structure variables 
    for (i = 0, c = 'A'; i < n; i++, c++) { 
        p[i].name = c; 
        p[i].at = arriv[i]; 
        p[i].bt = burst[i]; 
  
        // Variable for Completion status 
        // Pending = 0 
        // Completed = 1 
        p[i].completed = 0; 
  
        // Variable for sum of all Burst Times 
        sum_bt += p[i].bt; 
    } 
  
    // Sorting the structure by arrival times 
    sortByArrival(); 
    printf("\n========================================\n");
    printf("    HRRN Scheduling Algorithm");
    printf("\n========================================\n");    
    printf("\n#PID\tArrival Time\tBurst Time\tWait Time"); 
    printf("\tTAT\t\t Normalized TT"); 
    for (t = p[0].at; t < sum_bt;) { 
  
        // Set lower limit to response ratio 
        float hrr = -9999; 
  
        // Response Ratio Variable 
        float temp; 
  
        
        
        // Variable to store next processs selected 
        int loc; 
        for (i = 0; i < n; i++) { 
  
            // Checking if process has arrived and is Incomplete 
            if (p[i].at <= t && p[i].completed != 1) { 
  
                // Calculating Response Ratio 
                temp = (p[i].bt + (t - p[i].at)) / p[i].bt; 
  
                // Checking for Highest Response Ratio 
                if (hrr < temp) { 
  
                    // Storing Response Ratio 
                    hrr = temp; 
  
                    // Storing Location 
                    loc = i; 
                } 
            } 
        } 
  
        // Updating time value 
        t += p[loc].bt; 
  
        // Calculation of waiting time 
        p[loc].wt = t - p[loc].at - p[loc].bt; 
  
        // Calculation of Turn Around Time 
        p[loc].tt = t - p[loc].at; 
  
        // Sum Turn Around Time for average 
        avgtt += p[loc].tt; 
  
        // Calculation of Normalized Turn Around Time 
        p[loc].ntt = ((float)p[loc].tt / p[loc].bt); 
  
        // Updating Completion Status 
        p[loc].completed = 1; 
  
        // Sum Waiting Time for average 
        avgwt += p[loc].wt; 
        
        printf("\nP%d\t\t%d\t", p[loc].name-65, p[loc].at); 
        printf("%d\t\t%d\t\t", p[loc].bt, p[loc].wt); 
        printf("%d\t\t%f\t", p[loc].tt, p[loc].ntt); 
    } 
    printf("\n\nAverage waiting time :  %f\n", avgwt / n); 
    printf("Average Turn Around time :  %f\n", avgtt / n); 
} 
