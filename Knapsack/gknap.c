#include<stdio.h>
#include<stdlib.h>
void knapsack(int n, int c, int *p, int *w)
{
	float r[n],x[n];
	for(int i=0;i<n;i++)
		r[i]=((float)p[i]/(float)w[i]);
	for(int i=0;i<n;i++)
		x[i]=0;
	int u=c;
	int max=0;
	while(u!=0)
	{
		int max=0;
		for(int j=1;j<n;j++)
		{
			if(r[j]>r[max])
				max=j;
		}
		if(w[max]>u)
		{
			x[max]=((float)u/(float)w[max]);
			break;
		}
		x[max]=1;
		u=u-w[max];
		r[max]=0;
	}
	printf("the solution set is:\n");
	printf("(	");
	for (int i=0;i<n;i++)
		printf("%f	",x[i]);
	printf(")");
}
void main()
{
int n;
printf("enter the number of objects:");
scanf("%d",&n);
int c;
int p[n],w[n];
float x[n];
printf("enter the profit associated with each object:\n");
for(int i=0;i<n;i++)
{
	printf("enter the profit of %dth object:",i+1);
	scanf("%d",&p[i]);
}
printf("enter the weight associated with each object:\n");
for(int i=0;i<n;i++)
{
	printf("enter the weight of %dth object:",i+1);
	scanf("%d",&w[i]);
}
printf("enter the capacity of the knapsack:");
scanf("%d",&c);
knapsack(n,c,&p,&w);
}


