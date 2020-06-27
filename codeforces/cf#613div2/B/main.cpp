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

    void solve(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector <int> a(n + 2);
            vector <ll> f(n + 2);
            vector <ll> mi(n + 2);
            ll sum = 0;
            for(int i = 1;i <= n;++i){
                cin>>a[i];
                sum += 1LL * a[i];
                f[i] = f[i - 1] + 1LL * a[i];
                mi[i] = i;
            }
            for(int i = 1;i <= n;++i){
                if(f[i] > f[mi[i - 1]]){
                    mi[i] = mi[i - 1];
                }
            }
            bool ok = true;
            for(int i = 1;i <= n;++i){
                if(i == n and mi[i] == 0)continue;
                if(f[i] - f[mi[i]] >= sum){
                    ok = false;
                }
            }
            cout<<(ok ? "YES\n" : "NO\n");
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