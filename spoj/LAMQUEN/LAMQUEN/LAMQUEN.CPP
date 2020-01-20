#include <bits/stdc++.h>
using namespace std;

const int N=1e3+3;
vector <int> adj[N];
int n;
bool dd[N];

void dfs(int u)
{
    dd[u]=1;
    for(int i=0;i<adj[u].size();++i)
    {
        int v=adj[u][i];
        if(dd[v]==0)
            dfs(v);
    }
}

int main()
{
    freopen("LAMQUEN.inp","r",stdin);
    freopen("LAMQUEN.out","w",stdout);
    cin>>n;
    int x,y;
    while(cin>>x>>y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int dem=0;
    for(int i=1;i<=n;++i)
        if(dd[i]==0)
    {
        dfs(i);
        dem++;
    }
    if(dem > 1)cout<<0;
    else cout<<1;
}
