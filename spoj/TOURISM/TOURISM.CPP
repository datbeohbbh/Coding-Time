using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define sqr(X) ((X)*(X))

const ll MAXN=1e5+1;
const ll MAXR=1e6+1;
ll a[MAXN],F[MAXN],Sign[2*MAXR];
ll n,P,K,coun=0;

void ReadData()
{
    freopen("TOURISM.INP","r",stdin);
    freopen("TOURISM.OUT","w",stdout);
    cin>>n>>P;
    for(int i=1; i<=n; i++)cin>>a[i];
    F[1]=sqr(a[1]-P);
    Sign[a[n]]=n;
    K=1;
}

void Optimize()
{
    for(int i=2; i<=n-1; i++)
    {

    }
    cout<<F[n]<<endl;
    for(int i=1;i<=n;i++)
        if(Sign[a[i]]>0)coun++;
    cout<<coun<<endl;
    for(int i=1;i<=n;i++)
        if(Sign[a[i]]>0)cout<<Sign[a[i]]<<" ";
}

main(void)
{
    ReadData();
    Optimize();
}
