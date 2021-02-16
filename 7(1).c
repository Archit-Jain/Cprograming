#include<stdio.h>
int i,j,x,v,u,n,flag=0;
int visited[10],cost[10][10];
void dfs(int v)
{
int w;
visited[v]=1;
for(w=1;w<=n;w++)
{
if(cost[v][w]&&visited[w]==0)
{	printf("%d   ",w);
dfs(w);
}
}
}

void main()
{
printf("\nEnter the no. of vertices:\n");
scanf("%d",&n);
printf("Enter the cost of matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&cost[i][j]);
while(1)
{
     
printf("Enter the source:");
scanf("%d",&x);


         
printf("\n\n\n\n\n\nThe reachable nodes are:");
dfs(x);
}
}

