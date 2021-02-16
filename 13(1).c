//worst=(theta)(mn) other cases (theta)=(m)


#include<stdio.h>
#include<string.h>
#define MAX 500
char str[100],ptr[20];
int t[MAX];
void shifttable(char p[])
{	int i,j,m;
	m=strlen(p);
	for(i=0;i<MAX;i++)
		t[i]=m;
	for(j=0;j<m-1;j++)
		t[p[j]]=m-1-j;
}
int horspool(char p[],char src[])
{	int k,i,j,m,n;
	shifttable(p);	 
	 m=strlen(p);
	 n=strlen(src);
	 i=m-1;
	 while(i<n)
	 {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
			k++;
		if(k==m)
			return(i-m+1);
		else
			i=i+t[src[i]];
	 }
	 return -1;
}
void main()
{
	char src[100],p[100];
	int pos;	
	printf("\n Enter the text : ");
	scanf("%[^\n]",src);
	printf("\n Enter the pattern : ");
	gets(p);
	
	pos=horspool(p,src);
	if(pos==-1)
	printf("\n String pattern nt  found");
	else
	printf("\n String pattern found:%d\n",pos+1);
	
}
