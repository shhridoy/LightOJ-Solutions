#include<stdio.h>
int main()
{
    int a,b,c,d,sum=0;
    scanf("%d",&a);
    for(b=1;b<=a;b++){
        scanf("%d %d",&c,&d);
        sum=c+d;
        printf("Case %d: %d\n",b,sum);
    }

    return 0;
}
