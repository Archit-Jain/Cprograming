#include<stdio.h>
#include<stdlib.h>

int c[20][20];

int min(int i,int k)
{
if(i<k)
return i;
else return k;
}

int bin(int n,int k)
{
int i,j;
for(i=0;i<=n;i++)
{
for(j=0;j<=min(i,j);j++)
{
if(j==0||j==i)
c[i][j]=1;
else
c[i][j]=c[i-1][j-1]+c[i-1][j];
}
}
return(c[n][k]);
}

main()
{
int n,i,j,k;
printf("\nEnter the value of n:");
scanf("%d",&n);
printf("\nEnter the value of k:");
scanf("%d",&k);
bin(n,k);
if(n<k)
printf("Not possible\n");
else
printf("\nThe binomial co-efficient of(%d,%d)is:%d",n,k,c[n][k]);
printf("\n-------------------------\n");
if(n>=k)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=k;j++)
if(c[i][j]!=0)
printf("%3d",c[i][j]);
printf("\n");
getch();
}
          }
}
