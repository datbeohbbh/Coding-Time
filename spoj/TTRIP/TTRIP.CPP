using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back

const ll MAXN=111;
const ll INF=1e15+55;
vector <pll> adj[MAXN];
ll C[MAXN][MAXN],sign[MAXN];
ll n,trip=0,t=0,u=1;

bool check()
{
   ford(i,1,n)if(sign[i]==0)return true;
   return false;
}

main(void)
{
    //freopen("TTRIP.INP","r",stdin);
    //freopen("TTRIP.OUT","w",stdout);
    cin>>n;
    ford(i,1,n)ford(j,1,n)cin>>C[i][j];
    ford(i,1,n)ford(j,1,n)if(C[i][j]==0 && i!=j)C[i][j]=INF;
    ford(k,1,n)ford(i,1,n)ford(j,1,n)C[i][j]=min(C[i][j],C[i][k]+C[k][j]);
    sign[1]=sign[n]=1;
    while(check())
    {
        ll minn=INF,vv=110;
        ford(v,2,n-1)if(sign[v]==0 && minn>C[u][v])
        {
            minn=C[u][v];
            vv=v;
        }
        if(vv!=110)
        {
            trip+=C[u][vv];
            u=vv;
            sign[vv]=1;
        }
    }
    trip+=C[u][n];
    cout<<trip;
}
