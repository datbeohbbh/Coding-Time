using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define inf(type) numeric_limits <type> :: max()
#define fn "SAMER08A"  /// ___FILE_NAME_HERE___
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define __rep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

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
    return (x < 0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V __base)
{
    return ((x+k)%__base + __base)%__base;
}
template <class T,class U,class V>
T submod(T x,U k,V __base)
{
    return ((x-k)%__base + __base)%__base;
}
template <class T,class U,class V>
T mul(T x,U y,V __base)
{
    return (ll)x*y%__base;
}
/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

const int N=600;
const int inf=1e9+7;
vector <pii> adj[2][N];
vector <int> dist[3];
int s,d,n,m;
struct data
{
    int u,v,c;
    data(){}
    data(int _u,int _v,int _c):u(_u),v(_v),c(_c){}
    bool operator < (const data &other) const
    {
        return (c < other.c) or (c==other.c and u < other.u) or (c==other.c and u==other.u and v < other.v);
    }
};
set <data> insp;
vector <data> E;

void loadGr()
{
    scanf("%d%d",&s,&d);
    s++,d++;
    for(int u,v,c,i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        ++u,++v;
        adj[0][u].pb(mp(v,c));
        adj[1][v].pb(mp(u,c));
        E.pb(data(u,v,c));
    }
}

set <pii> heap;
void dijkstra(int src,int idx,int k)
{
    dist[idx].resize(n+5,inf);
    dist[idx][src]=0;
    heap.insert(mp(dist[idx][src],src));
    while(!heap.empty())
    {
        pii top=*heap.begin();
        heap.erase(heap.begin());
        int u=top.sec;
        for(int i=0;i<sz(adj[k][u]);i++)
        {
            int v=adj[k][u][i].fir;
            int c=adj[k][u][i].sec;
            set <data> :: iterator it=insp.find(data(u,v,c));
            if(it->u==u and it->v==v and it->c==c)
                continue;
            if(dist[idx][v] > dist[idx][u] + c)
            {
                if(dist[idx][v] != inf)heap.erase(mp(dist[idx][v],v));
                dist[idx][v]=dist[idx][u]+c;
                heap.insert(mp(dist[idx][v],v));
            }
        }
    }
}

void solve()
{
    dijkstra(s,0,0);
    dijkstra(d,1,1);
    for(int i=0;i<sz(E);i++)
    {
        int u=E[i].u;
        int v=E[i].v;
        int c=E[i].c;
        if(dist[0][u] + c + dist[1][v] == dist[0][d])
            insp.insert(data(u,v,c));
    }
    dijkstra(s,2,0);
    printf("%d\n",dist[2][d]==inf ? -1 : dist[2][d]);
}

void resetAll()
{
    insp.clear();
    heap.clear();
    E.clear();
    for(int i=0;i<=2;i++)dist[i].clear();
    for(int i=1;i<=n;i++)
        adj[0][i].clear(),adj[1][i].clear();
}

int main(void)
{
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    while(true)
    {
        scanf("%d%d",&n,&m);
        if(n==0 and m==0)return 0;
        loadGr();
        solve();
        resetAll();
    }
}
