using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=505;
const ll INF=1e15;
ll C[MAXN][MAXN],sign[MAXN];
ll n,m,k;

void floyd()
{
    for(int kk=1;kk<=n;kk++)
        for(int u=1;u<=n;u++)
           for(int v=1;v<=n;v++)
              if(sign[kk]==1)
                 C[u][v]=min(C[u][v],C[u][kk]+C[kk][v]);
}

main(void)
{
	ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int u,v,c,i=1; i<=m; i++)
    {
        cin>>u>>v>>c;
        C[u][v]=c;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           if(C[i][j]==0 && i!=j)C[i][j]=INF;
    while(k--)
    {
        ll u,v,c;
        cin>>c;
        if(c==1)
        {
            cin>>u;
            sign[u]=1;
            floyd();
        }
        else
        {
            cin>>u>>v;
            if(C[u][v]!=INF)cout<<C[u][v]<<endl;
            else cout<<-1<<endl;
        }
    }
}
