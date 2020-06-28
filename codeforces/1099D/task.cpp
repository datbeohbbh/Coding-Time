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
int n;
int s[N],a[N],h[N];

void dfs(int u,int par,int sum){
    for(auto v : adj[u]){
        if(v == par)continue;
        if(sum != s[v] and h[v] & 1){
            a[v] = s[v] - sum;
        }
        dfs(v,u,sum + a[v]);
    }
}

void dfs(int u,int par){
    for(auto v : adj[u]){
        if(v == par)continue;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}

void solve()
{
    cin>>n;
    for(int i = 2;i <= n;++i){
        int p;
        cin>>p;
        adj[i].pb(p);
        adj[p].pb(i);
    }
    for(int i = 1;i <= n;++i){
        cin>>s[i];
    }
    h[1] = 1;
    dfs(1,1);
    for(int i = 1;i <= n;++i)
        if(h[i] & 1)
          a[i] = -1;
    a[1] = s[1];
    dfs(1,1,a[1]);
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        ans+=1LL*a[i];
        if(h[i] & 1 and a[i] < 0)
          cout<<-1,exit(0);
    }
    cout<<ans;
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
