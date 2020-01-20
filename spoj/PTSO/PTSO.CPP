using namespace std;
#include<bits/stdc++.h>
#define ll long long

ll n,k=2;

main(void)
{
    scanf("%lld",&n);
    while(k <= sqrt(n))
    {
        if(n%k==0)
        {
            n/=k;
            printf("%lld%s",k,"*");
        }
        else k++;
    }
    printf("%lld",n);
}
