#include<stdio.h>
int count;
void insert(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		for(j=i-1;j>=0;j--)
		{
			
			if(key<a[j])
			{
				count++;
				a[j+1]=a[j];
			}
			else
			{
				count++;
				break;
			}
		}
		a[j+1]=key;
	}
}
main()
{
	int a[600],b[600],c[600],i,j,n,c1,c2,c3;
//	clrscr();
	printf("INSERTION SORT\n");
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter the elements one by one\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	count=0;
	insert(a,n);
	printf("\nArray after sorting : ");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
	printf("\nNo of counts : %d",count);
	printf("\n\nSize\tAsc\tDesc\tRandom\n");
	for(i=16;i<520;i*=2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		insert(a,i);
		c1=count;
		
		count=0;
		insert(b,i);
		c2=count;
		
		count=0;
		insert(c,i);
		c3=count;
		
		printf("\n%d\t%d\t%d\t%d",i,c1,c2,c3);
	}
	printf("\n");
    getch();
}
