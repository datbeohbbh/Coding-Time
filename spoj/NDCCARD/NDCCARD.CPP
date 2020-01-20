using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e4+44;
ll a[MAXN],n,m,maxx=-1;

bool cmp(ll A,ll B)
{
    return A>B;
}

main(void)
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1; i<=n; i++)
        if(a[i]<m)
        {
            for(int j=i+1; j<=n; j++)
                if(a[j]+a[i]<m)
                {
                    ll L=j+1,R=n,res=-1;
                    while(L<=R)
                    {
                        ll mid=(L+R)/2;
                        if(a[mid]+a[j]+a[i]<=m)
                        {
                            res=mid;
                            R=mid-1;
                        }
                        else break;
                    }
                    if(res!=-1)
                    {
                        cout<<a[i]+a[j]+a[res];
                        return 0;
                    }
                }
                else break;
        }
}
