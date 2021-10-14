#include <stdio.h>
int g[100][100];
int e[100][2];
int v;int E;
void relax()
{	

	int d[100];
	d[1]=9999;
	d[2]=0;
	for(int i=3;i<=v;i++)
		d[i]=9999;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=E;j++)
		{
			int s=e[j][j];
			int v=e[j][j+1];
			int c=g[s][v];

			if(d[s]+c<d[v])
				d[v]=d[s]+c;
		}
	}
	printf("\nSolution\n");
	for(int i=1;i<=v;i++)
		printf("%d\n",d[i]);
}
void main()
{
	
	printf("Enter number of vertices :: ");
	
	scanf("%d",&v);

	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			if(i==j)
				g[i][j]=0;
			else
				g[i][j]=-9999;
		}
	}

	printf("Enter the number of edges :: ");
	
	scanf("%d",&E);
	printf("Enter source,destination vertex along with the cost seperated by space ::\n");
	for(int i=1;i<=E;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[i][i]=a;
		e[i][i+1]=b;
		g[a][b]=c;
	}
	relax();
	/*for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			printf("%d  ",g[i][j]);
		}
		printf("\n");
	}*/

}