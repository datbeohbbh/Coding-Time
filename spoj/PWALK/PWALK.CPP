#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair

const ll MAXN=1010;
ll n,q,p1,p2,path=0,sign[MAXN];
vector <pll> adj[MAXN];
queue <pll> Q,empty_;

void ReadData()
{
    freopen("PWALK.INP","r",stdin);
    freopen("PWALK.OUT","w",stdout);
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(mp(v,c));
        adj[v].push_back(mp(u,c));
    }
}

ll BFS()
{
    Q.push(mp(p1,0));
    sign[p1]=1;
    while(!Q.empty())
    {
        pll u=Q.front();
        Q.pop();
        if(u.fir==p2)
        {
            Q=empty_;
            return u.sec;
        }
        for(int i=0;i<adj[u.fir].size();i++)
        {
            ll v=adj[u.fir][i].fir;
            ll c=adj[u.fir][i].sec;
            if(sign[v]==0)
            {
                Q.push(mp(v,u.sec+c));
                sign[v]=1;
            }
        }
    }
}

void Pwalk()
{
    while(cin>>p1>>p2)
    {
        path=BFS();
        cout<<path<<endl;
        memset(sign,0,sizeof(sign));
    }
}

main(void)
{
    ReadData();
    Pwalk();
}
