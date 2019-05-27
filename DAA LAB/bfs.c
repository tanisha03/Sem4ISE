#include<stdio.h>
int n,a[20][20],visited[20]={0},q[20]={0},f=0,r=0;
void bfs(int s)
{
	for(int i=1;i<=n;i++)
		if(a[s][i]!=0 && visited[i]==0)
			q[r++]=i;
	if(f<r)
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
int main()
{
	int i,j,source;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("enter the source\n");
	scanf("%d,",&source);
	visited[source]=1;
	bfs(source);
	printf("nodes reachable from %d are:\n",source);
	for(i=1;i<=n;i++)
		if(i!=source)
			if(visited[i])
				printf("%d  ",i);

	
}