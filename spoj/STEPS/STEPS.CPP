using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e5+1;
const ll BASE=14062008;
ll a[MAXN],F[MAXN],n,k,inp;

void ReadData()
{
    memset(a,0,sizeof(a));
    memset(F,0,sizeof(F));
    cin>>n>>k;
    for(int i=1; i<=k; i++)
    {
        cin>>inp;
        a[inp]=1;
    }
}

void Optimize()
{
    F[1]=1;
    F[2]=(a[2]==1 ? 0:1);
    for(int i=3; i<=n; i++)
        F[i]=(a[i]==1 ? 0: ((F[i-1]+F[i-2])%BASE) );
    cout<<F[n];

}

main(void)
{
    ReadData();
    Optimize();
}
