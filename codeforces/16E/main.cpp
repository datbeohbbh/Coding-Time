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

    const int N = 18;
    double a[N][N];
    double f[MASK(N + 1)];
    int n;

    void solve(){
        cin>>n;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                cin>>a[i][j];
            }
        }
        f[MASK(n) - 1] = 1.0;
        for(int mask = MASK(n) - 1;~mask;--mask){
            int cur = __builtin_popcount(mask);
            if(cur < 2)continue;
            for(int i = 0;i < n;++i){
                for(int j = i + 1;j < n;++j){
                    if(BIT(mask,i) & BIT(mask,j)){
                        f[mask ^ MASK(i)] += (2.0 / ((double)cur * (double)(cur - 1))) * f[mask] * a[j][i];
                        f[mask ^ MASK(j)] += (2.0 / ((double)cur * (double)(cur - 1))) * f[mask] * a[i][j];
                    }
                }
            }
        }
        cout<<setprecision(10)<<fixed;
        for(int i = 0;i < n;++i){
            cout<<f[MASK(i)]<<' ';
        }
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