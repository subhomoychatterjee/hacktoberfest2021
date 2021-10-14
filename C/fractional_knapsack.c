#include<stdio.h>
struct knap
{
	int p,w;
	float r;
};
float FKNAP(int n,struct knap[],float);
void main()
{
	struct knap k[10];
	int n,i;
	printf("Enter the no of product : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter profit and weight of product %d : ",i);
		scanf("%d%d",&k[i].p,&k[i].w);
		k[i].r=(float)k[i].p/k[i].w;
	}
	
	float W=10;
	printf("\nmaximum profit : %f",FKNAP(n,k,W));
			
}
float FKNAP(int n,struct knap k[],float W)
{
	int i,j;
	struct knap t;
	float x[10]={0},p=0;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(k[j].r<k[j+1].r)
			{
				t=k[j];
				k[j]=k[j+1];
				k[j+1]=t;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(k[i].w<W)
		{
			p+=k[i].p;
			W-=k[i].w;
		}
		else
			break;
	}
	
	if(i<n)
	{
		x[i]=W/k[i].w;
		p+=k[i].p*x[i];
		return p;
	}
}
	

