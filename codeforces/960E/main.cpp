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

const long long MOD = 1e9 + 7;

template <class T,class U>
T addmod(T x,U k){
    return ((x + k) % MOD + MOD * MOD) % MOD;
}
template <class T,class U>
T submod(T x,U k){
    return ((x - k) % MOD + MOD * MOD) % MOD;
}
template <class T,class U>
T mul(T x,U y){
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
    int v[N],dad[N],child[N];
    ll f[N][2];
    ll g[N][2];
    int n;

    void dfs(int u,int par){
        child[u] = 1;
        for(int v : adj[u]){
            if(v ^ par){
                dad[v] = u;
                dfs(v,u);
                child[u] += child[v];
            }
        }
        topo.emplace_back(u);
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>v[i];
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1,1);
        for(int i = 0;i < topo.size();++i){
            int u = topo[i];
            f[u][0] = 1LL * child[u] * 1LL * v[u];
            f[u][1] = -1LL * child[u] * 1LL * v[u];
            for(int v : adj[u]){
                if(v != dad[u]){
                    f[u][0] = addmod(f[u][0],f[v][1]);
                    f[u][1] = addmod(f[u][1],f[v][0]);
                }
            }
        }
        for(int i = topo.size() - 2;~i;--i){
            int u = topo[i];
            int w = dad[u];
            g[u][0] = addmod(1LL * v[u] * 1LL * (n - child[w]),addmod(1LL * v[w] * 1LL * child[u],1LL * v[u] * 1LL * (child[w] - child[u])));
            g[u][0] = addmod(g[u][0],addmod(g[w][1],submod(f[w][1],f[u][0])));
            g[u][1] = addmod(-1LL * v[u] * 1LL * (n - child[w]),addmod(-1LL * v[w] * 1LL * child[u],-1LL * v[u] * 1LL * (child[w] - child[u])));
            g[u][1] = addmod(g[u][1],addmod(g[w][0],submod(f[w][0],f[u][1])));
        }
        ll ans = 0;
        for(int u = 1;u <= n;++u){
            ans = addmod(ans,addmod(f[u][0],g[u][0]));
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