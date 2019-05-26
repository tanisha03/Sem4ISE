#include<stdio.h>
int n,p[20],w[20],m,a[20][20],i,j;
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void knapsack()
{
    for(i=0;i<=m;i++)
        a[0][i]=0;
    for(j=0;j<=n;j++)
        a[j][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(j<w[i])
                a[i][j]=a[i-1][j];
            else
                a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+p[i]);
        }
        i=n;
        j=m;
        while(i>0 && j>0)
        {
            if(a[i][j]!=a[i-1][j])
            {
                printf("Item %d with weight %d \n",i,w[i]);
                j=j-w[i];
            }
            i--;
        }
        printf("\n %d \n",a[n][m]);
}
void main()
{
printf("enter the number of items");
scanf("%d",&n);
printf("enter the weights of the items \n ");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("enter profit of items \n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("enter capacity \n");
scanf("%d",&m);
knapsack();
}
