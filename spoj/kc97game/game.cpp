using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=777;
ll a[MAXN],n,ans=0;

main(void)
{
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    ll rem=n;
    for(int i=1; i<=rem-2; i++)
    {
        ll id,maxx=-1;
        for(int j=2; j<=n-1; j++)
            if(a[j]*(a[j-1]+a[j+1])>maxx)
            {
                maxx=a[j]*(a[j-1]+a[j+1]);
                id=j;
            }
        for(int j=id;j<=n-1;j++)a[j]=a[j+1];
        n--;
        ans+=maxx;
    }
    cout<<ans;
}
