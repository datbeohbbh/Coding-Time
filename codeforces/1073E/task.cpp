#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

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
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return (long long)x*y%MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=21;
const ll base = 998244353;
ll l,r;
ll dp[N][2],pw[N];
int k;
vector <int> digits,a;

ll calc(int pos,bool flag)
{
    if(pos == -1)
      return 0;
    if(!flag and ~dp[pos][flag])
      return dp[pos][flag];
    ll ret = 0;
    int bound = flag ? min(digits[pos],a.back()) : a.back();
    for(int j = 0;j < sz(a) and a[j] <= bound;++j)
    {
        ll t = mul(a[j],pw[pos],base) + calc(pos - 1,flag & (a[j] >= digits[pos])) % base;
        t %= base;
        ret = addmod(ret,t,base);
    }
    if(!flag)
      return dp[pos][flag] = ret;
    return ret;
}

ll calc(ll val)
{
    digits.clear();
    while(val)
      digits.pb(val % 10),val/=10;
    return calc(sz(digits) - 1,true);
}

void solve()
{
    cin>>l>>r>>k;
    pw[0] = 1;
    for(int i = 1;i < N ;++i)
      pw[i] = pw[i - 1]*10LL;
    ll ans = 0;
    for(int mask = 1;mask < 1024;++mask)
    {
        if(__builtin_popcount(mask) > k)continue;
        a.clear();
        for(int i = 0;i < 10;++i)
         if(BIT(mask,i))
           a.pb(i);
        memset(dp,-1,sizeof(dp));
        ans = addmod(ans,calc(r) - calc(l - 1),base);
    }
    cout<<ans;
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
