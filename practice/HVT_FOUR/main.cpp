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

    const  int N = 2e3 + 2;
    const  int shift = 2e6 + 1;
    map <int,int> pref[shift<<1];
    int a[N],f[shift<<1];
    int n;
    ll ans = 0;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = 1;i <= n;++i){
            vector <int> cnt;
            for(int j = i + 1;j <= n;++j){
                ++f[a[i] + a[j] + shift];
                ++pref[a[i] + a[j] + shift][i];
                cnt.emp(a[i] + a[j] + shift);
            }
            sort(all(cnt));
            cnt.erase(unique(all(cnt)),cnt.end());
            for(int j = 0;j < sz(cnt);++j){
                pref[cnt[j]][i] += pref[cnt[j]][i - 1];
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = i + 1;j <= n;++j){
                int t = -(a[i] + a[j]);
                int y = pref[t + shift][j];
                if(y) {
                    ans += 1LL * (f[t + shift] - y);
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