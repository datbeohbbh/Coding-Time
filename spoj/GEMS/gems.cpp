using namespace std;
#include<bits/stdc++.h>
#define ll long long
ll a,b,c,n,rem,maxx;

void backtrack(ll v)
{
    if((a*v*v+b*v+c)%n!=rem && (a*v*v+b*v+c)%n<=n)
    {
        maxx++;
        ll k=(a*v*v+b*v+c)%n;
        backtrack(k);
    }
    else if((a*v*v+b*v+c)%n==rem || (a*v*v+b*v+c)%n>n)return ;
}

main(void)
{
    freopen("gems.inp","r",stdin);
    freopen("gems.out","w",stdout);
    ll t;
    cin>>t;
    while(cin>>a>>b>>c>>n)
    {
        for(int i=0;i<n;i++)
        {
            maxx=1;
            rem=i;
            backtrack(i);
        }
        cout<<maxx<<endl;
    }
}
