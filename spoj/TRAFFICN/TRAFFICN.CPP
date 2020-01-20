using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back

const ll MAXN=1e4+44;
const ll INF=1e15+15;
vector <pll> adj1[MAXN],adj2[MAXN];
ll d1[MAXN],d2[MAXN];
ll n,m,k,s,t,test;
pair<ll,pll> ed[500];

void dijkstra1(ll x)
{
    set <pll> S;
    for(int i=1;i<=n;i++)d1[i]=INF;
    d1[x]=0;
    S.insert(mp(0,x));
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll u=it.sec;
        for(int i=0;i<adj1[u].size();i++)
        {
            ll v=adj1[u][i].sec;
            ll c=adj1[u][i].fir;
            if(d1[v]>d1[u]+c)
            {
                if(d1[v]!=INF)S.erase(S.find(pll(d1[v],v)));
                d1[v]=d1[u]+c;
                S.insert(mp(d1[v],v));
            }
        }
    }
}

void dijkstra2(ll x)
{
    set <pll> S;
    for(int i=1;i<=n;i++)d2[i]=INF;
    d2[x]=0;
    S.insert(mp(0,x));
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll u=it.sec;
        for(int i=0;i<adj2[u].size();i++)
        {
            ll v=adj2[u][i].sec;
            ll c=adj2[u][i].fir;
            if(d2[v]>d2[u]+c)
            {
                if(d2[v]!=INF)S.erase(S.find(pll(d2[v],v)));
                d2[v]=d2[u]+c;
                S.insert(mp(d2[v],v));
            }
        }
    }
}

void PrintResult()
{
    ll minn=INF;
    for(int i=1;i<=k;i++)
    minn=min(min(minn,d1[ed[i].fir]+ed[i].sec.sec+d2[ed[i].sec.fir])
                     ,d1[ed[i].sec.fir]+ed[i].sec.sec+d2[ed[i].fir]);
    if(minn!=INF)cout<<minn<<endl;
    else cout<<-1<<endl;
}

main(void)
{
    ios_base :: sync_with_stdio(false);
    cin>>test;
    while(cin>>n>>m>>k>>s>>t)
    {
        for(int u,v,c,i=1;i<=m;i++)
        {
            cin>>u>>v>>c;
            adj1[u].pb(mp(c,v));
            adj2[v].pb(mp(c,u));
        }
        for(int i=1;i<=k;i++)
        cin>>ed[i].fir>>ed[i].sec.fir>>ed[i].sec.sec;
        dijkstra1(s);
        dijkstra2(t);
        PrintResult();
    }
}
