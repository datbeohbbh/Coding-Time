using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fir first
#define sec second
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
const ll MAXN=111;
const ll INF=1e15;
vector < pair< ll,vector <ll> > > adj[MAXN];
priority_queue <data> heap;
ll F[MAXN][20],sign[MAXN][20];
ll n,m,A,C,s,t,d=0,costmin=2*INF;

void Enter()
{
    freopen("AIRLINES.INP","r",stdin);
    freopen("AIRLINES.OUT","w",stdout);
    cin>>n>>m>>C>>A>>s>>t;
    for(int u,v,k,i=1; i<=m; i++)
    {
        cin>>u>>v;
        vector <ll> b;
        string st;
        getline(cin,st);
        stringstream ss(st);
        while(ss>>k)b.pb(k);
        adj[u].pb(mp(v,b));
        adj[v].pb(mp(u,b));
    }
}

void Init()
{
    for(int i=1; i<=n; i++)
        if(i!=s)
        {
            for(int j=1; j<=16; j++)
                F[i][j]=INF;
        }
    for(int j=1; j<=16; j++)heap.push(data(s,j,F[s][j]));
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
            ll v=adj[uu][i].fir,c;
            vector <ll> b;
            b=adj[uu][i].sec;
            for(int j=0; j<b.size(); j++)
            {
                if(b[j]!=xx)c=A+C;    else c=C;
                if(F[v][b[j]] > F[uu][xx] + c && sign[v][b[j]]==0)
                {
                    F[v][b[j]] = F[uu][xx] + c;
                    heap.push(data(v,b[j],F[v][b[j]]));
                }
            }
        }
    }
}

void PrintResult()
{
    for(int i=1; i<=16; i++)costmin=min(costmin,F[t][i]);
    cout<<costmin<<endl;
}

main(void)
{
    Enter();
    Init();
    Dijkstra();
    PrintResult();
}
