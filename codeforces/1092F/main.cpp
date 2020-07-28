#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
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
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 2e5 + 5;
    vector <int> adj[N];
    vector <int> topo;
    int a[N],dad[N];
    ll f[2][N],g[N],cnt[N];
    int n;
    ll ans = 0;

    void dfs(int u,int par){
        cnt[u] = a[u];
        for(int v : adj[u]){
            if(v == par){
                continue;
            }
            dad[v] = u;
            dfs(v,u);
            cnt[u] += cnt[v];
        }
        topo.emplace_back(u);
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1,1);
        for(int i = 0;i < sz(topo);++i){
            int u = topo[i];
            for(int v : adj[u]){
                if(v != dad[u]){
                    f[0][u] += f[0][v];
                }
            }
            f[0][u] += cnt[u];
        }
        for(int u = 1;u <= n;++u){
            f[0][u] -= cnt[u];
        }
        for(int i = sz(topo) - 2;~i;--i){
            int u = topo[i];
            int w = dad[u];
            f[1][u] = f[1][w] + f[0][w] - f[0][u] - cnt[u] + cnt[1] - cnt[u];
        }
        for(int u = 1;u <= n;++u){
            maximize(ans,f[0][u] + f[1][u]);
        }
        cout<<ans;
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