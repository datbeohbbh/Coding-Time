using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1111;
const ll INF=-999999999;
ll p[MAXN],n,m,cost=INF,price;

void b_search(ll L,ll R)
{
    while(L<=R)
    {
        ll mid=(L+R)/2,coun=0;
        for(int i=min(m,n);i>=1;i--)
        if(p[i]>=mid)coun+=mid;
        if(coun>=cost)
        {
            price=mid;
            cost=coun;
            R=mid-1;
        }
        else L=mid+1;
    }
    cout<<price<<" "<<cost;
}

main(void)
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>p[i];
    sort(p+1,p+1+m);
    b_search(1,1e6);
}
