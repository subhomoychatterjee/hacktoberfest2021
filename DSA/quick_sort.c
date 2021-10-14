#include<stdio.h>
int a[30];
void main()   /*Quick Sort*/
{
	int n,i;
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("enter elements...\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	q_sort(0,n-1);
	printf("Sorted array....\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void q_sort(int l,int u)
{
	int q;
	if(l<u)
	{
		q=partition(l,u);
		q_sort(l,q-1);
		q_sort(q+1,u);
	}
}
int partition(int l,int u)
{
	int i,j;
	int x=a[u];
	i=l-1;
	for(j=l;j<u;j++)
	{
		if(a[j]<x)
		{
			i++;
			swap(i,j);
		}
	}
		swap(i+1,u);
	return (i+1);
}

void swap(int i,int j)
{
	int t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}

