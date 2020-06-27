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
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 2e5 + 5;
    const int inf = 1e9 + 7;
    int a[N];
    int dist[N];
    int ans[N];
    int n;
    vector <int> adj[N];
    vector <int> vec[2];

    queue <int> que;
    void bfs(int src,int des){
        fill(dist + 1,dist + 1 + n,inf);
        for(int u : vec[src]){
            dist[u] = 0;
            que.push(u);
        }
        for(;sz(que);que.pop()){
            int u = que.front();
            for(int v : adj[u]){
                if(dist[v] == inf){
                    dist[v] = dist[u] + 1;
                    que.push(v);
                }
            }
        }
        for(int u : vec[des]){
            ans[u] = (dist[u] == inf ? -1 : dist[u]);
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            vec[a[i] & 1].emp(i);
        }
        for(int i = 1;i <= n;++i){
            if(i - a[i] >= 1){
                adj[i - a[i]].emp(i);
            }
            if(i + a[i] <= n){
                adj[i + a[i]].emp(i);
            }
        }
        fill(ans + 1,ans + 1 + n,-1);
        bfs(0,1);
        bfs(1,0);
        for(int i = 1;i <= n;++i){
            cout<<ans[i]<<' ';
        }
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