#include<stdio.h>
int NN,i,count=0;
int p[100],pi[100];
int dir[100];
void print()
{int i;
count=count+1;
printf("[%d]",count);
for(i=1;i<=NN;++i)
printf("%d",p[i]);
}
void print_trans(int x,int y)
{
printf("(%d,%d)",x,y);
printf("\n");
}
void move(int x,int d)
{
int z;
print_trans(pi[x],pi[x]+d);
z=p[pi[x]+d];
p[pi[x]]=z;
p[pi[x]+d]=x;
pi[z]=pi[x];
pi[x]=pi[x]+d;
}
void permu(int n)
{
int i;
if(n>NN)
print();
else
{
permu(n+1);
for(i=1;i<=n-1;++i)
{
move(n,dir[n]);
permu(n+1);
}
dir[n]=-dir[n];
}
}
void main()
{
printf("Enter n");
scanf("%d",&NN);
printf("\n");
for(i=1;i<=NN;i++)
{
dir[i]=-1;
p[i]=i;
pi[i]=i;
}
permu(1);
printf("\n");
}
