#include<stdio.h>
void warsh(int p[8][8],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
if(p[i][k]==1)
for(j=1;j<=n;j++)
p[i][j]=p[i][j]||p[k][j];
}
main() 
{
int i,j,n,a[8][8];
printf("\nTransitive closure using Warshall's algorithm");
printf("Enter number of vertices");
scanf("%d",&n);
printf("Enter adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
warsh(a,n);
printf("Transitive closure is \n\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%d",a[i][j]);
printf("\n");
}
}
