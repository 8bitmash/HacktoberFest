#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a[100000], n, i, j, temp, t;
	clock_t start, end;
	double total;
	printf("Enter the number of elements\n");
	//scanf("%d",&n);
	//printf("Enter the elements");
	for(t=5000; t<=50000; t=t+5000)
	{
		n=t;
		for(i=0; i<n; i++)
		{
			a[i]=rand();
		}
		start=clock();
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		end=clock();
		total = (double)(end-start)/CLOCKS_PER_SEC;
		printf("Time for %d is = %lf\n",t,total);

	}
	// printf("Sorted set of elements : \n");
	// for(i=0; i<n; i++)
	// 	printf("%d\t",a[i]);
}
