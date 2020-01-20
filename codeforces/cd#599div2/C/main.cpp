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

    const  int N = 1e5 + 5;
    int b[N];
    int n,m;
    ll ans = 0;
    multiset <int> ms;

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>b[i];
        }
        for(int j = 1;j <= m;++j){
            int g;
            cin>>g;
            ms.insert(g);
        }
        for(int i = 1;i <= n;++i){
            if(b[i] > *ms.begin()){
                cout<<-1,exit(0);
            }
        }
        sort(b + 1,b + 1 + n,greater <int> ());
        for(int i = 1;i <= n;++i){
            if(!ms.empty()) {
                int cnt = 1;
                ll sum = b[i];
                auto it = ms . lower_bound(b[i]);
                auto cur = ms . lower_bound(b[i]);
                while (!ms . empty() and it != ms . end()) {
                    if (*it == b[i]) {
                        ++it;
                    } else {
                        break;
                    }
                }
                if (it != ms . end()) {
                    while (!ms . empty() and cnt < m) {
                        if (it != ms . end()) {
                            sum += *it;
                            ++it;
                            ++cnt;
                        } else {
                            break;
                        }
                    }
                }
                ms . erase(cur, it);
                ans += sum + 1LL*b[i]*1LL*(m - cnt);
            } else {
                ans += 1LL*b[i]*1LL*m;
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