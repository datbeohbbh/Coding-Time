using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=5*(1e5+5);
ll a[MAXN],k;
map <ll,ll> m;

main(void)
{
    for(int i=1; i<=500002; i++)
    {
        ll x=a[i-1]-i;
        if(x > 0 && m[x]==0)a[i]=x,m[x]=1;
        else a[i]=a[i-1]+i,m[a[i]]=1;
    }
    while(scanf("%lld",&k)!=EOF)
    {
        if(k==-1)return 0;
        printf("%lld\n",a[k]);
    }
}
