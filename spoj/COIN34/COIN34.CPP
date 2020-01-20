using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second

const ll MAXN=4*1e5;
pll a[MAXN],b[MAXN];
ll k,X,coin[35],coin1[30],coin2[30],x[20],t=0,d=0,n=0,m=0;

bool cmp(pll A,pll B)
{
    return (A.fir<B.fir)||(A.fir==B.fir && A.sec<B.sec);
}

void Init()
{
    coin[1]=2;
    coin[2]=3;
    for(int i=3; i<=34; i++)coin[i]=coin[i-1]+coin[i-2]+coin[i-3];
    for(int i=1; i<=17; i++)coin1[++n]=coin[i];
    for(int i=18; i<=34; i++)coin2[++m]=coin[i];
}

void Proc()
{
    ll sum=0,coun=0,sum1=0;
    for(int i=1; i<=17; i++)
        if(x[i]==1)
        {
            sum+=coin1[i];
            sum1+=coin2[i];
            coun++;
        }
    a[++t]=mp(sum,coun);
    b[++d]=mp(sum1,coun);
}

void Coin34(ll p)
{
    for(int i=0; i<=1; i++)
    {
        x[p]=i;
        if(p==17)Proc();
        else Coin34(p+1);
    }
}

ll b_search(ll V)
{
    ll L=1,R=t,res=-1;
    while(L<=R)
    {
        ll mid=(L+R)/2;
        if(a[mid].fir==V)
        {
            res=a[mid].sec;
            L=mid+1;
        }
        else if(a[mid].fir<V)L=mid+1;
        else R=mid-1;
    }
    return res;
}

main(void)
{
    freopen("COIN34.INP","r",stdin);
    freopen("COIN34.OUT","w",stdout);
    cin>>k;
    Init();
    Coin34(1);
    sort(a+1,a+1+t,cmp);
    sort(b+1,b+1+d,cmp);
    for(int i=1; i<=k; i++)
    {
        cin>>X;
        ll maxx=-1;
        for(int j=1; j<=d; j++)
        {
            if(X-b[j].fir>=0)
            {
                ll Rem=b_search(X-b[j].fir);
                if(Rem!=-1)
                {
                    //maxx=max(maxx,b[j].sec+Rem);
                    maxx=b[j].sec+Rem;
                    break;
                }
            }
            else break;
        }
        cout<<"Case #"<<i<<":"<<" "<<maxx<<endl;
    }
}
