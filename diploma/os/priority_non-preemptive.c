#include <stdio.h>

//Function to calculate average time  
void findavgTime( int processes[], int n, int bt[], int at[], int priority[],int order)  
{  
    int done[10] = {0};
    int wait[10] = {0};
    int st=0,i=0,k=0,sum=0,wt=0,temp=0,count=n,old_st=0;
    int total_tat=0, total_wt=0;
    
    
    
    
    int pos=0,j=0;
    //sorting of burst times
    if(order==0)
    {
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(priority[j]>priority[pos])
                    pos=j;
            }
  
           temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
        
        
        
            temp=priority[i];
            priority[i]=priority[pos];
            priority[pos]=temp;
        
  
            temp=processes[i];
            processes[i]=processes[pos];
            processes[pos]=temp;
        
        
            temp = at[i];
            at[i]=at[pos];
            at[pos]=temp;
        }//end of small if
    }else {
        for(i=0;i<n;i++)
        {
            pos=i;
            for(j=i+1;j<n;j++)
            {
                if(priority[j]<priority[pos])
                    pos=j;
            }
  
           temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
        
        
        
            temp=priority[i];
            priority[i]=priority[pos];
            priority[pos]=temp;
        
  
            temp=processes[i];
            processes[i]=processes[pos];
            processes[pos]=temp;
        
        
            temp = at[i];
            at[i]=at[pos];
            at[pos]=temp;
        }
    }//end of big-if
    
    
    
    
    printf("Priority Non Preemptive Scheduling Algorithm");
    printf("\n\nPID\tAT\tBT\tPri\tWT\tTAT");
    for(st=0;st<100;)
    {
        //printf("\nst=%d",st);
        old_st = st;
        for(i=0;i<n;i++)
        {
            if(at[i]<=st && done[i]!=1)
            {
                temp=st;
                wt = temp-at[i];
                st = st + bt[i];
                done[i]=1;
                //st = complletation time
                total_wt += wt;
                total_tat += st-at[i];
                printf("\nP%d\t%d\t%d\t%d\t%d\t%d",processes[i],at[i],bt[i],priority[i],wt,st-at[i]);//wt+bt[i]);
                count--;
            }else{
                //st++;
            }
        }
        if(old_st==st) st++;
        if(count==0) break;
    }
    printf("\n\nTotal waiting time = %d\t\tAvg = %f",total_wt,(float)total_wt/n);
    printf("\nTotal TAT time = %d\t\tAvg = %f",total_tat,(float)total_tat/n);
}    


int main()
{
    int n=0,i=0,order;
    int processes[100],arrival_time[100],burst_time[100],priority[100];
    printf("Enter no of processes : ");
    scanf("%d",&n);
    
    //generally press 1
    printf("Enter 0 [High no->High Priority] ,1 [Low no->High Priority] : ");
    scanf("%d",&order);
    
    for(i=0;i<n;i++){
        processes[i]=i+1;
        printf("\nEnter Arrival time of P%d : ",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter Burst Time of P%d   : ",i+1);
        scanf("%d",&burst_time[i]);
        printf("Enter Priority of P%d     : ",i+1);
        scanf("%d",&priority[i]);
    }
    printf("\n========================================\n");

    findavgTime(processes, n,  burst_time, arrival_time, priority,order);  
    
    return 0;
}