#include<stdio.h>
int cost[20][20],visited[20]={0},d[20]={0};
void main()
{
    int i,j,n,source,min,u=0;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
               cost[i][j]=999;
        }
    printf("enter source\n");
    scanf("%d",&source);
    for(i=1;i<=n;i++)
        d[i]=cost[source][i];
    d[source]=0;
    visited[source]=1;
    for(j=2;j<=n;j++)
    {
        min=999;
        for(i=1;i<=n;i++)
            if(visited[i]==0)
                if(d[i]<min)
                {
                    min=d[i];
                    u=i;
                }
        visited[u]=1;
        for(i=1;i<=n;i++)
            if(cost[u][i]!=999 && visited[i]==0)
                if(d[i]>min+cost[u][i])
                    d[i]=min+cost[u][i];
    }
    printf("distance from %d to\n",source);
    for(i=1;i<=n;i++)
        if(i!=source)
            printf("%d=%d\n",i,d[i]);
}