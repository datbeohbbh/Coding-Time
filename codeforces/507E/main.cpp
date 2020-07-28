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
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    vector <pii> adj[N];
    vector <int> vertices[N];
    int n,m;
    int x[N],y[N],z[N];
    int prev[N];
    int f[N],dist[N];

    queue <int> q;
    void bfs(int src){
        q.emplace(src);
        vector <bool> vis(n + 1);
        vis[src] = true;
        for(;q.size() > 0;q.pop()){
            int top = q.front();
            vertices[dist[top]].emplace_back(top);
            for(pii e : adj[top]){
                int v = e.first;
                if(!vis[v]){
                    dist[v] = dist[top] + 1;
                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }

    void solve(){
        int cntOne = 0;
        cin>>n>>m;
        for(int i = 1;i <= m;++i){
            cin>>x[i]>>y[i]>>z[i];
            cntOne += z[i];
            adj[x[i]].emplace_back(make_pair(y[i],i));
            adj[y[i]].emplace_back(make_pair(x[i],i));
        }
        bfs(1);
        int maxDist = *max_element(dist + 1,dist + 1 + n);
        fill(f + 1,f + 1 + n,-1);
        f[1] = 0;
        for(int len = 1;len <= maxDist;++len){
            for(int u : vertices[len]){
                for(pii e : adj[u]){
                    int v = e.first;
                    int state = z[e.second];
                    if(dist[u] == dist[v] + 1){
                        if(f[u] < f[v] + state){
                            f[u] = f[v] + state;
                            prev[u] = e.second;
                        }
                    }
                }
            }
        }
        cout<<dist[n] + cntOne - (f[n] << 1)<<'\n';
        vector <bool> vis(m + 1);
        for(int u = n;u;){
            vis[prev[u]] = true;
            u = (x[prev[u]] != u ? x[prev[u]] : y[prev[u]]);
        }
        for(int i = 1;i <= m;++i){
            if(vis[i]){
                if(!z[i]) {
                    cout << x[i] << ' ' << y[i] << ' ' << 1 << '\n';
                }
            }  else {
                if(z[i]){
                    cout << x[i] << ' ' << y[i] << ' ' << 0 << '\n';
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}