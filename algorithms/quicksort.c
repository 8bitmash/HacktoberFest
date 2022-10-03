#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int low, int high)
{
    int i=low, j=high, temp;
    int pivot=a[low];
    while(i<j)
    {
        while(a[i] <= pivot && i<high)
        {
            i++;
        }
        while(a[j] >= pivot && j>low)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    if(low<high)
    {
        int pos= partition(a, low, high);
        quicksort(a, low, pos-1);
        quicksort(a, pos+1, high);
    }
}

int main()
{
    int a[100000], i, n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("Sorted array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}