#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
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
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e3 + 3;
    const ll inf = 1e18;
    const int prime[] = {-1,2,3,5,7,11,13,17,19,23,29,31};
    ll f[N][13];
    int n;

    void solve(){
        cin>>n;
        for(int i = 0;i <= n;++i){
            for(int j = 0;j < 12;++j){
                f[i][j] = numeric_limits <ll> :: max();
            }
        }
        f[1][0] = 1;
        for(int j = 1;j < 12;++j){
            for(int i = 1;i <= n;++i){
                ll pw = 1;
                for(int k = 0;k <= 61;++k){
                    if(i % (k + 1) == 0 and f[i / (k + 1)][j - 1] <= inf / pw){
                        minimize(f[i][j],f[i / (k + 1)][j - 1] * pw);
                    }
                    if(pw <= inf / (1LL * prime[j])){
                        pw *= 1LL*prime[j];
                    } else {
                        break;
                    }
                }
            }
        }
        ll ans = numeric_limits <ll> :: max();
        for(int j = 1;j < 12;++j){
            minimize(ans,f[n][j]);
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