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

const int N=2e5+2;
vector <int> dp[2][N],pn[N],adj[N],child[N],pnode[N];
vector <int> maxpre,maxsuf;
vector <int> topo;
vector < vector <int> > pre[N],suf[N];
int pos[N],dad[N],a[N];
int n;

void dfs(int u,int par){
    for(auto v : adj[u]){
        if(v == par)continue;
        dad[v] = u;
        pos[v] = sz(child[u]);
        child[u].pb(v);
        dfs(v,u);
    }
    topo.pb(u);
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        int x;
        cin>>x;
        a[i] = x;
        for(int j = 2;j <= x;++j){
            if(x % j)continue;
            while(x % j == 0)
                x/=j;
            pn[i].pb(j);
        }
        if(x > 1)
            pn[i].pb(x);
        sort(all(pn[i]));
        pn[i].erase(unique(all(pn[i])),pn[i].end());
        int val = (pn[i].empty() ? 0 : 1);
        dp[0][i].resize(sz(pn[i]),val);
        dp[1][i].resize(sz(pn[i]),val);
    }
    for(int i = 1;i < n;++i){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    for(int i = 0;i < sz(topo) - 1;++i){
        int v = topo[i];
        int u = dad[v];
        for(int j = 0;j < sz(pn[u]);++j){
            vector <int> :: iterator it = lower_bound(all(pn[v]),pn[u][j]);
            if(it == pn[v].end())continue;
            if(*it == pn[u][j]){
                maximize(dp[0][u][j],dp[0][v][it - pn[v].begin()] + 1);
            }
        }
    }
    for(int u = 1;u <= n;++u){
        if(child[u].empty())continue;
        for(int j = 0;j < sz(child[u]);++j)
            for(int k = 0;k < sz(pn[child[u][j]]);++k)
                pnode[u].pb(pn[child[u][j]][k]);
        sort(all(pnode[u]));
        pnode[u].erase(unique(all(pnode[u])),pnode[u].end());
        maxpre.resize(sz(pnode[u]),0);
        maxsuf.resize(sz(pnode[u]),0);
        pre[u].resize(sz(child[u]),vector <int> ());
        suf[u].resize(sz(child[u]),vector <int> ());
        for(int j = 0;j < sz(child[u]);++j){
            int v = child[u][j];
            pre[u][j].resize(sz(pn[v]),0);
            for(int k = 0;k < sz(pn[v]);++k){
                vector <int> :: iterator it = lower_bound(all(pnode[u]),pn[v][k]);
                maximize(pre[u][j][k],maxpre[it - pnode[u].begin()]);
                maximize(maxpre[it - pnode[u].begin()],dp[0][v][k]);
            }
        }
        for(int j = sz(child[u]) - 1;~j;--j){
            int v = child[u][j];
            suf[u][j].resize(sz(pn[v]),0);
            for(int k = 0;k < sz(pn[v]);++k){
                vector <int> :: iterator it = lower_bound(all(pnode[u]),pn[v][k]);
                maximize(suf[u][j][k],maxsuf[it - pnode[u].begin()]);
                maximize(maxsuf[it - pnode[u].begin()],dp[0][v][k]);
            }
        }
        maxpre.clear();
        maxsuf.clear();
    }
    for(int i = sz(topo) - 2;~i;--i){
        int u = topo[i];
        int w = dad[u];
        for(int j = 0;j < sz(adj[w]);++j){
            int v = adj[w][j];
            if(v == dad[w])continue;
            for(int k = 0;k < sz(pn[v]);++k){
                vector <int> :: iterator it = lower_bound(all(pn[w]),pn[v][k]);
                if(it == pn[w].end())continue;
                if(*it == pn[v][k]){
                    maximize(dp[1][v][k],pre[w][pos[v]][k] + 1);
                    maximize(dp[1][v][k],suf[w][pos[v]][k] + 1);
                    maximize(dp[1][v][k],dp[1][w][it - pn[w].begin()]);
                }
            }
        }
    }
    int ans = 0;
    for(int u = 1;u <= n;++u)
        for(int k = 0;k < sz(pn[u]);++k)
            maximize(ans,dp[0][u][k] + dp[1][u][k] -  __gcd(a[u],a[dad[u]]) == 1);
    for(int i = 0;i < 2;++i)
        for(int u = 1;u <= n;++u)
            for(int j = 0;j < sz(pn[u]);++j){
                maximize(ans,dp[i][u][j]);
            }
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
