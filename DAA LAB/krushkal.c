#include<stdio.h>
int cost[20][20],parent[20]={0};
void main()
{
    int n,i,j,ne=1,min,mincost=0,u,v,a,b;
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
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<min)
                {  
                    min=cost[i][j];
                    u=a=i;
                    v=b=j;
                }
        if(parent[u])
            u=parent[u];
        if(parent[v])
            v=parent[v];
        if(u!=v)
        {
            printf("cost from %d to %d is %d\n",a,b,min);
            mincost+=min;
            ne++;
            parent[v]=u;
        }

    cost[a][b]=cost[b][a]=999;
    }
    printf("min cost is %d\n",mincost);
}