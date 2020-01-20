using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll base=1e9+7;
const ll SIZE=1e6+6;
ll Hash[3][SIZE],Pow[3][SIZE];
ll n,m,q;
string X,Y;

inline void BuildHash()
{
    cin>>X>>Y;
    n=X.size();
    m=Y.size();
    X=" "+X;
    Y=" "+Y;
    Pow[1][0]=Pow[2][0]=1;
    for(int i=1; i<=n; i++)
        Pow[1][i]=(Pow[1][i-1]*26)%base;

    for(int i=1; i<=m; i++)
        Pow[2][i]=(Pow[2][i-1]*26)%base;

    for(int i=1; i<=n; i++)
        Hash[1][i]=(Hash[1][i-1]*26 + X[i]-'A')%base;

    for(int i=1; i<=m; i++)
        Hash[2][i]=(Hash[2][i-1]*26 + Y[i]-'A')%base;
}

inline ll GetHash(ll id,ll i,ll j)
{
    return (Hash[id][j]-Hash[id][i-1]*Pow[id][j-i+1] + base*base)%base;
}

main(void)
{
    freopen("HB_KT1B2.INP","r",stdin);
    freopen("HB_KT1B2.OUT","w",stdout);
    BuildHash();
    scanf("%lld",&q);
    while(q--)
    {
        ll i,j,k;
        scanf("%lld%lld%lld",&i,&j,&k);
        printf("%d\n",(GetHash(1,i,i+k-1)==GetHash(2,j,j+k-1) ? 1 : 0 ));
    }
}

