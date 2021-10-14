#include<stdio.h>
#define MAX 20
int V,E,G[10][10],vis[10]={0};
int s;
void input_graph()
{
    int i,j,u,v,w;
    printf("Enter the no. of vertices:");
    scanf("%d",&V);
    printf("Enter the no. of edges:");
    scanf("%d",&E);
    for(i=1;i<=V;i++)
        for(j=1;j<=V;j++)
          G[i][j]=99;

    printf("Enter the source,destination and weight respectively\n:");
    for(i=1;i<=E;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=w;
    }
    printf("Enter the source vertex:");
    scanf("%d",&s);
    printf("\n");

}


void Dijkstra()
{
    int i,d[MAX],c,min,u;
    for(i=1;i<=V;i++)
    {
        d[i]=G[s][i];
        vis[i]=0;

    }
    vis[s]=1;
    d[s]=0;
    c=1;
    while(c<V-1)
    {
        min=999;
        for(i=1;i<=V;i++)
        {
            if(d[i]<min && vis[i]==0)
            {
                min=d[i];
                u=i;

            }
        }
        vis[u]=1;
        for(i=1;i<=V;i++)
        {
            if(d[u]+G[u][i]<d[i] && vis[i]==0)
                d[i]=d[u]+G[u][i];
        }
        c++;
    }

    for(i=1;i<=V;i++)
        printf("%d ",d[i]);
    printf("\n");


}

void main()
{
    input_graph();
    Dijkstra();
}
