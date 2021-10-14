#include<stdio.h>
int a[30];			/****** Binary Search ******/
void main()
{
	int n,s,i;
	printf("enter array size : ");
	scanf("%d",&n);
	printf("enter elements :\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
									/*Sorting the array*/
	bsort(n);
	printf("sorted array : \n ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);

	printf("\nEnter search element : ");   /*Searching*/
	scanf("%d",&s);
	bs(0,n-1,s);

}
	
void bsort(int n)		 /*Bubble Sorting*/
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void bs(int l,int u,int s)  /*Binary Searching*/
{
	int m;
	while(l<=u)
	{
		m=(l+u)/2;
		if(a[m]==s)
		{
			printf("search Found at %d postion.....",m+1);
			break;
		}
		else if(a[m]>s)
			u=m-1;
		else
			l=m+1;
		
	}
	if(l>u)
		printf("OOPS!!!Search Not Found...");
}
