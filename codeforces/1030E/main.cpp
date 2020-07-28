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

    const int N = 3e5 + 5;
    int a[N];
    int f[2][N];
    int n;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            ll val;
            cin>>val;
            a[i] = __builtin_popcountll(val);
        }
        int suff = 0;
        ll ans = 0;
        f[0][n + 1] = 1;
        for(int i = n;i >= 1;--i){
            suff += a[i];
            ans += f[suff & 1][i + 1];
            int sum = 0,mx = 0;
            for(int j = i;j <= n and j - i <= 63;++j){
                sum += a[j];
                maximize(mx,a[j]);
                if((mx << 1) > sum and !(sum & 1)){
                    --ans;
                }
            }
            f[suff & 1][i] = f[suff & 1][i + 1] + 1;
            f[!(suff & 1)][i] = f[!(suff & 1)][i + 1];
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