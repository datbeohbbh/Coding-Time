using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define pii pair<int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define inf(type) numeric_limits <type> :: max()
#define fn "MICEMAZE"  /// ___FILE_NAME_HERE___
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define __rep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();it++)

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < 0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V __base)
{
    return ((x+k)%__base + __base)%__base;
}
template <class T,class U,class V>
T submod(T x,U k,V __base)
{
    return ((x-k)%__base + __base)%__base;
}
template <class T,class U,class V>
T mul(T x,U y,V __base)
{
    return (ll)x*y%__base;
}
/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

const int N=1e2+22;
const ll inf=1e18;
ll pass[N][N];
int n,e,m;
ll t;

int main(void)
{
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%d%d%lld%d",&n,&e,&t,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          pass[i][j]=inf;
    for(int i=1;i<=n;i++)pass[i][i]=0;
    for(int u,v,i=1;i<=m;i++)
    {
        ll c;
        scanf("%d%d%lld",&u,&v,&c);
        pass[u][v]=c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
              minimize(pass[i][j],pass[i][k]+pass[k][j]);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(pass[i][e] <= t);
    printf("%d",ans);
}
