using namespace std;
#include<bits/stdc++.h>
#define ll long long

ll d[11],n,x;

main(void)
{
    while(cin>>n)
    {
        ll x=n+1;
        while(true)
        {
            memset(d,0,sizeof(d));
            ll rem=x,cnt=0;
            while(rem!=-0)
            {
                ll r=rem%10;
                rem/=10;
                d[r]++;
            }
            for(int i=1;i<=9;i++)
            if(d[i]>1)cnt++;
            if(d[0]>=1)cnt++;
            if(cnt==0)
            {
                cout<<x;
                break;
            }
            else x++;
        }
    }
}
