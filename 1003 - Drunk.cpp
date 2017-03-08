    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include <cstring>
    #include <cstdio>
     
    using namespace std;
     
    int N; // N nodeNumber
    typedef vector < vector < int> > G;
    map < string, int> myMap;
     
    enum { WHITE, GRAY, BLACK} color[20001];
     
    bool visit( G &adj,  int i){                        // similar to DFS_visit
        color[i] = GRAY;
        vector <int>:: iterator it;
     
        for( it=adj[i].begin(); it!=adj[i].end(); it++)
            if( color[ *it] == GRAY) return true;
            else if( color[ *it] == WHITE)
                if( visit( adj, *it)) return true;
        color[i] = BLACK;
        return false;
    }
     
    bool containsCycle( G &adj){                        // similar to DFS
        int i;
        for( i=1; i<=N; i++) color[i] = WHITE;
        for( i=1; i<=N; i++)
            if( color[i] == WHITE)
                if( visit( adj, i)) return true;
     
        return false;
    }
     
    int main(){
        //freopen("in.txt","r",stdin);
     
        int caseNo, T, i, m;
        string a, b;
        cin >> T;
     
        for( caseNo=1; caseNo<=T; caseNo++){
            cin >> m;
            N = 0;
            G adj( 2*m+1);
            myMap.clear();
     
            for( i=1; i<=m; i++){
                cin >> a >> b;
                if( !myMap[a]) myMap[a] = ++N;
                if( !myMap[b]) myMap[b] = ++N;
                adj[ myMap[a]].push_back( myMap[b]);
            }
            string s = containsCycle( adj) ? "No" : "Yes";      // If contains cycle, Impossible to get drunk
            cout << "Case " << caseNo << ": " << s << endl;
        }
        return 0;
    }
