using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define sl "%lld"
#define sll "%lld\n"
#define sls "%lld "
#define pr pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)
#define minimize(a,b) a=min(a,b);

const ll MAXN=1e5+5;
ll F[505][MAXN],c[MAXN],m[MAXN];
ll n,s,ans=0;

main(void)
{
    scanf(sl sl,&s,&n);
    for(int i=1; i<=n; i++)
        scanf(sl sl,&c[i],&m[i]);
    F[0][0]=1;
    for(int i=0; i<=n-1; i++)
        for(int sum=0; sum<s; sum++)
            for(int j=0; j<=m[i+1]; j++)
                if(sum+j*c[i+1] <=s)
                    F[i+1][sum+j*c[i+1]]+=F[i][sum];
    for(int i=1; i<=n; i++)ans+=F[i][s];
    printf(sl,ans);
}
