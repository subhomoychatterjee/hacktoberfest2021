#include<stdio.h>
#define INF 9999
/*struct sol
{
	int *d;
	int *par;
};*/

//struct sol  B_F(int[][],int[][],int,int,int);
//void B_F(int[][],int[][],int,int,int);
int d[40][40];
void main()
{
	
	int G[10][10],V,E,s,u,v,w,i,j,dest;
	//int path[10];
	printf("Enter no. of vertex & Edges : ");
	scanf("%d%d",&V,&E);
	for(i=1;i<=V;i++)
	{
		for(j=1;j<=V;j++)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=INF;
		}
	}
	printf("Enter starting ,desination & weight :\n");
	for(i=1;i<=E;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
	}
	//scanf("%d",&s);
	//B_F(G,e,s,V,E);
	F_W(G,V);
	printf("Shortest Path matrix :\n");
	for(i=1;i<=V;i++)
	{
		for(j=1;j<=V;j++)
			printf("%d\t",d[i][j]);
		printf("\n");
	}
	
	/*sprintf("\n");
	for(i=1;i<=V;i++)
		printf("%d\t",par[i]);
	scanf("%d",&dest);
	i=dest;
	j=1;
	path[0]=i;
	while(par[i]==0)
	{
		path[j]=par[i];
		i=par[i];
		j++;
	}
	path[j]=par[i];
	for(i=j;i>=0;i--)
		printf("%d -> ",path[i]);
	*/
	
}
void F_W(int G[][10],int V)
{
	int n=V;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			d[i][j]=G[i][j];
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	//return d;
}	







/*void  B_F(int G[][10],int e[][3],int s,int V,int E)
{
	int i,j,u,v;
	//struct sol s1;
	
	for(i=1;i<=V;i++)
	{
		d[i]=INF;
	}

	d[s]=0;
	for(i=1;i<=V-1;i++)
	{
		for(j=1;j<=E;j++)
		{
			u=e[j][1];
			v=e[j][2];
			if(d[v]>d[u]+G[u][v])
			{
				d[v]=d[u]+G[u][v];
				par[v]=u;
			}
		}
	}
	if(d[v]>d[u]+G[u][v])
		printf("Neg. Cycle Present...");
	//s1.d=d;
	//return s1;
}*/
						
