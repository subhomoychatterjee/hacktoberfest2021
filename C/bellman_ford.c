#include<stdio.h>
#define INF 9999
/*struct sol
{
	int *d;
	int *par;
};*/

//struct sol  B_F(int[][],int[][],int,int,int);
//void B_F(int[][],int[][],int,int,int);
int d[10],par[10];
void main()
{
	int G[10][10],e[10][3],p[10],V,E,s,u,v,w,i,j,dest;
	printf("Enter the number of vertex & edge : ");
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
	printf("Enter starting & ending vertex and their cost :\n ");
	for(i=1;i<=E;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
		e[i][1]=u;
		e[i][2]=v;
	}
	printf("Enter starting vertex : ");
	scanf("%d",&s);
	B_F(G,e,s,V,E);
	printf("Minimum cost Matrix :\n");
	for(i=1;i<=V;i++)
		printf("%d\t",d[i]);
	printf("\n");
	printf("Parent Vertex Matrix :\n");
	for(i=1;i<=V;i++)
		printf("%d\t",par[i]);
	printf("\nEnter a destination vertex: ");
	scanf("%d",&dest);
	printf("%d ",s);
	//printf("\n b");
	path(s,dest);
	//printf("\n a");
	//path_iter(dest);
	
}

void  B_F(int G[][10],int e[][3],int s,int V,int E)
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
	for(i=1;i<=V-1;i++)
	{
		for(j=1;j<=E;j++)
		{
			if(d[v]>d[u]+G[u][v])
			printf("Neg. Cycle Present...");
		}
	}
	//s1.d=d;
	//return s1;
}

void path(int s,int t)
{
	if(s==t)
		return;
	if(s==par[t])
		printf(" - > %d ",t);
	else
	{
		path(s,par[t]);
		path(par[t],t);
	}
}	

void path_iter(int i)
{
	int j=1,p[10];
	p[0]=i;
	while(par[i]!=0)
	{
		p[j]=par[i];
		i=par[i];
		j++;
	}
	p[j]=par[i];
	printf(" %d",p[j-1]);
	for(i=j-2;i>=0;i--)
		printf(" -> %d",p[i]);

}
/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3
1
*/					
