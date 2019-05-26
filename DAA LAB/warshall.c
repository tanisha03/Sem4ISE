#include<stdio.h>
int a[20][20],n;
void warshall()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
}
void main()
{
    int i,j;
    printf("enter the no of nodes \n");
    scanf("%d",&n);
    printf("enter the matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
    warshall();
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%d ",a[i][j]);
        printf("\n");
        }
}
