using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

struct data
{
    ll u,v,k,p,q,w;
    data(ll u,ll v,ll k,ll p,ll q,ll w)
    {
        this->u=u;
        this->v=v;
        this->k=k;
        this->p=p;
        this->q=q;
        this->w=w;
    }
    bool operator < (const data &other) const
    {
        return w > other.w;
    }
};
const ll MAXN=51;
const ll INF=1e9+7;
const ll tx[]= {0,0,1,-1};
const ll ty[]= {-1,1,0,0};
priority_queue <data> heap;
ll F[MAXN][MAXN][8][8][8],sign[MAXN][MAXN][8][8][8],a[MAXN][MAXN];
ll m,n,x,y,z,t,cmin=2*INF;

void Enter()
{
    freopen("XUCXAC.INP","r",stdin);
    freopen("XUCXAC.OUT","w",stdout);
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j];
    cin>>x>>y>>z>>t;
}

void Init()
{

    ford(i,1,m)ford(j,1,n)ford(ii,1,6)ford(jj,1,6)ford(kk,1,6)
    F[i][j][ii][jj][kk]=INF;
    F[x][y][2][1][3]=5*a[x][y];
}

bool insize(ll uu,ll vv)
{
    return (1<=uu && uu<=m && 1<=vv && vv<=n);
}

void Dijkstra()
{
    heap.push(data(x,y,2,1,3,F[x][y][2][1][3]));
    while(!heap.empty())
    {
        data top=heap.top();
        heap.pop();
        ll u=top.u;
        ll v=top.v;
        ll k=top.k;
        ll p=top.p;
        ll q=top.q;
        sign[u][v][k][p][q]=1;
        if(F[u][v][k][p][q]!=top.w)continue;
        ford(i,0,3)if(insize(u+tx[i],v+ty[i]))
        {
            if(i==0)
            {
                if(F[u+tx[i]][v+ty[i]][q][p][7-k] > F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*(7-q)
                        && sign[u+tx[i]][v+ty[i]][q][p][7-k]==0)
                {
                    F[u+tx[i]][v+ty[i]][q][p][7-k] = F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*(7-q);
                    heap.push(data(u+tx[i],v+ty[i],q,p,7-k,F[u+tx[i]][v+ty[i]][q][p][7-k]));
                }
            }
            else if(i==1)
            {
                if(F[u+tx[i]][v+ty[i]][7-q][p][k] > F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*q
                        && sign[u+tx[i]][v+ty[i]][7-q][p][k]==0)
                {
                    F[u+tx[i]][v+ty[i]][7-q][p][k] = F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*q;
                    heap.push(data(u+tx[i],v+ty[i],7-q,p,k,F[u+tx[i]][v+ty[i]][7-q][p][k]));
                }
            }
            else if(i==2)
            {
                if(F[u+tx[i]][v+ty[i]][7-p][k][q] > F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*p
                        && sign[u+tx[i]][v+ty[i]][7-p][k][q]==0)
                {
                    F[u+tx[i]][v+ty[i]][7-p][k][q] = F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*p;
                    heap.push(data(u+tx[i],v+ty[i],7-p,k,q,F[u+tx[i]][v+ty[i]][7-p][k][q]));
                }
            }
            else
            {
                if(F[u+tx[i]][v+ty[i]][p][7-k][q] > F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*(7-p)
                        && sign[u+tx[i]][v+ty[i]][p][7-k][q]==0)
                {
                    F[u+tx[i]][v+ty[i]][p][7-k][q] = F[u][v][k][p][q] + a[u+tx[i]][v+ty[i]]*(7-p);
                    heap.push(data(u+tx[i],v+ty[i],p,7-k,q,F[u+tx[i]][v+ty[i]][p][7-k][q]));
                }
            }
        }
    }
}

void PrintResult()
{
    ford(i,1,6)ford(j,1,6)ford(ii,1,6)
    cmin=min(cmin,F[z][t][i][j][ii]);
    cout<<cmin;
}

main(void)
{
    Enter();
    Init();
    Dijkstra();
    PrintResult();
}

