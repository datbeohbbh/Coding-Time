using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e4+1;
const ll INF=-1e10;
ll F[MAXN],n,m,L,R,u;
char color[MAXN];

void process()
{
    if(u==1)for(int i=L; i<=R; i++)color[i]='W';
    if(u==2)for(int i=L; i<=R; i++)color[i]='B';
}

ll LEM4()
{
    ll maxx=INF;
    for(int i=1; i<=n; i++)
    {
        if(color[i]=='W')F[i]=F[i-1]+1;
        else if(color[i]=='B')F[i]=0;
        else if(color[i]=='x')F[i]=F[i-1]+1;
        maxx=max(maxx,F[i]);
    }
    return maxx;
}

main(void)
{
    freopen("LEM4.INP","r",stdin);
    freopen("LEM4.OUT","w",stdout);
    memset(color,'x',sizeof(color));
    cin>>n>>m;
    while(cin>>u)
    {
        if(u<3)
        {
            cin>>L>>R;
            process();
        }
        else cout<<LEM4()<<endl;
    }
}
