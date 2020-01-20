using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=5055;
ll a[MAXN],sum[MAXN],lmax=0,n;

bool B_search(ll L,ll R,ll t,ll d,ll res)
{
    while(L<=R)
    {
        ll mid=(L+R)/2;
        if(sum[mid]-sum[t]==sum[d]-sum[mid])
        {
            lmax=max(lmax,res);
            return true;
        }
        else if(sum[mid]-sum[t]>sum[d]-sum[mid])R=mid-1;
        else L=mid+1;
    }
    return false;
}

main(void)
{
    freopen("TWOSUM.INP","r",stdin);
    freopen("TWOSUM.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i-1; j++)
            if(i-j+1>lmax)
            {
                bool ok=B_search(j,i,j-1,i,i-j+1);
                if(ok)break;
            }
    }
    cout<<lmax;
}
