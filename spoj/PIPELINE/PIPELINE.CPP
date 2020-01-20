using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define sec second
#define fir first
#define mp make_pair
#define pb push_back

struct data
{
    ll u,x,w;
    data(ll u,ll x,ll w)
    {
        this->u=u;
        this->x=x;
        this->w=w;
    }
    bool operator < (const data &other) const
    {
        return w > other.w ;
    }
};
const ll MAXN=1e4+1;
const ll INF=1e15+555;
priority_queue <data> heap;
vector <pll> adj[MAXN];
ll F[MAXN][21],sign[MAXN][21];
ll n,m,k;

void ReadData()
{
    ios_base::sync_with_stdio(false);
    freopen("PIPELINE.INP","r",stdin);
    freopen("PIPELINE.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int a,b,c,i=1; i<=m; i++)
    {
        cin>>a>>b>>c;
        adj[a].pb(mp(c,b));
        adj[b].pb(mp(c,a));
    }
}

void Init()
{
    for(int i=2; i<=n; i++)
        for(int j=0; j<=k; j++)
            F[i][j]=INF;
    for(int i=0; i<=k; i++)heap.push(data(1,i,F[1][i]));
}

void Dijkstra()
{
    while(!heap.empty())
    {
        data top=heap.top();
        heap.pop();
        ll uu=top.u;
        ll xx=top.x;
        sign[uu][xx]=1;
        if(F[uu][xx]!=top.w)continue;
        for(int i=0; i<adj[uu].size(); i++)
        {
            ll v=adj[uu][i].sec;
            ll c=adj[uu][i].fir;
            for(int j=xx; j<=k; j++)
            {
                if(sign[v][j]==0 && F[v][j]>F[uu][xx]+c)
                {
                    F[v][j]=F[uu][xx]+c;
                    heap.push(data(v,j,F[v][j]));
                }
                c=0;
            }
        }
    }
    cout<<F[n][k];
}

main(void)
{
    ReadData();
    Init();
    Dijkstra();
}
