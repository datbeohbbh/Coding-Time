using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second

const ll MAXN=1e5+55;
pll a[MAXN];
ll coun=0,n,head[MAXN];

bool cmp(pll A,pll B)
{
    return (A.fir<B.fir) || (A.fir==B.fir && A.sec<B.sec);
}

main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].fir;
        a[i].sec=i;
        head[i]=a[i].fir;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    if(a[i].fir!=0 && head[a[i].sec]!=0)
    {
        a[i].fir=0;
        head[a[i].sec]=0;
        head[a[i].sec-1]=0;
        head[a[i].sec+1]=0;
        coun++;
    }
    cout<<coun;
}
