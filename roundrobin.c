#include<stdio.h>

int main(){
	int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
	float awt=0,att=0,temp=0;
	printf("Enter the no of processes -- ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter Burst Time for process %d -- ", i+1);
		scanf("%d",&bu[i]);
		ct[i]=bu[i];
	}

	printf("\nEnter the size of time slice -- ");
	scanf("%d",&t);
	max=bu[0];
	for(i=1;i<n;i++) /* temukan proses dengan burst time terbesar */
		if(max<bu[i])
			max=bu[i];
	
	for(j=0;j<(max/t)+1;j++)
		for(i=0;i<n;i++) /* iterasi pada setiap proses */
			if(bu[i]!=0)
				if(bu[i]<=t) /*jika kurang dari time slice*/
				{	
					tat[i]=temp+bu[i]; /* catat ta-time */
					temp=temp+bu[i];
					bu[i]=0;
				}
				else /*jika lebih besar dari time slice*/
				{
					bu[i]=bu[i]-t;
					temp=temp+t;
				}
	for(i=0;i<n;i++){
		wa[i]=tat[i]-ct[i]; /* catat waiting time tiap proses*/
		att+=tat[i]; /* catat total turn around time */
		awt+=wa[i]; /* catat total waiting time */
	}
	printf("\nThe Average Turnaround time is -- %f",att/n);
	printf("\nThe Average Waiting time is -- %f ",awt/n);
	printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
	for(i=0;i<n;i++)
		printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);

	return 0;
}