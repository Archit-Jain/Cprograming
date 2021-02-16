#include<stdio.h>
#include<math.h>
int count;
int partition(int a[],int l,int h)
{
	int i,j,temp,key;
	key=a[l];
	i=l+1;
	j=h;
	while(1)
	{
		
		while(i<h && key>=a[i])
		{	
            i++;
            count++;
        }
                    
		while(key<a[j])
		{
                       	j--;
                        count++;
        }

		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
			return j;
		}
	}
}

void quicksort(int a[],int l,int h)
{

	int p;
	
	if(l<h)
	{
		p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}

int main()
{
	int a[600],b[600],c[600],i,j,c1,c2,c3,n;
	float r1,r2,r3;
	printf("QUICK SORT\n");
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	printf("\nEnter the elements one by one\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	count=0;
	quicksort(a,0,n-1);
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
		quicksort(a,0,i-1);
		c1=count;
		
        count=0;
		quicksort(b,0,i-1);
		c2=count;
		
        count=0;
		quicksort(c,0,i-1);
		c3=count;
		
		r1=(float)(c1)/(i*i);
		r2=(float)(c2)/(i*i);
		r3=(float)(c3)/(i*i);

		printf("\n%d\t%d\t%f\t%d\t%f\t%d\t%f",i,c1,r1,c2,r2,c3,r3);
		
	}
	printf("\n");  return 0;
}
