using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e5+55;
ll a[MAXN],F[MAXN];
ll dmax=0,n,p;

void b_search(ll L,ll R)
{
    ll j=R;
    while(L<=R)
    {
        ll mid=(L+R)/2;
        if(a[j]-a[F[mid]]>=p)
        {
            dmax=max(dmax,j-F[mid]);
            R=mid-1;
        }
        else L=mid+1;
    }
}

main(void)
{
    freopen("JUMP.INP","r",stdin);
    freopen("JUMP.OUT","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    F[1]=1;
    for(int i=2;i<=n;i++)F[i]=(a[i] < a[F[i-1]] ? i : F[i-1]);
    for(int i=1;i<=n;i++)b_search(1,i);
    cout<<dmax;
}
