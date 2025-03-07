#include <stdio.h>
int main(){
    int at[10],bt[10],temp[10],wt1[10],tt1[10];
    int i,small,count=0,time,limit;
    int wt = 0,tt = 0,end;

    printf("Enter the Total Number of Processes: ");
    scanf("%d", &limit);
    for(i = 0; i < limit; i++)
    {
        printf("Enter arrival time and burst time of p(%d): ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        temp[i] = bt[i];
    }
    bt[9] = 9999;
    for(time = 0; count != limit; time++){
        small = 9;
        for(i = 0;i<limit; i++){
            if(at[i] <= time && bt[i] < bt[small] && bt[i] > 0)
                small = i;
        }
        bt[small]--;
        if(bt[small] == 0){
            count++;
            end = time + 1;
            wt = wt + end - at[small] - temp[small];
            tt = tt + end - at[small];
            wt1[small] = end - at[small] - temp[small];
            tt1[small] = end -at[small];
        }
    }
    printf("\nProcess/t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0;i<limit;i++){
        printf("p[%d]\t\t%d\t\t%d\t\t%d\n" ,i,temp[i],wt1[i],tt1[i]);
    }
    printf("\nAverage Waiting Time: %d\n", wt/limit);
    printf("Average Turnaround Time: %d\n", tt/limit);

    return 0;
}

