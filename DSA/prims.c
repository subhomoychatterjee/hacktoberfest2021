#include<stdio.h>
void main()
{
	int i,j,u,v,w,G[20][20],V,E;
	printf("Enter no. of vertex and Edges : ");
	scanf("%d%d",&V,&E);
	printf("Enter source,dest and weight :\n");
	for(i=1;i<=V;i++)
	{
		for(j=1;j<=V;j++)
			G[i][j]=99;
	}
	for(i=1;i<=E;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
	}
	printf("Reqd. MST :\n");
	prims(G,V,E);
}
void prims(int G[][20],int V,int E)
{
	int k=0,vis[20]={0},i,j,u,v,c=0,min;
	vis[1]=1;
	while(k<V-1)
	{
		min=99;
		for(i=1;i<=V;i++)
		{
			for(j=1;j<=V;j++)
			{
				if(G[i][j]<min && vis[i]==1 && vis[j]==0)
				{
					min=G[i][j];
					u=i;
					v=j;
				}
			}
		}
		printf("\n%d %d",u,v);
		c+=min;
		vis[v]=1;
		k++;
	}
}
						