using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e5+55;
ll a[MAXN],n,k,s=0;

bool cmp(ll A,ll B)
{
    return A>B;
}

main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+2,a+1+n,cmp);
    for(int i=1;i<=k+1;i++)s+=a[i];
    for(int i=k+2;i<=n;i++)s-=a[i];
    cout<<s;
}
