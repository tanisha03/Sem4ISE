#include<stdio.h>
char board[100][100];
int n,count=0;
int isattack(int row,int col)
{
    int i,j;
    for(i=0;i<n;i++)
        if(board[row][i]=='Q')
            return 0;
    for(i=0;i<n;i++)
        if(board[i][col]=='Q')
            return 0;
    i=row;
    j=col;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
            return 0;
        i--;
        j--;
    } 
    i=row;
    j=col;
    while(i>=0 && j<n)
    {
        if(board[i][j]=='Q')
            return 0;
        i--;
        j++;
    } 
    return 1;    
}
int nqueen(int row,int n)
{
    int i,j;
    if(row==n)
    {
        printf("--------------SOLUTION %d------------------\n",++count);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%c  ",board[i][j]);
             printf("\n");
        }
    return 0;
    }
    for(i=0;i<n;i++)
    {
        if(isattack(row,i))
        {
            board[row][i]='Q';
            if(nqueen(row+1,n)==1)
                return 1;
            board[row][i]='_';
        }
    }
    return 0;
}
void main()
{
    int i,j;
    printf("number of queens\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            board[i][j]='_';
    nqueen(0,n);
}