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
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int N = 2e5 + 5;
    int a[N];
    int pos[N];
    int f[2][N];
    int dad[N];
    vector <int>  adj[N];
    vector <int> child[N];
    vector <int> topo;
    vector <int> sumpref[N],sumsuff[N];
    int n;

    void dfs(int u,int par){
        for(int v : adj[u]){
            if(v ^ par){
                dad[v] = u;
                pos[v] = child[u].size();
                child[u].emplace_back(v);
                dfs(v,u);
            }
        }
        topo.emplace_back(u);
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            if(!a[i]){
                a[i] = -1;
            }
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for(int u = 1;u <= n;++u){
            for(int j = 0;j < 2;++j){
                f[j][u] = a[u];
            }
        }
        dfs(1,1);
        for(int i = 0;i < topo.size();++i){
            int u = topo[i];
            int g = 0;
            for(int v : child[u]){
                g += max(0,f[0][v]);
            }
            maximize(f[0][u],g + a[u]);
        }
        for(int u = 1;u <= n;++u){
            sumpref[u].resize(child[u].size());
            sumsuff[u].resize(child[u].size());
            for(int i = 0;i < child[u].size();++i){
                int v = child[u][i];
                int p = pos[v];
                sumpref[u][p] = sumsuff[u][p] = max(f[0][v],0);
            }
            for(int i = 1;i < child[u].size();++i){
                sumpref[u][i] += sumpref[u][i - 1];
            }
            for(int i = child[u].size() - 2;i >= 0;--i){
                sumsuff[u][i] += sumsuff[u][i + 1];
            }
        }
        for(int i = topo.size() - 1;i >= 0;--i){
            int u = topo[i];
            int w = dad[u];
            int p = pos[u];
            int pref = (p ? sumpref[w][p - 1] : 0);
            int suff = (p < len(child[w]) - 1 ? sumsuff[w][p + 1] : 0);
            maximize(f[1][u],f[1][w] + pref + suff + a[u]);
        }
        for(int u = 1;u <= n;++u){
            int res = a[u];
            maximize(res,f[0][u] + f[1][u] - a[u]);
            cout<<res<<' ';
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
