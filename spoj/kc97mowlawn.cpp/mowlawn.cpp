using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e5+55;
ll F[MAXN],E[MAXN];
ll n,k,sum;

main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>E[i];
    for(int i=1;i<=k;i++)F[i]=F[i-1]+E[i];
    for(int i=k+1;i<=n;i++)
    {
        sum=0;
        for(int j=i;j>=i-k+1;j--)
        {
            sum+=E[j];
            F[i]=max(F[i],sum+F[j-2]);
        }
        F[i]=max(F[i],F[i-1]);
    }
    cout<<F[n];
}
