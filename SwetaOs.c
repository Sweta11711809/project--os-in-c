#include<stdio.h>
int main()
{
    int i,j,no_of_p;
    int flag,swap;
    float Awt,Atat;
    int at[12],pr[15],total=0;
    printf("#***********Enter the no  of Process*********************#\n");
    scanf("%d",&no_of_p);

    printf("#************Enter Burst Time , Arrival Time and Priorty***********#\n");
    int bt[20],p_no[20],wt[20],tat[12];

    for(i=0;i<no_of_p;i++)
    {
      printf("\nProcess : P[%d]\n",(i+1));

      printf("Enter the Burst Time:");
      scanf("%d",&bt[i]);
      printf("Enter the Arrival Time:");
      scanf("%d",&at[i]);
      printf("Enter  the Priorty:");
      scanf("%d",&pr[i]);
      p_no[i]=i+1;
      }
      for(i=0;i<no_of_p;i++)
      {
        flag=i;
        for(j=i+1;j<no_of_p;j++)
        {
          if(pr[j]<pr[flag])
          flag=j;
         }
        swap=pr[i];
        pr[i]=pr[flag];
        pr[flag]=swap;
        swap=bt[i];
        bt[i]=bt[flag];
        bt[flag]=swap;
        swap=p_no[i];
        p_no[i]=p_no[flag];
        p_no[flag]=swap;
       }
      wt[0]=0;  
      for(i=1;i<no_of_p;i++)
      {
      wt[i]=0;

      for(j=0;j<i;j++)
      wt[i]+=bt[j];
      total=total+wt[i];
      }
     Awt=total/no_of_p;  
     total=0;
     printf("**************************************************************");
     printf("\nProcess\t     Burst Time    Waiting Time     Turn Around Time");
    for(i=0;i<no_of_p;i++)
    {
    tat[i]=bt[i]+wt[i];  
    total=total+tat[i];
    printf("\nProcess %d   \t %d    \t       %d     \t          %d",p_no[i],bt[i],wt[i],tat[i]);
     }
    printf("\n***************************************************************");
    Atat=total/no_of_p;
    printf("\n\nAvg Waiting Time= %f",Awt);
    printf("\nAvg Turn Around Time= %f\n",Atat);
    return 0;
}
