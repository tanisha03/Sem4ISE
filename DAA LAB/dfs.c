#include<stdlib.h>
int n,i,j,a[20][20],visited[20]={0},count=0,visitedorder[20];
void dfs(int i)
{
    count++;
    visited[i]=count;
    for(int v=1;v<=n;v++)
    {
        if(a[i][v]==1 && visited[v]==0)
            dfs(v);
    }
}
void main()
{
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            dfs(i);
    }
    for(i=1;i<=n;i++)
        visitedorder[visited[i]]=i;
    printf("DFS traversal\n");
    for(i=1;i<=n;i++)
        printf("%d  ",visitedorder[i]);

}
