#include<stdio.h>
int cost[20][20],visited[20]={0};
void main()
{
    int n,i,j,min,ne=1,source,a,b,mincost=0;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the cost matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    printf("enter the source node \n");
    scanf("%d",&source);
    visited[source]=1;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
            }
        if(visited[a]==0 || visited[b]==0)
        {
            printf("cost from %d to %d is %d\n",a,b,min);
            mincost+=min;
            visited[b]=1;
            ne++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Min cost is %d\n",mincost);
}