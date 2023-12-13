/*premptive
#include <stdio.h>
#include <string.h>

struct process {
    char name[20];
    int at, bt, pr, ct, wt, tat;
    int status;
} p[20], temp;

void main()
{
   int n;
   printf("ENTER THE NUMBER OF PROCESSES: ");
   scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nENTER DETAILS OF PROCESS %d\n", i + 1);
        printf("PROCESS NAME: ");
        scanf("%s", p[i].name);
        printf("ARRIVAL TIME: ");
        scanf("%d", &p[i].at);
        printf("BURST TIME: ");
        scanf("%d", &p[i].bt);
        printf("PRIORITY: ");
        scanf("%d", &p[i].pr);
        p[i].status = 0;
    }
    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n-1-i; j++)
         {
            if (p[j].at > p[j+1].at)
             {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    int currentT= 0, num= 0;
    struct process scheduled[20];
    
    while (num < n)
     {
        int high = -1;
        int index = -1;
        
        for (int i = 0; i < n; i++)
         {
            if (p[i].at <= currentT && p[i].status==0) 
            {
                if (high== -1 || p[i].pr < high) 
                {
                    high = p[i].pr;
                    index = i;
                }
            }
        }
        if (index != -1) 
        {
            p[index].ct = currentT+ p[index].bt;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            currentT = p[index].ct;
            p[index].status = 1;
            scheduled[num++] = p[index];
        }
        else 
        {
            currentT++;
        }
    }
    printf("\nPROCESS NAME\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%-15s\t%6d\t\t%6d\t\t%6d\n", p[i].name, p[i].ct, p[i].wt, p[i].tat);
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }
    
    printf("\nAVERAGE WAITING TIME: %.2f", totalWT / n);
    printf("\nAVERAGE TURNAROUND TIME: %.2f\n", totalTAT / n);
    
    printf("\nGANTT CHART\n");
    printf("-------------------------------------------------------------\n");
    printf("|");
    for (int i = 0; i < num; i++)
    {
        printf(" %-10s |", scheduled[i].name);
    }
    printf("\n-------------------------------------------------------------\n");
    printf("0");
    for (int i = 0; i < num; i++) 
    {
        printf("          %2d", scheduled[i].ct);
    }
 }
 */
#include<stdio.h>
int n,time,tot_wt=0,tot_tat=0,flag,i,j;
struct process
{
 int pid;
 int at;
 int bt;
 int tat;
 int wt;
 int ct;
 int prio;

};


void sjf(struct process p[],int n)
{

 struct process temp;
 //sorting
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-1-i;j++)
  {
  if(p[j].prio>p[j+1].prio)
    {
     temp=p[j];
     p[j]=p[j+1];
     p[j+1]=temp;
    }
  }
 }
 
 time=0;

 for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
       {
        if(p[j].at<=time && p[j].ct==0)
          {
           flag=1;
           break;
          }
       }
   
     if(flag==1)
      {
        time=time+p[j].bt;
        p[j].ct=time;
        p[j].tat=p[j].ct-p[j].at;
        p[j].wt=p[j].tat-p[j].bt;
        tot_wt+=p[j].wt;
        tot_tat+=p[j].tat;
  
      }
     if(flag==0)
      {
        time++;
        i--;
      }
    }
  
  printf("PID\tAT\tBT\tPRIO\tCT\tTAT\tWT\n");
  for(i=0;i<n;i++)
  {
   printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].prio,p[i].ct,p[i].tat,p[i].wt);
  }
}
 
void main()
{
 printf("Enter the no process\n");
 scanf("%d",&n);
 struct process p[n];
 printf("Enter details\n");
 for(int i=0;i<n;i++)
 {
  printf("Enter Pid:");
  scanf("%d",&p[i].pid);
  printf("Enter AT:");
  scanf("%d",&p[i].at);
  printf("Enter BT:");
  scanf("%d",&p[i].bt);
  printf("Enter prio:");
  scanf("%d",&p[i].prio);
  p[i].ct=0;
 }
 
 sjf(p,n);
 }
  
