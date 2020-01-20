using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

const ll MAXN=30;
ll a[MAXN][MAXN],res[MAXN],S,k,n,d=0,sum;
bool ok;

void PrintResult()
{
    if(ok)
    {
        cout<<"YES"<<endl;
        ford(i,1,k)cout<<res[i]<<" ";
    }
    else cout<<"NO";
}

void backtrack(ll i,ll j,ll summ)
{
    if(summ==S)
    {
        ok=true;
        PrintResult();
        return ;
    }
    ford(u,1,n)ford(v,j+1,k)
    if(a[i][j]<=a[u][v] && summ+a[u][v]<=S)
    {
        res[++d]=a[u][v];
        summ+=a[u][v];
        backtrack(u,v,summ);
        summ-=a[u][v];
        d--;
    }
}

main(void)
{
    freopen("V8SCORE.INP","r",stdin);
    freopen("V8SCORE.OUT","w",stdout);
    cin>>S>>k>>n;
    ford(i,1,n)ford(j,1,k)cin>>a[i][j];
    ford(i,1,n)
    {
        d=0;
        sum=a[i][1];
        res[++d]=a[i][1];
        ok=false;
        if(sum!=S)backtrack(i,1,sum);
        if(ok)return 0;
    }
    PrintResult();
}
