#include<stdio.h>
int n;
int m;
int G[10][10],x[10],flag=0,c=0;

void print_colour()
{
    int i;
    flag=1;
    c++;
    printf("Solution no %d :",c);
    for(i=1;i<=n;i++)
    printf("%d  ",x[i]);
    printf("\n");
}

void next_colour(int k)
{
    int i,j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1;j<=n;j++)
        {
            if(G[j][k]!=0 && (x[k]==x[j]))
            break;
        }
        if(j==n+1)
            return;

    }
}
void gcolouring(int k)
{
    while(1)
    {
        next_colour(k);
        if(x[k]==0)
            return;
        if(k==n)
            print_colour();
        else
            gcolouring(k+1);
    }

}
void main()
{
    printf("enter the no. of vertices:");
    scanf("%d",&n);
    int i,j,e;
    m=n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            G[i][j]=0;

    }
    printf("Enter the no. of edges:");
    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
        int s,d;
        printf("Enter the no. of target vertices and edges:");
        scanf("%d%d",&s,&d);
        G[s][d]=G[d][s]=1;

    }

    for(i=1;i<=n;i++)
        x[i]=0;


    for(m=1;m<n;m++)
    {
    gcolouring(1);
    if(flag==1)
    {
    printf("Minimum number of colors required:%d\n",m);
    break;
    }
    }
}
