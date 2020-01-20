using namespace std;
#include<bits/stdc++.h>
#define ll long long

const ll MAXN=1e5;
ll P[10*MAXN],d=0,R[10*MAXN],coun=0;

main(void)
{
    freopen("MPRIME.INP","r",stdin);
    freopen("MPRIME.OUT","w",stdout);
    P[0]=P[1]=1;
    for(int i=2; i<=sqrt(MAXN*10); i++)
        for(int j=i*i; j<=MAXN*10; j+=i)
            if(P[j]==0)P[j]=1;
    for(int i=2; i<=MAXN; i++)
        if(P[i]==0)
        {
            R[++d]=i;
            if(d==1001)break;
        }
    //cout<<d<<endl;
    for(int i=2; i<=d; i+=2)
    {
        cout<<R[i]<<R[i+1]<<endl;
        coun++;
    }
    cout<<coun;
}
