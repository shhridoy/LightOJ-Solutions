#include<stdio.h>
int main()
{
    int a,n,i,c,p,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&a);
        c=a/2;
        p=a-c;
        printf("%d %d\n",c,p);
    }
    return 0;
}
