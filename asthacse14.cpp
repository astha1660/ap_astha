#include<stdio.h>
#include <unistd.h>
#include <windows.h>
int main()
{
	printf("-------------------------------------------------------");
	printf("\n\t OPERATING SYSTEM ASSIGNMENT CODE CSE316\n");
	printf("\tName: Astha    Roll No.:37   section: R18SJ   \n");
	printf("-------------------------------------------------------\n\n");

int p[20],burst_t[30], su[20], waiting_tym[20],turn_ar_tym[20],i, r, n, temp;
float waiting_tymavg, t_ar_t_avg;


printf("Kindly Enter the Required Information. Below:\n\n");
sleep(3);

printf("Enter the number of Processes in the queue : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i] = i;
printf("Enter the Burst Time for process[%d] : ",i);
scanf("%d",&burst_t[i]);
printf("teacher/student process (0/1) ? : ");
scanf("%d", &su[i]);
}

for(i=0;i<n;i++)
{
for(r=i+1;r<n;r++)
{
if(su[i] > su[r])
{
temp=p[i];
p[i]=p[r];
p[r]=temp;

temp=burst_t[i];
burst_t[i]=burst_t[r];
burst_t[r]=temp;

temp=su[i];
su[i]=su[r];
su[r]=temp;
}
}
}
waiting_tymavg = waiting_tym[0] = 0;
t_ar_t_avg = turn_ar_tym[0] = burst_t[0];
for(i=1;i<n;i++)
{
waiting_tym[i] = waiting_tym[i-1] + burst_t[i-1];
turn_ar_tym[i] = turn_ar_tym[i-1] + burst_t[i];
waiting_tymavg = waiting_tymavg + waiting_tym[i];
t_ar_t_avg = t_ar_t_avg + turn_ar_tym[i];
}
printf("\nloading results...\n\n");
sleep(3);
printf("------------------------------------------------------------------------------------------------\n");
printf("\n  PROCESS\t TEACHER/STUDENT PROCESS    BURST TIME   \tWAITING TIME\tTURNAROUND TIME");
printf("\n------------------------------------------------------------------------------------------------\n");

for(i=0;i<n;i++)
{ 

printf("\n  %d \t         \t%d  \t\t\t%d\t\t\t%d \t\t%d ",p[i],su[i],burst_t[i],waiting_tym[i],turn_ar_tym[i]);


} 
printf("\n\n-----------------------------------------------------------------------------------------------\n");

printf("\nAverage Waiting Time is : %f",waiting_tymavg);
printf("\nAverage Turnaround Time is : %f\n",t_ar_t_avg);

return 0;
}
