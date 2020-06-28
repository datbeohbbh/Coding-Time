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
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const  int N = 2e5 + 5;
    vector <pii> adj[N];
    bool vis[N];
    int dad[N],edge[N];
    int f[2][N][3],sum[3][N];
    int n;
    vector <int> topo;

    void dfs(int u,int par){
        vis[u] = true;
        isleaf[u] = true;
        for(int i = 0;i < sz(adj[u]);++i){
            int v = adj[u][i].fir;
            int e = adj[u][i].sec;
            if(v == par)continue;
            dad[v] = u;
            edge[v] = e;
            dfs(v,u);
        }
        topo.pb(u);
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            int u,v,e;
            cin>>u>>v>>e;
            adj[u].pb(mp(v,e));
            adj[v].pb(mp(u,e));
        }
        dad[1] = 1;
        dfs(1,1);
        for(int j = 0;j < 2;++j){
            for(int u = 1;u <= n;++u){
                for(int k = 0;k < 3;++k){
                    f[j][u][k] = 1;
                }
            }
        }
        for(int i = 0;i < sz(topo) - 1;++i){
            int v = topo[i];
            int u = dad[v];
            if(!edge[v]){
                f[0][u][0] += f[0][v][0];
            } else {
                f[0][u][1] += f[0][v][1];
                f[0][u][2] += f[0][v][2] + f[0][v][0];
            }
        }
        for(int u = 1;u <= n;++u){
            for(int i = 0;i < sz(adj[u]);++i){
                int v = adj[u][i].fir;
                int e = adj[u][i].sec;
                if(v == dad[u])continue;
                sum[e][u] += f[0][v][e];
                if(e)sum[2][u] += f[0][v][2];
               }
            }
        for(int i = sz(topo) - 2;~i;--i){
            int u = topo[i];
            int w = dad[u];
            if(!edge[u]){
                f[1][u][0] += f[1][w][0] + sum[0][w] - f[0][u][0];
            } else {
                f[1][u][1] += f[1][w][1] + sum[1][w] - f[0][u][1];
                f[1][u][2] += f[1][w][2] + sum[2][w] + sum[0][w] - f[0][u][2] - f[0][u][0];
            }
        }
        for(int u = 1;u <= n;++u){
            for(int j = 0;j < 2;++j){
                ans += 1LL*f[0][u][j]*1LL*f[1][u][j] - 1;
                ans += (1LL*(sum[j][u] - 1)*1LL*sum[j][u]) / 2LL;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}