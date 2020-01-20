using namespace std;
#include<bits/stdc++.h>

int n,k,cnt;
bool prime[1111];

main(void)
{
    while(cin>>n>>k)
    {
        cnt=0;
        for(int i=2; i<=n; i++)
            if(!prime[i])
            {
                for(int j=1; j<=n/i; j++)
                    if(!prime[i*j])
                    {
                        cnt++;
                        if(cnt==k)
                        {
                            printf("%d\n",j*i);
                            break;
                        }
                        prime[i*j]=true;
                    }
            }
        fill(prime+1,prime+1+1011,false);
    }
}
