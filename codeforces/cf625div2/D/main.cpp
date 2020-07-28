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

#define ll long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    const int N = 2e5 + 5;
    vector <int> adj[N],gr[N];
    int n,m,k;
    int p[N],dist[N];

    queue <int> q;
    void bfs(int src){
        q.emplace(src);
        vector <bool> vis(n + 2,0);
        vis[src] = true;
        for(;q.size() > 0;q.pop()){
            int u = q.front();
            for(int v : adj[u]){
                if(!vis[v]){
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                    vis[v] = true;
                }
            }
        }
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            adj[v].emplace_back(u);
            gr[u].emplace_back(v);
        }
        cin>>k;
        for(int i = 1;i <= k;++i){
            cin>>p[i];
        }
        bfs(p[k]);
        int min_path = 0,max_path = 0;

        for(int cur = k - 1;cur > 0;--cur){
            while(cur > 0 and dist[p[cur]] == dist[p[cur + 1]] + 1){
                --cur;
            }
            if(cur){
                ++min_path;
            }
        }
        for(int i = 1;i < k;++i){
            for(int v : gr[p[i]]){
                if(dist[p[i]] == dist[v] + 1 and v != p[i + 1]){
                    ++max_path;
                    break;
                }
            }
        }
        cout<<min_path<<' '<<max_path;
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
