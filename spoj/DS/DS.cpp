using namespace std;
#include <bits/stdc++.h>
bool dd[100000];
const int N=1e5+1;
int dem=0;
vector <int> adj[N];
void dfs(int k)
{
  dd[k]=1;
  for (int i=0;i<adj[k].size();++i)
  {
      int v=adj[k][i];
      if (dd[v]==0)
          {
              dem++;
              dfs(v);
          }
  }

}
int main()
{
    int n,k;
    freopen("DS.inp","r",stdin);
    freopen("DS.out","w",stdout);
    cin>>n>>k;
    int m,u;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
    for (int j=1;j<=m;++j)
    {
        cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    }
    dfs(k);
    cout<<dem+1<<endl;
    for (int i=1;i<=n;i++)
    {
        if (dd[i]==1) cout<<i<<" ";
    }
}
