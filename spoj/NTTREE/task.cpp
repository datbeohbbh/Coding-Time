using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define sz(c) ((c).size())
#define all(c) (c).begin(),(c).end()
#define fn "test"   ///____FILE_NAME_HERE_____
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

template <class T,class U> void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U> void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T> T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T> T safe_sqrt(T x)
{
    return sqrt(max((T)0,x));
}
template <class T,class U,class V> T addmod(T x,U k,V mod)
{
    return ((x + k)%mod + mod) % mod;
}
template <class T,class U,class V> T submod(T x,U k,V mod)
{
    return ((x - k)%mod + mod) % mod;
}
template <class T,class U,class V> T mulmod(T x,U k,V mod)
{
    return (ll)x*k%mod;
}

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=1e4+4;
vector <pair <int,ll> > adj[N];
vector <pair <ll,pii> > edges;
int n;
int szt[N];

void dfs(int u,int par)
{
    szt[u]=1;
    for(auto i : adj[u])
    {
        int v=i.fir;
        if(v==par)continue;
        dfs(v,u);
        szt[u]+=szt[v];
    }
}

void solve()
{
    cin>>n;
    for(int u,v,i=1;i<n;++i)
    {
        ll w;
        cin>>u>>v>>w;
        ++u,++v;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
        edges.pb(mp(w,mp(u,v)));
    }
    dfs(1,1);
    ll ans=0;
    for(int i=0;i<sz(edges);++i)
    {
        int u=edges[i].sec.fir;
        int v=edges[i].sec.sec;
        ll w=edges[i].fir;
        int cc=min(szt[u],szt[v]);
        ans+=1ll*w*1ll*cc*1ll*(n - cc);
    }
    cout<<ans;
}}

int main(void)
{
    cin.sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
