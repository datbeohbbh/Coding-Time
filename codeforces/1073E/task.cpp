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

const int N = 11;
const ll base = 998244353;
bool dp[N<<1][1<<N][2];
ll cnt[N<<1][1<<N][2];
ll sum[N<<1][1<<N][2];
vector <int> digits;
ll l,r,k;

ll f(ll val){
    memset(dp,false,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));
    digits.clear();
    digits.pb(0);
    for(;val;val /= 10)
        digits.pb(val % 10);
    dp[sz(digits) - 1][0][true] = true;
    cnt[sz(digits) - 1][0][true] = 1;
    for(int pos = sz(digits) - 1;pos > 0;--pos)
        for(int mask = 0;mask < MASK(N - 1);++mask)
            if(__builtin_popcount(mask) <= k){
                for(int flag = 0;flag < 2;++flag){
                    int bound = (flag ? digits[pos] : 9);
                    for(int j = 0;j <= bound;++j)
                        if(__builtin_popcount(mask|MASK(j)) <= k){
                            if(!dp[pos][mask][flag])continue;
                            int msk = (mask | j) ? mask | MASK(j) : 0;
                            int new_flag = flag & (digits[pos] == j);
                            ll combine = addmod(mul(sum[pos][mask][flag],10LL,base),mul(cnt[pos][mask][flag],1LL*j,base),base);
                            dp[pos - 1][msk][new_flag]|=dp[pos][mask][flag];
                            cnt[pos - 1][msk][new_flag] = addmod(cnt[pos - 1][msk][new_flag],cnt[pos][mask][flag],base);
                            sum[pos - 1][msk][new_flag] = addmod(sum[pos - 1][msk][new_flag],combine,base);
                        }
                }
            }
      ll ans = 0;
      for(int mask = 0;mask < MASK(N - 1);++mask)
        if(__builtin_popcount(mask) <= k){
            if(dp[0][mask][0])
                ans = addmod(ans,sum[0][mask][0],base);
            if(dp[0][mask][1])
                ans = addmod(ans,sum[0][mask][1],base);
        }
      return ans;
}

void solve()
{
    cin>>l>>r>>k;
    cout<<submod(f(r),f(l - 1),base);
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
