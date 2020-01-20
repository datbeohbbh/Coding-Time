using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e4+44;
const ll INF=9999999999;
ll Dmax[20*MAXN],Dmin[20*MAXN],n,q,a,b,v,resmax,resmin;

void IT(ll k,ll L,ll R,ll i,ll j)
{
    if(L>j || R<i)return ;
    if(i<=L && R<=j)
    {
        resmax=max(resmax,Dmax[k]);
        resmin=min(resmin,Dmin[k]);
        return ;
    }
    ll m=(L+R)/2;
    IT(k*2,L,m,i,j);
    IT(k*2+1,m+1,R,i,j);
}

void Init(ll k,ll L,ll R,ll i)
{
    if(L>i || R<i) return;
    if(L==R)
    {
        Dmax[k]=Dmin[k]=v;
        return;
    }
    ll m=(L+R)/2;
    Init(k*2,L,m,i);
    Init(k*2+1,m+1,R,i);
    Dmax[k]=max(Dmax[k*2],Dmax[k*2+1]);
    Dmin[k]=min(Dmin[k*2],Dmin[k*2+1]);
}

main(void)
{
    freopen("NKLINEUP.INP","r",stdin);
    freopen("NKLINEUP.OUT","w",stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>v;
        Init(1,1,n,i);
    }
    while(cin>>a>>b)
    {
        resmax=-INF;
        resmin=INF;
        IT(1,1,n,a,b);
        cout<<abs(resmax-resmin)<<endl;
    }
}
