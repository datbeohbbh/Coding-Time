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
struct result
{
    ll r1,r2,r3;
};
const ll MAXN=111;
const ll INF=1e15;
vector < pair< ll,vector <ll> > > adj[MAXN];
priority_queue <data> heap;
result trace[MAXN][MAXN],res[MAXN*100];
ll F[MAXN][20],sign[MAXN][20];
ll n,m,A,C,s,t,d=0,costmin=2*INF,rem;

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
                if(b[j]!=xx)c=A+C;      else c=C;
                if(F[v][b[j]] > F[uu][xx] + c && sign[v][b[j]]==0)
                {
                    F[v][b[j]] = F[uu][xx] + c;
                    result rr;
                    rr.r1=uu;
                    rr.r2=xx;
                    rr.r3=b[j];
                    trace[v][b[j]]=rr;
                    heap.push(data(v,b[j],F[v][b[j]]));
                }
            }
        }
    }
}

void Trace()
{
    while(true)
    {
        if(t==0 || rem==0)break;
        result rr;
        rr.r1=trace[t][rem].r1;
        rr.r3=trace[t][rem].r3;
        rr.r2=t;
        res[++d]=rr;
        ll tt=trace[t][rem].r1;
        ll rem1=trace[t][rem].r2;
        t=tt;
        rem=rem1;
    }
    for(int i=d-1; i>=1; i--)
        cout<<res[i].r1<<" "<<res[i].r2<<" "<<res[i].r3<<endl;
}

void PrintResult()
{
    for(int i=1; i<=16; i++)
        if(costmin>F[t][i])
        {
            rem=i;
            costmin=F[t][i];
        }
    cout<<costmin<<endl;
}

main(void)
{
    Enter();
    Init();
    Dijkstra();
    PrintResult();
    Trace();
}
