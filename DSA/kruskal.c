#include<stdio.h>
void bubble_sort();
int find(int);
void link(int,int);
void kruskal();
struct kruskal
{
  int u,v,w;
 }s[10],t;
 int V,E;
 int p[10],r[10]={0};
 main()
 {
   int i;
   printf("Enter the vertex : ");
   scanf("%d",& V);
   printf("Enter the edge : ");
   scanf("%d",& E);
   for(i=1;i<=V;i++)
   		p[i]=i;
   printf("enter source,dest vertex & weight :\n");
   for(i=1;i<=E;i++)
   {
     //printf("enter source vertex :");
     scanf("%d",& s[i].u);
     //printf("Enter the destination vertex: ");
     scanf("%d",& s[i].v);
     //printf("Enter the weight : ");
     scanf("%d",& s[i].w);
    }
    bubble_sort();
    kruskal();
  }

 void bubble_sort()
 {
   int i,j;
   for(i=1;i<=E;i++)
   {
      for(j=1;j<=E-i;j++)
      {
        if(s[j].w>s[j+1].w)
        {
          t=s[j];
          s[j]=s[j+1];
          s[j+1]=t;
         }
       }
     }
  }

int find(int x)
 {
   if(x!=p[x])
      x=find(p[x]);
      return x;
  }

void link(int x,int y)
 {
   if(r[x]>r[y])
   		p[y]=x;
   else
   		p[x]=y;
   if( r[x]==r[y] && (x!=y) )
   		r[y]=r[y]+1;
  }

void kruskal()
{
   int j,m,n,c=0;
   for(j=1;j<=E;j++)
   {
   	//printf("\n%d %d",s[j].u,s[j].v,s[j].w);
     m=find(s[j].u);
     n=find(s[j].v);
     if(m!=n)
     {
       link(m,n);
       printf("%d %d \n",s[j].u, s[j].v);
       c=c+s[j].w;
     }
   }
   printf("Total =  %d",c);
 }
