using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

const ll MAXN=33333;
const ll INF=1e15+15;
vector <pll> adj[MAXN];
ll F1[MAXN],F2[MAXN],d1[MAXN],d2[MAXN],res[MAXN],sign[MAXN];
ll n,m,t=0;

void Enter()
{
    cin>>n>>m;
    for(int u,v,c,i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        adj[u].pb(mp(c,v));
        adj[v].pb(mp(c,u));
    }
}

void Dijkstra1()
{
    set <pll> S;
    for(int i=1;i<=n;i++)d1[i]=INF;
    S.insert(mp(0,1));
    d1[1]=0;
    F1[1]=1;
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll u=it.sec;
        for(int i=0;i<adj[u].size();i++)
        {
            ll v=adj[u][i].sec;
            ll c=adj[u][i].fir;
            if(d1[v]>d1[u]+c)
            {
                if(d1[v]!=INF)S.erase(S.find(pll(d1[v],v)));
                d1[v]=d1[u]+c;
                S.insert(mp(d1[v],v));
                F1[v]=F1[u];
            }
            else if(d1[v]==d1[u]+c)F1[v]+=F1[u];
        }
    }
}

void Dijkstra2()
{
    set <pll> S;
    for(int i=1;i<=n;i++)d2[i]=INF;
    S.insert(mp(0,n));
    d2[n]=0;
    F2[n]=1;
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll u=it.sec;
        for(int i=0;i<adj[u].size();i++)
        {
            ll v=adj[u][i].sec;
            ll c=adj[u][i].fir;
            if(d2[v]>d2[u]+c)
            {
                if(d2[v]!=INF)S.erase(S.find(pll(d2[v],v)));
                d2[v]=d2[u]+c;
                S.insert(mp(d2[v],v));
                F2[v]=F2[u];
            }
            else if(d2[v]==d2[u]+c)F2[v]+=F2[u];
        }
    }
}

void Result()
{
    for(int i=2;i<=n-1;i++)
    if(F1[i]*F2[i]==F1[n] && d1[i]+d2[i]==d1[n])sign[i]=1;
    for(int i=2;i<=n-1;i++)if(sign[i]==0)res[++t]=i;
    cout<<t<<endl;
    for(int i=1;i<=t;i++)cout<<res[i]<<endl;
}

main(void)
{
    Enter();
    Dijkstra1();
    Dijkstra2();
    Result();
}
