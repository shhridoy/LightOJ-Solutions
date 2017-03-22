#include<bits/stdc++.h>
#define fi(n, m)     for(int i=n; i<=m; i++)
#define fii(i, n, m) for(int i=n; i<=m; i++)
using namespace std;
vector<int>vt[20009];
int vis[20009], s, cnt, pr[20009], sts[20009];

void dfs(int at){
    if(vis[at]) return ;
    else{
        vis[at]=1;
        sts[at]=sts[pr[at]]*(-1); //if parent=-1 then child=1;
        cnt++;
        s=s+sts[at];
        fii(i, 0, vt[at].size()-1){
            int v=vt[at][i];
            if(!vis[v]) pr[v]=at;
            dfs(v);
        }
    }
}

int main(){
    int t, n, cs=1, mx, a, b, ans;
    cin>>t;
    while(t--){
        set<int>st;
        set<int>::iterator it;
        mx=0, ans=0;
        cin>>n;
        fi(1, n){
            cin>>a>>b;
            vt[a].push_back(b);
            vt[b].push_back(a);
            st.insert(a);
            st.insert(b);
            mx=max(mx, max(a, b));
        }
        fi(0, mx){
            vis[i]=0, pr[i]=i, sts[i]=0;
        }
        for(it=st.begin(); it!=st.end(); it++){
            cnt=0, s=0;
            if(vis[*it]==0){
                sts[*it]=1;
                dfs(*it);
                if(s<0) s=s*(-1);
        //technique to find maximum Vampires/Lykans
                s=(cnt+s)/2;
                ans=ans+s;
            }
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(it=st.begin(); it!=st.end(); it++){
            vt[*it].clear();
        }
    }
    return 0;
}
