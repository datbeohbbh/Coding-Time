using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=55;
const ll base=10003;
ll a[MAXN][MAXN];
ll m,n,k,way=0;

bool check(ll i,ll j)
{
    ll cnt1=0,cnt2=0;
    for(int kk=1;kk<=m;kk++)
        if(a[kk][j]==1)cnt1++;
    for(int kk=1;kk<=n;kk++)
        if(a[i][kk]==1)cnt2++;
    return (cnt1<2 && cnt2<2);
}

void Try(ll cnt)
{
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(check(i,j) && a[i][j]==0)
            {
                a[i][j]=1;
                if(cnt==k)way=(way+1)%base;
                else Try(cnt+1);
                a[i][j]=0;
            }
}

main(void)
{
    cin>>m>>n>>k;
    Try(1);
    cout<<way;
}
