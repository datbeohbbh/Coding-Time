using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=16;
ll lem[MAXN][MAXN],x[MAXN],dd[MAXN];
ll n,pmin=LONG_LONG_MAX;

void ReadData()
{
    freopen("LEM3.INP","r",stdin);
    freopen("LEM3.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>lem[i][j];
}

void Process()
{
    ll sum=0;
    for(int i=1; i<=n-1; i++)
        sum+=lem[x[i]][x[i+1]];
    pmin=min(pmin,sum);
}

void Try(ll k)
{
    for(int i=1; i<=n; i++)
        if(dd[i]==0)
        {
            dd[i]=1;
            x[k]=i;
            if(k==n)Process();
            else Try(k+1);
            dd[i]=0;
        }
}

main(void)
{
    ReadData();
    Try(1);
    cout<<pmin;
}
