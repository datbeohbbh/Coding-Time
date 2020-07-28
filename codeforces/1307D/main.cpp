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
    vector <int> adj[N];
    vector <int> dist[2];
    int a[N],ord[N];
    int n,m,k;

    void bfs(vector <int> &f,int src){
        f.resize(n + 2,0);
        vector <bool> vis(n + 2, false);
        queue <int> que;
        que.emplace(src);
        vis[src] = true;
        for(;que.size() > 0;que.pop()){
            int cur = que.front();
            for(int v : adj[cur]){
                if(!vis[v]){
                    vis[v] = true;
                    f[v] = f[cur] + 1;
                    que.emplace(v);
                }
            }
        }
    }

    void solve(){
        cin>>n>>m>>k;
        for(int i = 1;i <= k;++i){
            cin>>a[i];
            ord[i] = i;
        }
        for(int i = 1;i <= m;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        bfs(dist[0],1);
        bfs(dist[1],n);
        sort(ord + 1,ord + 1 + k,[&](const int &i,const int &j){
            return dist[0][a[i]] - dist[1][a[i]] < dist[0][a[j]] - dist[1][a[j]];
        });
        vector <int> maxsuff(k + 2,0);
        maxsuff[k] = dist[1][a[ord[k]]];
        for(int i = k - 1;i >= 1;--i){
            maximize(maxsuff[i],max(maxsuff[i + 1],dist[1][a[ord[i]]]));
        }
        int ans = 0;
        for(int i = 1;i < k;++i){
            maximize(ans,dist[0][a[ord[i]]] + maxsuff[i + 1]);
        }
        cout<<min(dist[0][n],++ans);
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
