#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[], int low, int mid, int high)
{
    int i=low,j=mid+1,k=0;
    int size=low+high-1;
    int b[size];
    while(i<=mid && j<=high)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=high)
    {
        b[k++]=a[j++];
    }
    k=0;
    for(i=low; i<=high; i++)
    {
        a[i]=b[k++];
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid= (low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[1000000], i, n;
    clock_t start, end;
    double total;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    
    total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken= %lf",total);
}