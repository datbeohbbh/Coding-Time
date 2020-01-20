using namespace std;
#include<bits/stdc++.h>
#define ll long long

main(void)
{
    ll res=0;
    char ch;
    while(cin>>ch)res+=ch-'0';
    while(res/10!=0)
    {
        ll ans=res,rem=0;
        while(ans/10!=0)
        {
            rem+=(ans%10);
            ans/=10;
        }
        rem+=ans;
        res=rem;
    }
    cout<<res;
}
