using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)
const ll MAXN=111;
ll C[MAXN][MAXN],a[100*MAXN];
ll n,m,hack=0;
main(void)
{
    cin>>n>>m;
    ford(i,1,m)cin>>a[i];
    ford(i,1,n)ford(j,1,n)cin>>C[i][j];
    ford(k,1,n)ford(i,1,n)ford(j,1,n)C[i][j]=min(C[i][j],C[i][k]+C[k][j]);
    hack=C[1][a[1]]+C[a[m]][n];
    ford(i,1,m-1)hack+=C[a[i]][a[i+1]];
    cout<<hack;
}
