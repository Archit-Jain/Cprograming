#include<stdio.h>
#include<stdlib.h>
int count=0;

int selection(int a[],int n)
{
	int i,j,temp,small,pos;

	for(i=0;i<n-1;i++)
	{
		small=a[i];
		pos=i;	
		for(j=i+1;j<n;j++)
		{
			count++;
			if(a[j]<small)
			{
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
{
	int i,j,k,n,temp,a[600],b[600],c[600],c1,c2,c3,pos;
	float r1,r2,r3;
	printf("enter the number of elements ");
	scanf("%d",&n);
	printf("enter the items to sort ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection(a,n);

	printf("\nsorted list is : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

	printf("size\tasc\tdsc\trandom\n");


	for(i=16;i<520;i=i*2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		selection(a,i);
		c1=count;
		
		count=0;
		selection(b,i);
		c2=count;
		
        count=0;
		selection(c,i);
		c3=count;
		
        r1=(float)(c1)/(i*i);
		r2=(float)(c2)/(i*i);
		r3=(float)(c3)/(i*i);

		printf("\n%d\t%d\t%f\t%d\t%f\t%d\t%f",i,c1,r1,c2,r2,c3,r3);
		
	}
	printf("\n");
	getch();
}


