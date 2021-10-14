#include<stdio.h>
#define MAX 100
int j[MAX];
int job_sequence(int d[],int n)
{
    int i,k=1,r,q;
    d[0]=j[0]=0;
    j[1]=1;
    for(i=2;i<=n;i++)
    {
        r=k;
        while(d[j[r]]>d[i] && d[j[r]]!=r)
        r=r-1;
        if(d[j[r]]<=d[i] && d[i]>r)
        {
            for(q=k;q<=r+1;q++)
            {
                j[q+1]=j[q];
            }
                j[r+1]=i;
                k=k+1;


        }
     }
    return k;


}
void main()
{
    int i,n,k,c,p[MAX],d[MAX];
    printf("Enter the no. of jobs:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the no. of profit and deadlines :");
        scanf("%d%d",&p[i],&d[i]);
        }
    k=job_sequence(d,n);
    printf("no. of selected jobs are:%d\n",k);
    printf("Job sequence is:\t");
    for(i=1;i<=k;i++)
        printf("%d\t",j[i]);
    printf("\n");
    //for(i=1;i<=k;i++){
        //c=c+p[j[i]];
        //printf("%d",j[i]);
        //printf("\n");

}
