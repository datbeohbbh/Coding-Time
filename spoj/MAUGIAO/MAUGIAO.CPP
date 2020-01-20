using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

const ll MAXN=30;
ll a[MAXN][MAXN],F[15*MAXN],sign[MAXN],b[15*MAXN],n,m=0,S=0;

main(void)
{
    freopen("MAUGIAO.INP","r",stdin);
    freopen("MAUGIAO.OUT","w",stdout);
    cin>>n;
    ford(i,1,n)ford(j,1,n)
    {
        cin>>a[i][j];
        b[++m]=a[i][j];
    }
    F[0]=1;
    ford(i,1,n)
    {
        ll maxx=-99999999999,rem;
        ford(j,1,n)
        {
            if(sign[j]==0)if(a[j][i]>maxx)
                {
                    maxx=a[j][i];
                    rem=j;
                }
        }
        sign[rem]=1;
        S+=maxx;
    }
    ford(i,1,m)for(int j=S-b[i]; j>=0; j--)
        if(F[j]>0)F[j+b[i]]+=F[j];
    cout<<S<<" "<<F[S];
}
