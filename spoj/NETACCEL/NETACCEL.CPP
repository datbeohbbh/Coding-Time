using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,double>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

struct data
{
    ll u,x;
    double w;
    data (ll u,ll x,double w)
    {
        this -> u = u;
        this -> x = x;
        this -> w = w;
    }
    bool operator < (const data &other) const
    {
        return w > other.w ;
    }
};

const ll MAXN=1111;
const ll INF=1e15+15;
priority_queue <data> pq;
vector <pll> adj[MAXN];
double F[MAXN][MAXN/10];
ll sign[MAXN][MAXN/10];
ll n,m,k;

void ReadData()
{
    //freopen("NETACCEL.INP","r",stdin);
    //freopen("NETACCEL.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        ll u,v;
        double c;
        cin>>u>>v>>c;
        adj[u].pb(mp(v,c));
        adj[v].pb(mp(u,c));
    }
}

void Init()
{
    for(int i=2; i<=n; i++)
        for(int j=0; j<=k; j++)
            F[i][j]=INF;
    for(int j=0; j<=k; j++)pq.push(data(1,j,F[1][j]));
}

void Dijkstra()
{
    while(!pq.empty())
    {
        data top=pq.top();
        pq.pop();
        ll uu=top.u;
        ll xx=top.x;
        sign[uu][xx]=1;
        if(F[uu][xx]!=top.w)continue;
        for(int i=0; i<adj[uu].size(); i++)
        {
            ll v=adj[uu][i].fir;
            double c=adj[uu][i].sec;
            ll x2=1;
            for(int j=xx; j<=k; j++)
            {
                if(sign[v][j]==0 && F[v][j] > F[uu][xx] + c/x2)
                {
                    F[v][j] = F[uu][xx] + c/x2;
                    pq.push(data(v,j,F[v][j]));
                }
                x2*=2;
            }
        }
    }
    cout<<fixed<<setprecision(2)<<F[n][k];
}

main(void)
{
    ReadData();
    Init();
    Dijkstra();
}
