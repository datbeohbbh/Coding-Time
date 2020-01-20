using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

const ll MAXN=555;
const ll INF=1e15;
ll a[MAXN][MAXN],b[MAXN][MAXN],F[MAXN],sum[MAXN],c[MAXN];
ll n,m,Smax=-INF;

void Enter()
{
    freopen("MATRIX.INP","r",stdin);
    freopen("MATRIX.OUT","w",stdout);
    cin>>m>>n;
    ford(i,1,m)ford(j,1,n)cin>>a[i][j];
    ford(i,1,m)ford(j,1,n)b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1]+a[i][j];
    //ford(i,1,n)ford(j,1,m)b[j][i]=b[j-1][i]+a[j][i];
}

ll Calc(ll i,ll j,ll k,ll q)
{
    return b[k][q]-(b[i-1][q]+b[k][j-1])+b[i-1][j-1];
}

void Matrix()
{
    /*ford(i,1,m)ford(j,1,i)
    {
        ford(k,0,n)F[k]=INF,sum[k]=0;
        ford(k,1,n)c[k]=b[i][k]-b[j-1][k];
        ford(k,1,n)sum[k]=sum[k-1]+c[k];
        ford(k,1,n)F[k]=min(F[k-1],sum[k]);
        ford(k,1,n)Smax=max(Smax,abs(abs(sum[k])-abs(F[k])));
    }
    if(m==1 && n==1)cout<<a[1][1];
    else cout<<Smax;*/
    ford(i,1,m)ford(j,1,n)ford(k,1,m)ford(q,1,n)Smax=max(Smax,Calc(i,j,k,q));
    cout<<Smax;
}

main(void)
{
    Enter();
    Matrix();
}
