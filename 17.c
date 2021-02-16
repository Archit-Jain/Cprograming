//time and space is Q(nk) and optimal sol Q(n+k)
#include<stdio.h>
int max(int a,int b)
{
return (a>b?a:b);
}
void knapsack(int n,int m,int w[20],int v[20][20],int p[20])
{
 int i,j;
	 for(i=0;i<=n;i++)
	{
           for(j=0;j<=m;j++)
             {
                if(i==0||j==0)
                 	v[i][j]=0;
		else if(w[i]>j)
          		v[i][j]=v[i-1][j];
		else
          		v[i][j]=max(v[i-1][j],(v[i-1][j-w[i]]+p[i]));
              printf("%d\t",v[i][j]);
	     }
          printf("\n");
	}
}


void print_optimal_solution(int n,int m,int w[20],int v[20][20])
{
 int i,j,x[10];
 printf("\n\n\n optimal solution is %d\n",v[n][m]);
	 for(i=0;i<n;i++)
		 x[i]=0;
 i=n;
 j=m;
 printf("\n obj to be selelcted");

	while(i!=0 && j!=0)
	{
           if(v[i][j]!=v[i-1][j])
		{
		x[i]=1;
		printf(" obj%d of weight[%d]\n",i,w[i]);
		j=j-w[i];
		}
	   i=i-1;
	}
	}



int main()
{
    int m,n,i,j,p[20],w[20],v[20][20];
    printf("\n enter the number of objects:");
    scanf("%d",&n);
    printf("\n enter weights of %d objects:",n);
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    printf("\n enter profits respectively\n");
    for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
    printf("\n enter the capacity of knapsack\n");
    scanf("%d",&m);
    knapsack(n,m,w,v,p);
    print_optimal_solution(n,m,w,v);
                     
return 0;
}
