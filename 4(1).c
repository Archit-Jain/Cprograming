//n log n
#include<stdio.h>
#include<math.h>
int count;
void merge(int a[],int l,int m,int h)
{
	int i,j,k,c[10000];
	i=k=l;
	j=m+1;
	while(i<=m && j<=h)
	{
		count++;
		if(a[i]<a[j])
		c[k++]=a[i++];
		else
		c[k++]=a[j++];

	}
	while(i<=m)
	c[k++]=a[i++];
	while(j<=h)
	c[k++]=a[j++];
	for(i=l;i<k;i++)
	a[i]=c[i];
}

void mergesort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}

int main()
{
	int a[600],b[600],c[600],i,j,n;
	float r1,r2,r3;
    int c1,c2,c3;
	printf("MERGE SORT\n");
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter the elements one by one\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	count=0;
	mergesort(a,0,n-1);
	printf("\nArray after sorting : ");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
	printf("\nNo of counts : %d",count);
	
    printf("\n\nSize\t\tAsc\tDesc\tRandom\n");
	for(i=16;i<520;i*=2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		mergesort(a,0,i-1);
		c1=count;
		r1=c1/i;
		
		count=0;
		mergesort(b,0,i-1);
		c2=count;
		
		count=0;
		mergesort(c,0,i-1);
		c3=count;
		
		r1=(float)(c1)/i;
		r2=(float)(c2)/i;
		r3=(float)(c3)/i;

		printf("\n%d\t%d\t%f\t%d\t%f\t%d\t%f",i,c1,r1,c2,r2,c3,r3);
        
    }
	
	printf("\n");
    return 0;
}
