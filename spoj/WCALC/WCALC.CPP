using namespace std;
#include<bits/stdc++.h>
#define ll long long

main(void)
{
    ll b,n,coun=0,a,m;
    cin>>b>>n;
    for(int i=1;i<2*n;i++)
    if((b*i*(2*n-i))%(n*n)==0)coun++;
    cout<<coun;
}
