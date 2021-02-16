//Reachable using BFS
#include<stdio.h>
void bfs(int n,int a[10][10],int source,int visited[100])
{
int i,g[10],u;
int front=1,rear=1;
visited[source]=1;
g[rear]=source;
while(front<=rear)
{
u=g[front];
printf("-----%d-----",u);
front=front+1;
for(i=1;i<=n;i++)
{
if(a[u][i]==1&&visited[i]==0)
{
rear=rear+1;
g[rear]=i;
visited[i]=1;
}
}
}
}
int main()
{
int n,a[10][10],i,j,source,visited[10];
printf("Enter number of nodes\n");
scanf("%d",&n);
printf("\nEnter adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("Enter source node:\n");
scanf("%d",&source);
 
for(i=1;i<=n;i++)
visited[i]=0;

bfs(n,a,source,visited);

printf("\n");

getch();
}
