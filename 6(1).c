#include<stdio.h>

int i,j,w,x,v,u,n,flag=0;
int visited[10],cost[10][10];

void dfs(int v)
{
	visited[v]=1;
	for(w=1;w<=n;w++)
	{
		if(cost[v][w] && visited[w]==0)
		dfs(w);
	}
}
void main()
{
	
	
	printf("\nEnter the number of vertices:\n");
	scanf("%d",&n);
	printf("Enter the cost of matrix::\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&cost[i][j]);
	printf("\nEnter the source of the matrix: ");
	scanf("%d",&x);
	dfs(x);
	
    for (i=1;i<=n;i++)
	{
		if(visited[i]==0)
		flag=1;
	}
	
	if(flag==0)
	printf("\nThe graph is connected!!!!\n");
	else
	printf("\nThe graph is not connected\n");
	printf("--------------------------");
	getch();
	
}
