#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return (long long)x*y%MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=3e5+5;
ll f[3][N];
int dad[N],len[N],w[N],pos[N];
vector <pii> adj[N];
vector <int> topo;
vector <ll> node[N],maxpre[N],maxsuf[N];
int n;

void dfs(int u,int par){
    for(auto cur : adj[u]){
        int v = cur.fir;
        if(v == par)continue;
        pos[v] = sz(node[u]);
        node[u].pb(v);
        dad[v] = u;
        len[v] = cur.sec;
        dfs(v,u);
    }
    topo.pb(u);
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i)
      cin>>w[i];
    for(int i = 1;i < n;++i){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].pb(mp(v,c));
        adj[v].pb(mp(u,c));
    }
    dfs(1,1);
    for(int u = 1;u <= n;++u)
        f[0][u] = f[1][u] = f[2][u] = 1LL*w[u] - 1LL*len[u];
    for(int i = 0;i < sz(topo) - 1;++i){
        int v = topo[i];
        int u = dad[v];
        maximize(f[0][u],f[0][v] + 1LL*w[u] - 1LL*len[u]);
    }
    for(int u = 1;u <= n;++u){
        if(node[u].empty())continue;
        maxpre[u].resize(sz(node[u]),0);
        maxsuf[u].resize(sz(node[u]),0);
        for(int j = 0;j < sz(node[u]);++j){
            maxpre[u][j] = maxsuf[u][j] = f[0][node[u][j]];
        }
        for(int j = 1;j < sz(node[u]);++j){
            if(maxpre[u][j] < maxpre[u][j - 1])
              maxpre[u][j] = maxpre[u][j - 1];
        }
        for(int j = sz(node[u]) - 2;~j;--j){
            if(maxsuf[u][j] < maxsuf[u][j + 1])
              maxsuf[u][j] = maxsuf[u][j + 1];
        }
    }
    for(int i = sz(topo) - 2;~i;--i){
        int t = topo[i];
        int ww = dad[t];
        if(pos[t] - 1 >= 0)
           maximize(f[1][t],maxpre[ww][pos[t] - 1] + 1LL*w[ww] + 1LL*w[t] - 1LL*len[t]);
        if(pos[t] + 1 < sz(node[ww]))
           maximize(f[1][t],maxsuf[ww][pos[t] + 1] + 1LL*w[ww] + 1LL*w[t] - 1LL*len[t]);
        maximize(f[1][t],f[1][ww] + w[t] - 1LL*len[t]);
    }
    for(int i = sz(topo) - 2;~i;--i){
        int t = topo[i];
        int ww = dad[t];
        if(pos[t] - 1 >= 0)
           maximize(f[2][t],maxpre[ww][pos[t] - 1] + f[0][t] + 1LL*w[ww]);
        if(pos[t] + 1 < sz(node[ww]))
           maximize(f[2][t],maxsuf[ww][pos[t] + 1] + f[0][t] + 1LL*w[ww]);
        maximize(f[2][t],f[1][ww] + f[0][t]);
    }
    ll ans = 0;
    for(int u = 1;u <= n;++u)
        for(int j = 0;j < 3;++j)
          maximize(ans,f[j][u] + (j == 0)*1LL*len[u]);
    cout<<ans;
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
