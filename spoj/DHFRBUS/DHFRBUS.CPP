using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fir first
#define sec second
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
const ll MAXN=1e5+15;
const ll INF=1e15+15;
priority_queue <data> heap;
vector <pll> adj[MAXN];
ll F[MAXN][15],sign[MAXN][15];
ll n,m,k,s,t;

void Enter()
{
    //freopen("DHFRBUS.INP","r",stdin);
    //freopen("DHFRBUS.OUT","w",stdout);
    cin>>n>>m>>k>>s>>t;
    for(int a,b,c,i=1; i<=m; i++)
    {
        cin>>a>>b>>c;
        adj[a].pb(mp(c,b));
        adj[b].pb(mp(c,a));
    }
}

void Init()
{
    for(int i=1; i<=n; i++)
        if(i!=s)
        {
            for(int j=0; j<=k; j++)
                F[i][j]=INF;
        }
    for(int j=0; j<=k; j++)heap.push(data(s,j,F[s][j]));
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
        for(int i=0;i<adj[uu].size();i++)
        {
            ll v=adj[uu][i].sec;
            ll c=adj[uu][i].fir;
            for(int j=xx;j<=k;j++)
            {
                if(sign[v][j]==0 && F[v][j] > F[uu][xx] + c)
                {
                    F[v][j] = F[uu][xx] + c;
                    heap.push(data(v,j,F[v][j]));
                }
                c=0;
            }
        }
    }
    cout<<F[t][k];
}

main(void)
{
    Enter();
    Init();
    Dijkstra();
}
