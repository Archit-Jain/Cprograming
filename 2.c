#include<stdio.h>

int count;
void select(int a[],int n)
{
	int pos,i,j,temp,small;
	for(i=0;i<n;i++)
	{
		small=a[i];
		pos=i;
	
	for(j=i+1;j<n;j++)
	{
		count++;
		if(a[j]<small)
		{
			count++;
			small=a[j];
			pos=j;
	
		}
    }
		temp=a[pos];
		a[pos]=a[i];
		a[i]=small;
	}

}

main()
{	float r1,r2,r3;
	int a[600],b[600],c[600],i,j,n,c1,c2,c3;
//	clrscr();
	printf("SELECTION SORT\n");
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter the elements one by one\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	count=0;
	select(a,n);
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
		select(a,i);
		c1=count;
		r1=(float)(c1)/(i*i);

		count=0;
		select(b,i);
		c2=count;
		r2=(float)(c2)/(i*i);
	
		count=0;
		select(c,i);
		c3=count;
		r3=(float)(c3)/(i*i);
		printf("\n%d\t%d\t%f\t%d\t%f\t%d\t%f",i,c1,r1,c2,r2,c3,r3);
	}
	printf("\n");
	getch();
}
