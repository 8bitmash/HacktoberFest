#include<stdio.h>

int N;
int board[20][20];

int isAttack(int i, int j)
{
    int l, k;
    for(k=0; k<N; k++)
    {
        if((board[i][k] == 1) || (board[k][j]==1))
            return 1;
    }

    for(k=0; k<N; k++)
    {
        for(l=0; l<N; l++)
        {
            if(((k+l)==(i+j)) || ((k-l)==(i-j)))
            {
                if(board[k][l]==1)
                    return 1;
            }
        }
    }
    return 0;
}

int nQueen(int n)
{
    int i, j;
    if(n==0)
    {
        return 1;
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if( (!isAttack(i, j)) && (board[i][j]!=1))
            {
                board[i][j]=1;
                if(nQueen(n-1)==1)
                {
                    return 1;
                }
                board[i][j]=0;
            }
        }
    }
    return 0;
}

void main()
{
    int i, j;
    printf("Enter the number of queens\n");
    scanf("%d",&N);

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            board[i][j] = 0;
        }
    }

    nQueen(N);

    printf("The solution matrix is: \n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%d\t",board[i][j]);
        }
        printf("\n");
    }
}
