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
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int max_lg = 64;
    const ll base = 1e9 + 7;
    ll x,n;

    void solve(){
        cin>>x>>n;
        vector <int> primes;
        ll tmp = x;
        for(int j = 2;j * j <= tmp;++j){
           if(tmp % j == 0) {
               while (tmp % j == 0) {
                   tmp /= j;
               }
               primes.emp(j);
           }
        }
        if(tmp > 1){
            primes.emp(tmp);
        }
        ll ans = 1;
        for(int i = 0;i < sz(primes);++i){
            int p = primes[i];
            vector <ll> cnt;
            cnt.resize(max_lg,0LL);
            ll mull = (ll)p;
            int c = 1;
            while(mull <= n){
                cnt[c] += n / mull;
                if(mull > n / (1LL*p)){
                    break;
                }
                mull *= (1LL*p);
                ++c;
            }
            ll sum_cnt = cnt[max_lg - 1];
            for(int j = max_lg - 2;j > 0;--j){
                cnt[j] -= sum_cnt;
                sum_cnt += cnt[j];
            }
            for(int j = 1;j < max_lg;++j){
                if(cnt[j] > 0){
                    ll pw = 1;
                    ll x = 1;
                    ll h = cnt[j];
                    for(ll f = j;f > 0;--f){
                        x = mul(x,p,base);
                    }
                    for(;h > 0;x = mul(x,x,base),h /= 2LL){
                        if(h & 1){
                            pw = mul(pw,x,base);
                        }
                    }
                    ans = mul(ans,pw,base);
                }
            }
        }
        cout<<ans;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}