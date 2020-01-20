using namespace std;
#include<bits/stdc++.h>
#define ll long long

ll n,k,cow=0;
queue <ll> Q;

main(void)
{
    //ios_base::sync_with_stdio(false);   cin.tie(false);
    freopen("VRATF.INP","r",stdin);
    freopen("VRATF.OUT","w",stdout);
    cin>>n>>k;
    Q.push(n);
    while(!Q.empty())
    {
        ll R,x,y;
        R=Q.front();
        Q.pop();
        if(R>k)
        {
            y=(R+k)/2;
            x=R-y;
            if(abs(y-x)==k && x>0 && y>0)
            {
                Q.push(x);
                Q.push(y);
            }
            else cow++;
        }
        else cow++;
    }
    cout<<cow;
}
