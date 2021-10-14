#include<stdio.h>
int c=0;
void main()
{
	int n,x[20];
	printf("Enter no. of Queen :");
	scanf("%d",&n);
	nqueen(n,1,x);
}
void nqueen(int n,int k,int x[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(place(k,i,x))
		{
			x[k]=i;
			if(k==n)
				display(x,n);
			else
				nqueen(n,k+1,x);
		}
	}
}
int place(int k,int i,int x[])
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if(x[j]==i)
			return 0;
		if(abs(k-j)==abs(i-x[j]))
			return 0;
	}
	return 1;
}
void display(int x[],int n)
{
	printf("\n%d. :\n",++c);	
	int i,j;
	for(i=1;i<=n;i++)
		printf(" %d ",x[i]);
	printf("\n\n   ");
	for(i=1;i<=n;i++)
		printf(" %d ",i);
	printf("\n");	
	for(i=1;i<=n;i++)
	{
		printf(" %d ",i);	
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf(" Q ");
			else
				printf(" - ");	
		}
		printf("\n");
	}
}
		
