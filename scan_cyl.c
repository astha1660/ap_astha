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
{
	int n,max,curr,prev,*a,*q1,*q2;
	int i, j=0,k=0;
               int total =0;
	int f1,f2,f3,f;
	char buffer[10],invalid[1];
	
	write(1,"Enter size of disk: ",strlen("Enter size of disk: "));
	f1=read(0,buffer,sizeof(buffer));
	max=atoi(buffer);
	
	write(1,"Enter number of pending requests: ",strlen("Enter number of pending requests: "));
	f1=read(0,buffer,sizeof(buffer));
	n=atoi(buffer);
	
	
	write(1,"Enter the curr request (Should be less than size of size of disk): ",strlen("Enter the curr request (Should be less than size of size of disk): "));
	f1=read(0,buffer,sizeof(buffer));
	curr=atoi(buffer);
	if(curr>=max || curr<=0)
	{
		write(1,"Invalid request",strlen("Invalid request"));
		f2=read(0,invalid,1);
		return 0;
	}
		
	write(1,"Enter the previous request (Should be less than size of size of disk): ",strlen("Enter the previous request (Should be less than size of size of disk): "));
	f1=read(0,buffer,sizeof(buffer));
	prev=atoi(buffer);
	if(prev>=max || prev<=0)
	{
		write(1,"Invalid request",strlen("Invalid request"));
		f2=read(0,invalid,1);
		return 0;
	}

	a=(int*)malloc(n*(sizeof(int)));	
	q1=(int*)malloc(n*(sizeof(int)));
	q2=(int*)malloc(n*(sizeof(int)));
		
	write(1,"Enter the requests (Should be less than size of size of disk): ",strlen("Enter the requests (Should be less than size of size of disk): "));
	
	for(i=0;i<n;i++)
	{
		f1=read(0,buffer,sizeof(buffer));
		a[i]=atoi(buffer);
		if(a[i]>=max || a[i]<=0)
		{
			write(1,"Invalid request",strlen("Invalid request"));
			f2=read(0,invalid,1);
			return 0;
		}
		if(a[i]<curr)
		{
			q1[j]=a[i];
			j++;	
		}
		else
		{
			q2[k]=a[i];
			k++;	
		}
			
	}

	if(curr<prev)
	{
		printf("%d",curr);
		sort(q1,j,1);
		printf(" -> 0");
		sort(q2,k,0);
		if(k==0)
			total= curr;
		else	
			total=curr+q2[k-1];
        	printf("/nTotal distance moved by disk arm is %d",total);						
	}
	else
	{
		printf("%d",curr);
		sort(q2,k,0);
		printf("-> %d",max);
		sort(q1,j,1);
		if(j==0)
			total=max-curr;
		else	
			total=max-curr+max-q1[0];
		printf("\nTotal distance moved by disk arm is %d",total);
	}
	
	
	free(a);
	free(q1);
	free(q2);
	return 0;
}



