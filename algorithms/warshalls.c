#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define size 10

int main()
{
    int a[size][size], i, j, k, n, t;
    printf("Enter the order of the matrix\n");
    scanf("%d",&n);
    printf("Enter the elements of the matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==1 || (a[i][k]==1 && a[k][j]==1))
                {
                    a[i][j]=1;
                }
            }
        }
    }
    printf("Transitive closure matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}