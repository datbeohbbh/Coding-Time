#include <bits/stdc++.h>

using namespace std;

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

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "EDGE"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int N = 1e5 + 5;
    vector <int> adj[N];
    vector <int> child[N];
    vector <int> maxpref[N],maxsuff[N];
    vector <int> topo;
    vector < pair < int,int > > edges;
    int pos[N];
    int dad[N];
    int g[N],f[N];
    int n;

    void dfs(int u,int par){
        for(int v : adj[u]){
            if(v == par)continue;
            pos[v] = len(child[u]);
            child[u].emplace_back(v);
            dad[v] = u;
            dfs(v,u);
        }
        topo.emplace_back(u);
    }

    void solve(){
        cin>>n;
        for(int u,v,i = 1;i < n;++i){
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            edges.emplace_back(make_pair(u,v));
        }
        dfs(1,1);
        for(int i = 0;i < len(topo);++i){
            int u = topo[i];
            if(len(child[u]) > 0){
                for(int v : child[u]){
                    maximize(g[u],g[v] + 1);
                }
            }
        }
        for(int u = 1;u <= n;++u){
            maxpref[u].resize(len(child[u]),0);
            maxsuff[u].resize(len(child[u]),0);
            for(int i = 0;i < len(child[u]);++i){
                int v = child[u][i];
                maxpref[u][i] = maxsuff[u][i] = g[v];
            }
            for(int i = 1;i < len(maxpref[u]);++i){
                maximize(maxpref[u][i],maxpref[u][i - 1]);
            }
            for(int i = len(maxsuff[u]) - 2;i >= 0;--i){
                maximize(maxsuff[u][i],maxsuff[u][i + 1]);
            }
        }
        for(int i = len(topo) - 2;i >= 0;--i){
            int u = topo[i];
            int w = dad[u];
            maximize(f[u],f[w] + 1);
            int idx = pos[u];
            if(idx > 0){
                maximize(f[u],maxpref[w][idx - 1] + 2);
            }
            if(idx < len(child[w]) - 1){
                maximize(f[u],maxsuff[w][idx + 1] + 2);
            }
        }
        int maxLength = 0;
        for(int u = 1;u <= n;++u){
            maximize(maxLength,f[u] + g[u]);
        }
        for(pair < int,int > e : edges){
            int u = e.first;
            int v = e.second;
            if(dad[u] == v){
                swap(u,v);
            }
            if(u == 1){
                int idx = pos[v];
                int l = max(idx > 0 ? maxpref[1][idx - 1] : 0,idx < len(child[1]) - 1 ? maxsuff[1][idx + 1] : 0) + 1;
                cout<<(l + 1 + g[v] == maxLength ? "YES\n" : "NO\n");
            }
            else {
                cout<<(f[u] + 1 + g[v] == maxLength ? "YES\n" : "NO\n");
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".INP","r",stdin);
    freopen(fn".OUT","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
