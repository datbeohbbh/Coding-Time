using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair

const ll MAXN=222;
pii coor[MAXN];
ll plane[MAXN];
ll n,res=0,ans=99999999,id=0;

main(void)
{
    scanf("%lld",&n);
    for(int i=1; i<=n; i++)
        scanf("%lld%lld",&coor[i].fir,&coor[i].sec);
    for(int i=1; i<=n-2; i++)
        for(int j=i+1; j<=n-1; j++)
            for(int k=j+1; k<=n; k++)
            {
                long a1=coor[j].fir-coor[i].fir,b1=coor[j].sec-coor[i].sec;
                long a2=coor[k].fir-coor[j].fir,b2=coor[k].sec-coor[j].sec;
                plane[i]+=(a1*b2 != a2*b1);
                plane[j]+=(a1*b2 != a2*b1);
                plane[k]+=(a1*b2 != a2*b1);
                res+=(a1*b2 != a2*b1);
            }
    for(int i=1; i<=n; i++)ans=min(ans,plane[i]);
    for(int i=1; i<=n; i++)if(plane[i]==ans)
        {
            id=i;
            break;
        }
    printf("%lld %lld",res,id);
}
