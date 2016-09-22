#include<iostream>
#include<stdio.h>
#include<math.h>
#define PI acos(0.0)*2
using namespace std;
int main()
{
    int T, a;
    double R, r, n, e, f, x, y, z;
    cin>> T;
    for(int i=1; i<=T; i++){
        scanf("%lf %lf", &R, &n);
        e = PI/n;
        x = sin(e);
        y = (R*x) / (1+x);
        a = (int)y;
        z = (y*1.0) / a;
        if(z != 1)
            printf("Case %d: %.10lf\n", i, y);
        else
            printf("Case %d: %.0lf\n", i, y);
    }

    return 0;
}
