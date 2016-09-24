#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int T;
    long long W, odd, even;
    cin >> T;
    for(int i=1; i<=T; i++){
        scanf("%lld", &W);
        if(W%2 != 0){
            printf("Case %d: Impossible\n", i);
            continue;
        }
        odd = W/2;
        even = 2;
        while(odd%2 == 0){
            odd = odd / 2;
            even = even * 2;
        }
        printf("Case %d: %lld %lld\n", i, odd, even);
    }

    return 0;
}
