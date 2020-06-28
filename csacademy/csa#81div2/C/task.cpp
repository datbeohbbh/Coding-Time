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
    return ((x % MOD) * (y % MOD)) % MOD;
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

const int N = 55;
const ll base = 1e9 + 7;
int c[10];
int n;

ll inv(ll x,ll h){
    ll res = 1;
    for(;h > 0;x = mul(x,x,base),h>>=1){
        if(h & 1){
            res = mul(res,x,base);
        }
    }
    return res;
}

ll calc(){
    ll f = 1;
    int num_digits = 0;
    for(int i = 0;i <= 9;++i){
        num_digits += c[i];
    }
    for(int i = 1;i <= num_digits;++i){
        f = mul(f,i,base);
    }
    for(int i = 0;i <= 9;++i){
        ll fc = 1;
        for(int j = 1;j <= c[i];++j){
            fc = mul(fc,j,base);
        }
        f = mul(f,inv(fc,base - 2),base);
    }
    ll sump = 0;
    for(int i = 0;i < num_digits;++i){
        sump = addmod(sump,inv(10,i),base);
    }
    ll sum = 0;
    for(int i = 0;i <= 9;++i){
        if(!c[i])continue;
        ll dp = f;
        dp = mul(dp,inv(num_digits,base - 2),base);
        dp = mul(dp,c[i],base);
        ll add = mul(i,sump,base);
        sum = addmod(sum,mul(dp,add,base),base);
    }
    return sum;
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        int x;
        cin>>x;
        ++c[x];
    }
    ll ans = calc();
    if(c[0]){
        --c[0];
        ans = submod(ans,calc(),base);
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
