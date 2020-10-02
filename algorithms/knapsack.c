#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
  if(a>b)
    return a;
  else 
    return b;
}
int main()
{
    int m[100][100], i, j, k, n, cap, w[100], v[100];
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the weights\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the values\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("Enter the capacity\n");
    scanf("%d",&cap);
    for(i=1; i<n+1; i++)
    {   
        for(j=1; j<cap+1; j++)
        {
            if(j-w[i]>=0)
                m[i][j]=max(m[i-1][j], (m[i-1][j-w[i]]+v[i]));
            else
                m[i][j]=m[i-1][j];
        }
    }
    printf("The max value is: %d\n", m[n][cap]);
    printf("******Matrix********\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=cap;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    j=cap;
    int x[100];
    for(i=1;i<=n;i++)
        x[i]=0;
    for(i=n;i>0;i--)
    {
        if(m[i][j]!=m[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
    }
    printf("The item set is:\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf("Item %d\n",i);
        }
    }
}