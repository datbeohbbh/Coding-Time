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
#define BIT(x,i) (((x)>>(i))&1LL)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    const int lg = 60;
    const int inf = 1e9;
    vector <int> comp[lg + 1];
    vector <pii> edges;
    vector <int> adj[N];
    int dist[N];
    bool vis[N];
    ll a[N];
    int n,ans = inf;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int j = 0;j <= lg;++j){
            for(int i = 1;i <= n;++i){
                if(BIT(a[i],j)){
                    comp[j].emp(i);
                }
            }
            if(sz(comp[j]) > 2){
                cout<<3,exit(0);
            } else if(sz(comp[j]) == 2){
                int u = comp[j][0],v = comp[j][1];
                adj[u].emp(v),adj[v].emp(u);
                edges.emp(mp(u,v));
            }
        }
        function <int(int,int)> bfs = [&](int src,int des){
            fill(dist + 1,dist + 1 + n,inf);
            fill(vis + 1,vis + 1 + n,false);
            queue <int> q;
            q.push(src);
            vis[src] = true;
            dist[src] = 1;
            for(;sz(q);q.pop()){
                int u = q.front();
                if(u == des){
                    return dist[u];
                }
                for(int i = 0;i < sz(adj[u]);++i){
                    int v = adj[u][i];
                    if(u == src and v == des)continue;
                    if(!vis[v]){
                        dist[v] = dist[u] + 1;
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            return inf;
        };
        for(int e = 0;e < sz(edges);++e){
            int u = edges[e].fir;
            int v = edges[e].sec;
            minimize(ans,bfs(u,v));
        }
        cout<<(ans == inf ? -1 : ans);
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
