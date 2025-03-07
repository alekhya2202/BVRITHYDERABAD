#include<stdio.h>
 
void main()
{
    int bursttime[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Number of process:");
    scanf("%d",&n);
 
    printf("\nBurst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("For Process %d:",i+1);
        scanf("%d",&bursttime[i]);
        p[i]=i+1;          
    }
 
    
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bursttime[j]<bursttime[pos])
                pos=j;
        }
 
        temp=bursttime[i];
        bursttime[i]=bursttime[pos];
        bursttime[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;           
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bursttime[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bursttime[i]+wt[i];    
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bursttime[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     
    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
}
