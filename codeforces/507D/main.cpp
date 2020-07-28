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
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e3 + 30;
    int n;
    ll m,k;
    ll f[N][N / 10][2];
    ll pw[N];

    void solve(){
        cin>>n>>k>>m;
        pw[0] = 1;
        for(int i = 1;i <= n;++i){
            pw[i] = (pw[i - 1] * 10) % k;
        }
        ll ans = 0;
        f[0][0][0] = 1 % m;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < k;++j){
                for(int prev_flag = 0;prev_flag < 2;++prev_flag){
                    for(int x = 0;x <= 9;++x){
                        int cur_flag = prev_flag;
                        int t = (j + x * pw[i]) % k;
                        if(!t and x){
                            cur_flag = 1;
                        }
                        f[i + 1][t][cur_flag] = (f[i + 1][t][cur_flag] + f[i][j][prev_flag]) % m;
                        if(cur_flag and x and i == n - 1){
                            (ans += f[i][j][prev_flag]) %= m;
                        }
                    }
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
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}