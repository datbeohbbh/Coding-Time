using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair

struct Coor
{
    ll u,v,x,y;
};
const ll MAXN=111;
vector <ll> adj[MAXN];
ll sign[MAXN],res[MAXN];
Coor coor[MAXN];
ll n,d=0;
double D;
bool ok;

void Init()
{
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
        {
            double L=sqrt((coor[i].x-coor[j].x)*(coor[i].x-coor[j].x)
                          +(coor[i].y-coor[j].y)*(coor[i].y-coor[j].y));
            if(L<=D && coor[i].u>=coor[i].v)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
}

void DFS(ll uu,ll i)
{
    sign[uu]=1;
    if(uu==i)
    {
        ok=true;
        return ;
    }
    for(int j=0;j<adj[uu].size();j++)
    {
        ll vv=adj[uu][j];
        if(sign[vv]==0)DFS(vv,i);
    }
}

main(void)
{
    cin>>n>>D;
    for(int uu,vv,xx,yy,i=1; i<=n; i++)
    {
        cin>>xx>>yy>>uu>>vv;
        coor[i].x=xx;
        coor[i].y=yy;
        coor[i].u=uu;
        coor[i].v=vv;
    }
    cout<<-1;
}
