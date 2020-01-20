using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<double,ll>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

const ll MAXN=1e3+33;
const double INF=1e9+7;
vector <pll> adj[MAXN];
set <pll> S;
double d[MAXN],m;
pair <ll,ll> coor[MAXN];
ll n,w;

void ReadData()
{
    cin>>n>>w>>m;
    for(int i=1; i<=n; i++)cin>>coor[i].fir>>coor[i].sec;
    for(int i=1; i<=w; i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(mp(0,v));
        adj[v].pb(mp(0,u));
    }
}

void Init()
{
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
        {
            double L=sqrt((coor[i].fir-coor[j].fir)*(coor[i].fir-coor[j].fir)
                          +(coor[i].sec-coor[j].sec)*(coor[i].sec-coor[j].sec));
            if(L<=m)
            {
                adj[i].pb(mp(L,j));
                adj[j].pb(mp(L,i));
            }
        }
}

void Dijkstra()
{
    for(int i=1; i<=n; i++)d[i]=INF;
    d[1]=0;
    S.insert(mp(0,1));
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll u=it.sec;
        for(int i=0; i<adj[u].size(); i++)
        {
            ll v=adj[u][i].sec;
            double c=adj[u][i].fir;
            if(d[v]>d[u]+c)
            {
                if(d[v]!=INF)S.erase(S.find(pll(d[v],v)));
                d[v]=d[u]+c;
                S.insert(mp(d[v],v));
            }
        }
    }
    if(d[n]!=INF)cout<<setprecision(0)<<fixed<<d[n]*1000;
    else cout<<-1;
}

main(void)
{
    ReadData();
    Init();
    Dijkstra();
}

