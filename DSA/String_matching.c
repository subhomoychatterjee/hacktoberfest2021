#include<stdio.h>
#include<string.h>
void main()
{
    char s[100];
    char m[50];

    printf("Enter the string::");
    gets(s);
    printf("Enter the match:");
    gets(m);
    int lens =strlen(s);
    int lenm =strlen(m);
    int i,j,st;
    int f=1;
    for(i=0;i<=lens;)
    {
        if(s[i]!=m[0])
            i++;
        else
        {
            i=i+1;
            st=i;
            for(j=1;j<=lenm;j++)
            {
                if(s[i]==m[j])
                    i++;
                else
                {
                    i=i+1;
                    break;
                }
            }
            if(j==lenm)
            {
                printf("Match found from location:: %d\n",(st));
                f=0;

            }
        }
    }
    if(f)
        printf("::No match found::\n");
}
