#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int burst_t[n],i,j,arrival[n],co=0,avg_wt=0;
    for ( i = 0; i < n; i++)
    {
        printf("Enter the burst time of the process: \n");
        scanf("%d",&burst_t[i]);
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the arrival time of the process: \n");
        scanf("%d",&arrival[i]);
    }
    
    for(i=0;i<n;i++){
        int min_idx=i;
        for(j=i+1;j<n;j++){
            if(arrival[j]<arrival[min_idx]){
                min_idx=j;
            }
            if (min_idx!=i){
                int temp=arrival[i];
                arrival[i]=arrival[min_idx];
                arrival[min_idx]=temp;
                temp=burst_t[i];
                burst_t[i]=burst_t[min_idx];
                burst_t[min_idx]=temp;
            }
        }
    }

    if (arrival[0]!=0){
        co=arrival[0];
    }

    for (i=0;i<n;i++){
        printf("Waiting time for the process is %d \n",co-arrival[i]);
        co+=burst_t[i];
        printf("Turn around time for the process is %d \n",co-arrival[i]);
        avg_wt=co/n;}


printf("Average waiting time is %d \n",avg_wt);
    return 0;
}
