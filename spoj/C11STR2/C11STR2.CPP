using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e5+55;
const ll base=1e9+7;
ll Hash[3][MAXN],Pow[3][MAXN];
ll n,m,len=base,pos=1;
string a,b;

inline ll GetHash(ll id,ll i,ll j)
{
    return (Hash[id][j] - Hash[id][i-1]*Pow[id][j-i+1] + base*base) % base;
}

main(void)
{
    freopen("C11STR2.INP","r",stdin);
    freopen("C11STR2.OUT","w",stdout);
    cin>>a>>b;
    if(a==b)
    {
        cout<<a;
        return 0;
    }
    m=a.size(),n=b.size();
    a=" "+a;
    b=" "+b;
    Pow[1][0]=Pow[2][0]=1;
    Hash[1][0]=Hash[2][0]=0;
    for(int i=1; i<=m; i++)
        Pow[1][i]=(Pow[1][i-1]*26)%base;

    for(int i=1; i<=n; i++)
        Pow[2][i]=(Pow[2][i-1]*26)%base;

    for(int i=1; i<=m; i++)
        Hash[1][i]=(Hash[1][i-1]*26 + a[i] - 'a')%base;

    for(int i=1; i<=n; i++)
        Hash[2][i]=(Hash[2][i-1]*26 + b[i] - 'a')%base;

    for(int i=1; i<=min(m,n); i++)
        if(GetHash(1,m-i+1,m) == GetHash(2,1,i))
        {
            if(len > m + n - i)
            {
                len=m + n - i;
                pos=i+1;
            }
        }

    for(int i=pos ; i<=n; i++)a+=b[i];
    a.erase(0,1);
    cout<<a;
}
