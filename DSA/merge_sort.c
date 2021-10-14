#include<stdio.h>
int a[10];

void merge_sort(int l,int u)
{
        int m;
        if(l<u)
        {
            m=(l+u)/2;
            merge_sort(l,m);
            merge_sort(m+1,u);
            merge(l,m,u);
        }
}

void merge(int l,int m,int u){
    int i,j,k,t;
    i=j=l;
    k=m+1;
    int b[10];

    while(j<=m && k<=u)
    {
        if(a[j]>a[k])
            b[i++]=a[k++];
        else
            b[i++]=a[j++];
    }
    if(k>u)
    {
        for(t=j;t<=m;t++)
            b[i++]=a[t];

    }
    else
    {
        for(t=k;t<=u;t++)
            b[i++]=a[t];
    }
    for(t=l;t<=u;t++)
        a[t]=b[t];
}


void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");

}
void main()
{
    int i,n;
    printf("Enter array length:");
    scanf("%d",&n);
    printf("Enter the elements for sorting:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    merge_sort(0,n-1);
    printf("The sorted array is:\n");
    print(a,n);
}
