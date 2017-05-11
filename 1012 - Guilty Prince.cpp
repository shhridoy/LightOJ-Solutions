    #include<iostream>
    #include<cstdio>
    #include<vector>
    #include<queue>
    #include<cstring>
    #define max 25
     
    using namespace std;
     
    int cost[max][max],color[max][max];
     
    int X[4]= {1,-1,0,0};
    int Y[4]= {0,0,1,-1};
     
    int W,H,count=0;
    char mat[max][max];
     
    void bfs(int i,int j)
    {
        memset(cost,0,sizeof(cost));
        memset(color,0,sizeof(color));
     
        queue<int>Q;
        int ui,uj,vi,vj,k;
     
        Q.push(i);
        Q.push(j);
     
        cost[i][j] = 0;
        color[i][j] = 1;
     
        while(!Q.empty())
        {
     
            ui = Q.front();
            Q.pop();
     
            uj = Q.front();
            Q.pop();
     
           count++;
     
     
            for(k=0; k<4; k++)
            {
                vi = ui+X[k];
                vj = uj+Y[k];
     
                if((vi>=1&&vi<=H) && (vj>=1&&vj<=W) && (mat[vi][vj]!='#'))
                {
     
                    if(!color[vi][vj])
                    {
                        Q.push(vi);
                        Q.push(vj);
                        cost[vi][vj] = cost[ui][uj]+1;
                        color[vi][vj]=1;
                    }
     
                }
            }
        }
     
     
    }
     
    int main()
    {
        int i,j,k,n,cas,p;
        scanf("%d",&cas);
        for(k=1;k<=cas;k++)
        {
            p=0;
     
            scanf("%d%d",&W,&H);
     
            for(i=1;i<=H;i++)
            {
                for(j=1;j<=W;j++)
                {
                    scanf(" %c",&mat[i][j]);
                }
            }
     
            for(i=1;i<=H;i++)
            {
                for(j=1;j<=W;j++)
                {
                    if(mat[i][j]=='@')
                    {
                        bfs(i,j);
     
                        break;
                        p=1;
                    }
                }
                if(p)
                    break;
            }
     
            printf("Case %d: %d\n",k,count);
            count=0;
        }
     
        return 0;
     
    }
