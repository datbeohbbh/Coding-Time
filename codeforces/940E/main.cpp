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

    const int N = 1e5 + 5;
    const ll inf = 1e18;
    ll sum[N];
    int a[N];
    int n,c;
    ll f[N];

    void solve(){
        cin>>n>>c;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            sum[i] = sum[i - 1] + 1LL * a[i];
        }
        deque <int> dq;
        for(int i = 1;i <= n;++i){
            while(!dq.empty() and a[dq.back()] >= a[i]){
                dq.pop_back();
            }
            while(!dq.empty() and dq.front() < i - c + 1){
                dq.pop_front();
            }
            dq.emplace_back(i);
            f[i] = (c > 1 ? f[i - 1] + a[i] : inf);
            if(i >= c){
                minimize(f[i],f[i - c] + sum[i] - sum[i - c] - a[dq.front()]);
            }
        }
        cout<<f[n];
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