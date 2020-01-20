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

const int N = 65;
ll coef[N][N];
ll m;
int k;

ll f(ll val){
    vector <int> digits;
    for(;val > 0;val /= 2LL){
        digits.pb(val % 2);
    }
    reverse(all(digits));
    ll ret = 0;
    int cur = 0;
    for(int i = 0;i < sz(digits);++i){
        if(!digits[i])continue;
        if(k - cur > sz(digits) - i - 1 or sz(digits) < i + 1 or k < cur)
            break;
        ret += coef[sz(digits) - i - 1][k - cur];
        ++cur;
    }
    return ret;
}

void solve()
{
    cin>>m>>k;
    for(int i = 0;i <= 64;++i){
        for(int j = 0;j <= i;++j){
            coef[i][j] = (i == j or !j ? 1 : coef[i - 1][j - 1] + coef[i - 1][j]);
        }
    }
    ll l = max(1LL,m),r = 1e18;
    for(ll mid = (l + r) / 2LL;l <= r;mid = (l + r) / 2LL){
        ll gap = f(2LL*mid);
        ll x = f(mid);
        gap -= x;
        if(gap > m){
            r = mid - 1;
        }
        else if(gap < m){
            l = mid + 1;
        }
        else {
            cout<<mid;
            exit(0);
        }
    }
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
