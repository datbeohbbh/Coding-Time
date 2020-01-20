using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

const ll MAXN=2001;
const ll INF=-1e10;
ll a[MAXN][MAXN],F[MAXN][MAXN];
ll n,k,maxi=INF;

void ReadData()
{
    //freopen("BONUS.INP","r",stdin);
    //freopen("BONUS.OUT","w",stdout);
    cin>>n>>k;
    ford(i,1,n)ford(j,1,n)
    {
        cin>>a[i][j];
        F[i][j]=F[i-1][j]+F[i][j-1]-F[i-1][j-1]+a[i][j];
    }
}

ll BONUS(ll i,ll j)
{
    return (F[i+k-1][j+k-1]-(F[i-1+k][j-1]+F[i-1][j-1+k])+F[i-1][j-1]);
}

void Optimize()
{
    ford(i,1,n-k+1)ford(j,1,n-k+1)
    maxi=max(maxi,BONUS(i,j));
    cout<<maxi;
}

main(void)
{
    ReadData();
    Optimize();
}
