using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

const ll MAXN=30;
const ll INF=-1e10;
ll a[MAXN],b[MAXN],c[MAXN],golda[100*MAXN],goldb[100*MAXN],x[MAXN],sum[MAXN];
ll n,kp1,kp2,d1=0,d2=0,d3=0,d4=0,r,Gmax=INF,sp1=0,sp2=0;
bool ok;

void ReadData()
{
    freopen("DGOLD.INP","r",stdin);
    freopen("DGOLD.OUT","w",stdout);
    ll dmin=-INF,r1,r2;
    cin>>n;
    ford(i,1,n)cin>>a[i];
    ford(i,1,n)sum[i]=sum[i-1]+a[i];
    ford(i,1,n)
    {
        if(dmin>abs(sum[n]-2*sum[i]))
        {
            dmin=abs(sum[n]-2*sum[i]);
            r1=i;
            r2=r1+1;
        }
    }
    ford(i,1,r1)
    {
        b[++d1]=a[i];
        sp1+=a[i];
    }
    ford(i,r2,n)
    {
        c[++d2]=a[i];
        sp2+=a[i];
    }
    kp1=r1;
    kp2=n-r1;
}

void Gold1()
{
    ll summ=0;
    ford(i,1,kp1)summ+=x[i]*b[i];
    if(summ<=sp1)golda[++d3]=summ;
}

void Gold2()
{
    ll summ=0;
    ford(i,1,kp2)summ+=x[i]*c[i];
    if(summ<=sp2)goldb[++d4]=summ;
}

void Bit(ll p)
{
    ford(i,0,1)
    {
        x[p]=i;
        if(p==r)
        {
            if(!ok)Gold1();
            else if(ok)Gold2();
        }
        else Bit(p+1);
    }
}

void B_search(ll L,ll R,ll x)
{
    while(L<=R)
    {
        ll mid=(L+R)/2;
        if(golda[mid]==x)
        {
            Gmax=max(Gmax,x);
            return ;
        }
        else if(golda[mid]<x)L=mid+1;
        else R=mid-1;
    }
}

void DGOLD()
{
    ok=false;
    r=kp1;
    Bit(1);
    memset(x,0,sizeof(x));
    ok=true;
    r=kp2;
    Bit(1);
    sort(golda+1,golda+1+d3);
    ford(i,1,d4)
    B_search(1,d3,goldb[i]);
    cout<<Gmax;
}

main(void)
{
    //ios_base::sync_with_stdio(false);
    ReadData();
    DGOLD();
}
