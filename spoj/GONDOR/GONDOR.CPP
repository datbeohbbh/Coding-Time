using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<double,ll>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

const ll MAXN=111;
const double INF=1e15;
vector <pll> adj[MAXN];
set <pll> S;
pair <ll,ll> coor[MAXN];
vector <ll> lis[MAXN];
double d[MAXN];
ll s[MAXN],n;

void Enter()
{
    freopen("GONDOR.INP","r",stdin);
    freopen("GONDOR.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>coor[i].fir>>coor[i].sec>>s[i];
        for(int x,j=1; j<=n-1; j++)
        {
            cin>>x;
            lis[i].pb(x);
        }
    }
}

void Init()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<lis[i].size(); j++)
        {
            ll v=lis[i][j];
            double L=sqrt((coor[v].fir-coor[i].fir)*(coor[v].fir-coor[i].fir)+
                          (coor[v].sec-coor[i].sec)*(coor[v].sec-coor[i].sec));
            adj[i].pb(mp(L,v));
        }
    }
    for(int i=1; i<=n; i++)d[i]=INF;
}

void Dijkstra()
{
    S.insert(mp(0,1));
    d[1]=0;
    while(!S.empty())
    {
        pll it=*S.begin();
        S.erase(S.begin());
        ll u=it.sec;
        for(int i=0; i<adj[u].size(); i++)
        {
            if(s[u]>0)
            {
                ll v=adj[u][i].sec;
                double c=adj[u][i].fir;
                if(d[v]>d[u])s[u]--;
                if(d[v]>d[u]+c)
                {
                    if(d[v]!=INF)S.erase(S.find(pll(d[v],v)));
                    d[v]=d[u]+c;
                    S.insert(mp(d[v],v));
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout<<setprecision(6)<<fixed<<d[i]<<endl;
}

main(void)
{
    Enter();
    Init();
    Dijkstra();
}
