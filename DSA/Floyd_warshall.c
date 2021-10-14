#include<stdio.h>
#define MAX 100
int d[MAX][MAX],e[MAX][3];
void floyd_warshall(int n,int w[MAX][MAX])
{
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j]=w[i][j];
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    //return d;
}
void main()
{
    int w,i,j,u,v,V,E,G[MAX][MAX];
    printf("Enter the no of vertices and edeges:");
    scanf("%d%d",&V,&E);
    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            if(i==j)
                G[i][j]=0;
            else
                G[i][j]=9999;
        }
    }
    for(i=1;i<=E;i++)
    {
        printf("Enter source and destination edge and weight:");
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=w;
        e[i][1]=u;
        e[i][2]=v;
    }
    //printf("Enter the destinationn path:");
    //scanf("%d",&S);
    floyd_warshall(V,G);
    for(i=1;i<=V;i++){
            for(j=1;j<=V;j++)
                printf("%d\t",d[i][j]);
            printf("\n");
        }

}
