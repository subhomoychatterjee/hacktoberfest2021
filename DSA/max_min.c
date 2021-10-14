#include<stdio.h>
int max,min,a[10];

void max_min(int i,int j)
{
 int max1,min1,m;
 if(i==j)
 max=min=a[i];
 else
 {
    m=(i+j)/2;
    max_min(i,m);
    max1=max;
    min1=min;
    max_min(m+1,j);
    if(max1>max)
        max=max1;

    if(min>min1)
      min=min1;

 }
}

void main()
{
 int i,n;
 printf("Enter the size of array:");
 scanf("%d",&n);
 printf("Enter array elements:");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 max_min(0,n-1);
 printf("max is%d\n",max);
 printf("min is%d\n",min);

}
