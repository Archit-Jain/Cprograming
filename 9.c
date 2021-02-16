//topological sort usin dfs stack
  /*Logic:traverse given graph using dfs(but explicit stack 
    used ,not recursion to enable checking contents of stack, 
    to check for cyclicity),note the order of pop in array 
    pop[],topo order is reverse of order of pop*/ 




  #include<stdio.h>
 #include<stdlib.h>  
  int j=0,pop[10],vis[10];


  int dfs(int u,int n,int a[][10])
  {
     int i,v,top=-1,s[10];
     vis[u]=1;
     s[++top]=u;
     while(top!=-1)
     {
	 for(v=1;v<=n;v++)
	 {
	    if(a[u][v]==1&&vis[v]==1)
	    {
	       for(i=top;i>=0;i--)
		  if(s[i]==v)
		  {
		    printf("topo not poss\n\n");
		    
		    exit(0);
		  }
	    }
	    if(a[u][v]==1&&vis[v]==0)
	    {
	      vis[v]=1;
	      s[++top]=v;
	      u=v;
	      v=0;
	    }
	 }
	 j++;
	 pop[j]=u;
	 top--;
	 u=s[top];
     }
}


   void topo(int n,int a[][10])
    {
       int i,u;
       for(i=1;i<=n;i++)
       vis[i]=0;
       for(u=1;u<=n;u++)
       {
	   if(vis[u]==0)
	      dfs(u,n,a);
       }
    }





   int main()
   {
	int i,k,n,a[10][10];
	printf("\nTOPOLOGICAL SORTING\n");
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix::\n");
	for (i=1;i<=n;i++)
	for (k=1;k<=n;k++)
	{
	 scanf("%d",&a[i][k]);
	}
	topo(n,a);
	printf("\ntopo order is\n");
	for(i=n;i>0;i--)
	   printf(" %d",pop[i]);
	
	
	getch();
  }
