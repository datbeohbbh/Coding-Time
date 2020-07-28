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

    const int N = 1e5 + 5;
    int v[N],t[N];
    ll pref[N],ans[N];
    int f[N],g[N];
    int n;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>v[i];
        }
        for(int i = 1;i <= n;++i){
            cin>>t[i];
            pref[i] = pref[i - 1] + 1LL*t[i];
        }
        for(int i = 1;i <= n;++i){
            f[i] = i - 1;
            for(int l = i,r = n,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(1LL*v[i] >= pref[mid] - pref[i - 1]){
                    f[i] = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        for(int i = 1;i <= n;++i){
            ++g[i],--g[f[i] + 1];
        }
        for(int i = 1;i <= n;++i){
            g[i] += g[i - 1];
        }
        for(int i = 1;i <= n;++i){
            ans[i] = 1LL*t[i]*1LL*g[i];
            if(i <= f[i]) {
                v[i] -= (pref[f[i]] - pref[i - 1]);
            }
        }
        for(int i = 1;i <= n;++i){
            ans[f[i] + 1] += 1LL*v[i];
        }
        for(int i = 1;i <= n;++i){
            cout<<ans[i]<<' ';
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