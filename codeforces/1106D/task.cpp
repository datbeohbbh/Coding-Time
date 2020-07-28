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
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return (long long)x*y%MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=1e5+5;
vector <int> adj[N];
int n,m;
bool vis[N],proc[N];
vector <int> ord;
set <int> heap;

void dfs(int u){
    if(!vis[u])ord.pb(u);
    vis[u] = true;
    heap.erase(u);
    for(int i = 0;i < sz(adj[u]);++i){
        int v = adj[u][i];
        if(vis[v])continue;
        int mv = v;
        if(!heap.empty()){
            if(mv > *heap.begin()){
                mv = *heap.begin();
                heap.erase(heap.begin());
            }
        }
        if(!proc[u]){
         for(int j = i;j < sz(adj[u]);++j)
            if(!vis[adj[u][j]])
                heap.insert(adj[u][j]);
         proc[u] = true;
        }
        dfs(mv);
    }
}

void solve()
{
    cin>>n>>m;
    for(int i = 1;i <= m;++i){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1;i <= n;++i){
        sort(all(adj[i]));
        adj[i].erase(unique(all(adj[i])),adj[i].end());
    }
    dfs(1);
    while(sz(heap)){
        dfs(*heap.begin());
        if(!sz(heap))break;
    }
    for(auto res : ord)
        cout<<res<<' ';
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
