#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	/*for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}*/
}
void swap(int a,int b)
{
	int t=a;
	a=b;
	b=t;
}
int part(int a[],int l,int h)
{
	int pivot=a[h];
	int i=l-1;
	for(int j=l;j<h;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[h]);
	return(i+1);
}
void qs(int a[],int l,int h,int n)
{
	if(l<h)
	{
		int p=part(a,l,h);
		qs(a,l,p-1,n);
		qs(a,p+1,h,n);
	}
}
void main()
{
	int l=10,i,n;
	clock_t start_b,end_b,start_q,end_q;
	double total_b,total_q;
	printf("size		bubble			quick\n");
	while(l<=100000)
	{
		int a[l];
		for(i=0;i<l;i++)
		{
			a[i]=rand()%5000000;
		}
		start_b=clock();
		//printf("Starting loops for bubble sort %ld \n",start_b);
		bubble(a,l);
		end_b=clock();
		//printf("\nEnding loops =%ld\n",end_b);
		total_b=(double)(end_b-start_b)/CLOCKS_PER_SEC;
		//printf("Total time taken for bubble sort is : %f\n",total_t);
		start_q=clock();
		//printf("Starting loops for quick sort %ld \n",start_q);
		qs(a,0,l-1,l);
		/*for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}*/
		end_q=clock();
		//printf("\nEnding loops =%ld\n",end_q);
		total_q=(double)(end_q-start_q)/CLOCKS_PER_SEC;
		//printf("Total time taken for quick sort is : %f\n",total_q);
		printf("%d		%f 		%f\n",l,total_b,total_q);
		l=l*10;
		FILE *fil1;
 		fil1=fopen("/home/student/graph.dat","a");
 		fprintf(fil1,"%d\t\t%f\t\t\t%f\n",l,total_b,total_q);
 		//fprintf(file1,"%.10lf\n",total_q);
 		fclose(fil1);
	}
}


