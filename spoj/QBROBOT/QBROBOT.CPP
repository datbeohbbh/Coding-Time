using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second

struct data
{
    ll t,e,u;
    data(ll t,ll e,ll u)
    {
        this->t=t;
        this->e=e;
        this->u=u;
    }
};
const ll MAXN=555;
const ll INF=1e9+7;
vector <data> adj[MAXN];
ll sign[MAXN],d[MAXN],dd[MAXN];
ll n,m,wmin=INF,maxx=-INF;

void ReadData()
{
    freopen("QBROBOT.INP","r",stdin);
    freopen("QBROBOT.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>sign[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        ll x,y,txy,cxy;
        cin>>x>>y>>txy>>cxy;
        adj[x].pb(data(txy,cxy,y));
        adj[y].pb(data(txy,cxy,x));
        maxx=max(maxx,cxy);
    }
}

void Dijkstra()
{
    set <pll> S;
    for(int i=1;i<=n;i++)d[i]=INF;
    S.insert(mp(0,1));
    d[1]=0;
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll uu=it.sec;
        for(int i=0;i<adj[uu].size();i++)
        {
            ll v=adj[uu][i].u;
            ll c=adj[uu][i].t;
            if(d[v]>d[uu]+c)
            {
                if(d[v]!=INF)S.erase(S.find(pll(d[v],v)));
                d[v]=d[uu]+c;
                S.insert(mp(d[v],v));
            }
        }
    }
}

bool BFS(ll full)
{
    queue <data> Q;
    for(int i=1;i<=n;i++)dd[i]=0;
    Q.push(data(0,full,1));
    dd[1]=1;
    while(!Q.empty())
    {
        data it=Q.front();
        Q.pop();
        ll uu=it.u;
        if(uu==n && it.t==d[n])return true;
        if(sign[uu]==1)it.e=full;
        for(int i=0;i<adj[uu].size();i++)
        {
            ll v=adj[uu][i].u;
            ll tm=adj[uu][i].t;
            ll ener=adj[uu][i].e;
            if(it.e>=ener && dd[v]==0)
            {
                dd[v]=1;
                Q.push(data(it.t+tm,it.e-ener,v));
            }
        }
    }
    return false;
}

void Qbrobot(ll L,ll R)
{
    while(L <= R)
    {
        ll mid=(L+R)/2;
        if(BFS(mid))
        {
            wmin=min(wmin,mid);
            R=mid-1;
        }
        else L=mid+1;
    }
    cout<<wmin;
}

main(void)
{
    ReadData();
    Dijkstra();
    Qbrobot(1,maxx);
}
