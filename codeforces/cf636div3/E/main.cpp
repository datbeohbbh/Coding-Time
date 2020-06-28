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
    int n,m,a,b,c;
    int p[N],w[N];
    vector < pair <int,int> > adj[N];

    void bfs(int src){
        vector <bool> vis(n + 2,0);
        queue <int> q;
        q.emplace(src);
        vis[src] = true;
        for(;len(q) > 0;q.pop()){
            int top = q.front();
            for(pair <int,int> p : adj[top]){
                int v = p.first;
                int idx = p.second;
                if(!vis[v]){
                    vis[v] = true;
                    q.emplace(v);
                    ++w[idx];
                }
            }
        }
    }

    vector < pair <int,int> > tr[2];
    const int inf = 2e9;
    void dijkstra(int src,int f){
        set < pair <int,int> > heap;
        vector <int> d(n + 2,inf);
        d[src] = 0;
        heap.insert(make_pair(d[src],src));
        while(!heap.empty()){
            pair <int,int> top = *heap.begin();
            heap.erase(heap.begin());
            int u = top.second;
            for(pair <int,int> p : adj[u]){
                int v = p.first;
                int idx = p.second;
                if(d[v] > d[u] + w[idx]){
                    if(d[v] != inf){
                        heap.erase(heap.find(make_pair(d[v],v)));
                    }
                    d[v] = d[u] + w[idx];
                    heap.insert(make_pair(d[v],v));
                    tr[f][v] = make_pair(u,idx);
                }
            }
        }
    }

    void clr(){
        for(int u = 1;u <= n;++u){
            adj[u].clear();
        }
        for(int i = 1;i <= m;++i){
            w[i] = 0;
            p[i] = 0;
        }
        for(int i = 0;i < 2;++i){
            tr[i].clear();
        }
    }

    llong compute(){
        cin>>n>>m>>a>>b>>c;
        for(int i = 1;i <= m;++i){
            cin>>p[i];
        }
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(make_pair(v,i));
            adj[v].emplace_back(make_pair(u,i));
        }
        for(int i = 0;i < 2;++i){
            tr[i].resize(n + 2,make_pair(0,0));
        }
        bfs(a);
        bfs(b);
        dijkstra(a,0);
        dijkstra(b,1);
        map <int,int> cnt;
        int t = c;
        while(t != b){
            ++cnt[tr[1][t].second];
            t = tr[1][t].first;
        }
        t = b;
        while(t != a){
            ++cnt[tr[0][t].second];
            t = tr[0][t].first;
        }
        vector <pair <int,int> > e;
        for(auto p : cnt){
            if(p.first > 0) {
                e . emplace_back(make_pair(p . second, p . first));
            }
        }
        sort(all(e),[&](const pair <int,int> &i,const pair <int,int> &j){
            return i.first > j.first;
        });
        sort(p + 1,p + 1 + m);
        llong ans = 0;
        int cur = 1;
        for(int i = 0;i < len(e);++i){
            ans += 1LL * e[i].first * 1LL * p[cur++];
        }
        clr();
        return ans;
    }

    void solve(){
        int t;
        cin>>t;
        while(t--){
            cout<<compute()<<'\n';
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
