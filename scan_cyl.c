#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int compf (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void sort(int a[],int size, int flag)
{
	int i;
	qsort(a,size, sizeof(int),compf);
	if(flag==1)
	{
		for(i=size-1;i>=0;i--)
		{
			printf(" -> %d",a[i]);
		}
	}
	else
	{
		for(i=0;i<size;i++)
		{
			printf(" -> %d",a[i]);
		}
	}
}


int main()
{       printf("-------------------------------------------------------");
	printf("\n\t OPERATING SYSTEM ASSIGNMENT CODE CSE316\n");
	printf("\tName: Astha    Roll No.:37   section: R18SJ   \n");
	printf("-------------------------------------------------------\n\n");
	sleep(2);
	int n,max,curr,prev,*a,*p1,*p2;
	int i, j=0,k=0;
               int total =0;
	int f1,f2,f3,f;
	char buffer[10],invalid[1];
	printf("\n Kindly Enter the Required Information : \n\n");
	sleep(2);
	write(1,"Enter size of the disk:     ",strlen("Enter size of disk:     "));
	f1=read(0,buffer,sizeof(buffer));
	max=atoi(buffer);
        write(1,"Enter the number of pending requests:     ",strlen("Enter number of pending requests:     "));
	f1=read(0,buffer,sizeof(buffer));
	n=atoi(buffer);
	write(1,"Enter the current request :     ",strlen("Enter the current request :    "));
	f1=read(0,buffer,sizeof(buffer));
	curr=atoi(buffer);
	if(curr>=max || curr<=0)
	{
		write(1,"Invalid request",strlen("Invalid request"));
		f2=read(0,invalid,1);
		return 0;
	}
		
	write(1,"Enter the previous request :     ",strlen("Enter the previous request :     "));
	f1=read(0,buffer,sizeof(buffer));
	prev=atoi(buffer);
	if(prev>=max || prev<=0)
	{
		write(1,"Invalid request",strlen("Invalid request"));
		f2=read(0,invalid,1);
		return 0;
	}

	a=(int*)malloc(n*(sizeof(int)));	
	p1=(int*)malloc(n*(sizeof(int)));
	p2=(int*)malloc(n*(sizeof(int)));
		
	write(1,"Enter the requests in the queue : ",strlen("Enter the requests in the queue : "));

	for(i=0;i<n;i++)
	{
		f1=read(0,buffer,sizeof(buffer));
		a[i]=atoi(buffer);
		if(a[i]>=max || a[i]<=0)
		{
				printf("\n\nCalculating Results...\n");
	sleep(4);
			write(1,"Invalid request",strlen("Invalid request"));
			f2=read(0,invalid,1);
			return 0;
		}
		if(a[i]<curr)
		{
			p1[j]=a[i];
			j++;	
		}
		else
		{
			p2[k]=a[i];
			k++;	
		}
			
	}

	if(curr<prev)
	{
		printf("%d",curr);
		sort(p1,j,1);
		
		printf(" -> 0");
		sort(p2,k,0);
		if(k==0)
			total= curr;
		else	
			total=curr+p2[k-1];
				printf("\n\nCalculating Distance...");
	sleep(4);
        	printf("\n\nTotal distance moved by disk arm is %d",total);						
	}
	else
	{
		printf("%d",curr);
		sort(p2,k,0);
		
		printf("-> %d",max);
		sort(p1,j,1);
		if(j==0)
			total=max-curr;
		else	
			total=max-curr+max-p1[0];
				printf("\n\nCalculating Distance...");
	sleep(4);
		printf("\n\nTotal distance moved by disk arm is %d",total);
	}
	free(a);
	free(p1);
	free(p2);
	return 0;
}



