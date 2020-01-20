using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=60011;
ll n,T[MAXN],R[MAXN],F[MAXN];

main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>T[i];
    for(int i=1;i<n;i++)cin>>R[i];
    F[1]=T[1];
    for(int i=2;i<=n;i++)F[i]=min(F[i-1]+T[i],F[i-2]+R[i-1]);
    cout<<F[n];
}
