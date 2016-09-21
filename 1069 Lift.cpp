#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int T, ur_pos, lift_pos, n, value, i, j;
    cin>>T;
    for(i=1; i<=T; i++){
        cin>>ur_pos>>lift_pos;
        if(ur_pos>lift_pos){
            n = ur_pos - lift_pos;
        }
        else if(lift_pos>ur_pos){
            n = lift_pos - ur_pos;
        }
        else{
            n = 0;
        }
        value = ((n+ur_pos)*4) + 19;
        cout<< "Case " << i << ": " << value <<endl;
    }

    return 0;
}
