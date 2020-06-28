#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

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

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 2e5 + 5;
    vector <pii> adj[2][N];
    vector <int> gr[N];
    int vis[N];
    int vis_e[N];
    int n,m,s;
    int w[N];
    int next_idx = 0;
    stack <int> stk;
    int low[N],num[N];
    int scc_idx[N],scc_cnt[N];
    ll scc_value[N];
    int idx_scc = 0;
    ll f[2][N];
    bool isLeaf[N];

    void addEdges(int flag,int u,int v,int idx){
        adj[flag][u].emplace_back(make_pair(v,idx));
        if(!flag) {
            adj[flag][v] . emplace_back(make_pair(u, idx));
        }
    }

    void directGraph(int u){
        vis[u] = true;
        for(pii e : adj[0][u]){
            int v = e.first;
            int idx = e.second;
            if(!vis_e[idx]){
                addEdges(1,u,v,idx);
                vis_e[idx] = true;
            }
            if(!vis[v]){
                directGraph(v);
            }
        }
    }

    void tarjan(int u){
        low[u] = num[u] = ++next_idx;
        stk.emplace(u);
        vis[u] = 1;
        for(pii e : adj[1][u]){
            int v = e.first;
            if(vis[v] == 1){
                minimize(low[u],num[v]);
            } else if(!vis[v]){
                tarjan(v);
                minimize(low[u],low[v]);
            }
        }
        if(low[u] == num[u]){
            ++idx_scc;
            while(true){
                int v = stk.top();
                stk.pop();
                scc_idx[v] = idx_scc;
                scc_value[idx_scc] += 1LL * w[v];
                ++scc_cnt[idx_scc];
                vis[v] = 2;
                if(u == v){
                    break;
                }
            }
        }
    }

    void dfs(int u){
        vis[u] = true;
        for(pii e : adj[0][u]){
            int v = e.first;
            if(scc_idx[u] ^ scc_idx[v]){
                gr[scc_idx[u]].emplace_back(scc_idx[v]);
            }
            if(!vis[v]){
                dfs(v);
            }
        }
    }

    void compute(int u,int par){
        isLeaf[u] = true;
        for(int v : gr[u]){
            if(v ^ par){
                isLeaf[u] = false;
                compute(v,u);
                f[0][u] |= f[0][v];
                maximize(f[1][u],f[1][v] + scc_value[u]);
            }
        }
        f[0][u] |= (scc_cnt[u] > 1);
        if(isLeaf[u]) {
            f[1][u] = scc_value[u];
        }
    }

    void g(int u,int par,ll &ans,ll &end_path){
        ans += scc_value[u];
        for(int v : gr[u]){
            if(v ^ par){
                if(f[0][v]){
                    g(v,u,ans,end_path);
                } else {
                    maximize(end_path,f[1][v]);
                }
            }
        }
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>w[i];
        }
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            addEdges(0,u,v,i);
        }
        cin>>s;
        directGraph(s);
        fill(vis + 1,vis + 1 + n,false);
        for(int u = 1;u <= n;++u){
            if(!vis[u]){
                tarjan(u);
            }
        }
        fill(vis + 1,vis + 1 + n,false);
        dfs(s);
        compute(scc_idx[s],scc_idx[s]);
        ll ans = 0,end_path = 0;
        g(scc_idx[s],scc_idx[s],ans,end_path);
        cout<<ans + end_path;
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
