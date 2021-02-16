#include<stdio.h>

#include<stdlib.h>
void floid(int p[8][8],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	int i,j,n,a[8][8];
	
	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix :\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&a[i][j]);
		if(a[i][j]==0)
		 a[i][j]=999;
	}
	floid(a,n);
	printf("\nAll pair shortest path matrix : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%2d ",a[i][j]);
		printf("\n");
	}
 getch();	
}
