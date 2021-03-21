#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <queue> 
#include <string.h>
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

bool compare1(process p1, process p2) 
{ 
    return p1.arrival_time < p2.arrival_time;
}

bool compare2(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}



//Function to calculate average time  
void FCFS( int processes[], int n, int bt[], int at[], int processes_dict2[])  
{  
    int done[10] = {0};
    int wait[10] = {0};
    int st=0,i=0,k=0,sum=0,wt=0,temp=0,count=n,old_st=0;
    int total_tat=0, total_wt=0;
    printf("    FCFS Scheduling Algorithm");
    printf("\n\nPID\tAT\tBT\tWT\tTAT");
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
                printf("\nP%d\t%d\t%d\t%d\t%d",processes_dict2[i],at[i],bt[i],wt,st-at[i]);//wt+bt[i]);
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

int main() {

    int n,count=0,type;
    int tq;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int idx;

    int at[100],bt[100],temp,processes[100],at2[100],bt2[100],processes2[100];
    int processes_dict[100],processes_dict2[100];
    
    cout << setprecision(2) << fixed;
    cout<<"MultiLevel Queue with Queue 1 = RR | Queue 2 = FCFS"<<endl;
    cout<<"===================================================="<<endl<<endl;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"\nEnter time quantum for Queue 1: ";
    cin>>tq;

   
    cout<<endl<<endl;
     for(int i = 0,j=0,k=0; i < n; i++) {
        cout<<"Enter Process Type [0/1] for P "<<i+1<<": ";
        cin>>type;
        if(type==1){    //for FCFS
            cout<<"Enter arrival time of        P "<<i+1<<": ";
            cin>>at2[j];
            cout<<"Enter burst time of          P "<<i+1<<": ";
            cin>>bt2[j];
            processes2[j] = j+1;
            processes_dict2[j]=i+1;
            count += 1;
            j++;
        }else {
            cout<<"Enter arrival time of       P "<<i+1<<": ";
            cin>>at[k];
            cout<<"Enter burst time of         P "<<i+1<<": ";
            cin>>bt[k];
            processes[k] = k+1;
            processes_dict[k]=i+1;
            k++;
        }
        cout<<endl;
    }
    
    n=n-count;

      

    int pos=0,j=0;
    //sorting of burst times
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=processes[i];
        processes[i]=processes[pos];
        processes[pos]=temp;
        
        
        temp=processes_dict[i];
        processes_dict[i]=processes_dict[pos];
        processes_dict[pos]=temp;
        
        temp = at[i];
        at[i]=at[pos];
        at[pos]=temp;
    }
    
     for(int i = 0; i < n; i++) {
//        cout<<"Enter arrival time of process "<<i+1<<": ";
        p[i].arrival_time=at[i];
//        cout<<"Enter burst time of process "<<i+1<<": ";
        p[i].burst_time=bt[i];
        burst_remaining[i] = p[i].burst_time;
        p[i].pid = processes[i];
//        cout<<endl;
    }


    sort(p,p+n,compare1);

    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark,0,sizeof(mark));
    mark[0] = 1;

    while(completed != n) {
        idx = q.front();
        q.pop();

        if(burst_remaining[idx] == p[idx].burst_time) {
            p[idx].start_time = max(current_time,p[idx].arrival_time);
            total_idle_time += p[idx].start_time - current_time;
            current_time = p[idx].start_time;
        }

        if(burst_remaining[idx]-tq > 0) {
            burst_remaining[idx] -= tq;
            current_time += tq;
        }
        else {
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

            p[idx].completion_time = current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].arrival_time;

            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            total_response_time += p[idx].response_time;
        }

        for(int i = 1; i < n; i++) {
            if(burst_remaining[i] > 0 && p[i].arrival_time <= current_time && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(burst_remaining[idx] > 0) {
            q.push(idx);
        }

        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(burst_remaining[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }


    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((p[n-1].completion_time - total_idle_time) / (float) p[n-1].completion_time)*100;
    throughput = float(n) / (p[n-1].completion_time - p[0].arrival_time);

    sort(p,p+n,compare2);

    cout<<endl;
    
    cout<<"========================================"<<endl;
    cout<<"Round Robin Scheduling Algorithm"<<endl;
    cout<<"========================================"<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<"P"<<processes_dict[i]<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].response_time<<"\t"<<"\n"<<endl;
//        cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<endl<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;


    cout<<endl<<endl;

    FCFS(processes2, count, bt2, at2, processes_dict2 );
}

/*
AT - Arrival Time of the process
BT - Burst time of the process
ST - Start time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process
RT - Response time of the process
Formulas used:
TAT = CT - AT
WT = TAT - BT
RT = ST - AT
*/
