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

    const int MAX_C = 20;
    string s;
    int f[1 << (MAX_C + 1)];
    int ans = 0;

    void solve(){
        cin>>s;
        for(int i = 0;i < sz(s);++i){
            vector <bool> has(MAX_C,false);
            int mask = 0;
            for(int j = i;j < sz(s);++j){
                if(has[s[j] - 'a'])break;
                has[s[j] - 'a'] = true;
                mask |= MASK(s[j] - 'a');
                f[mask] = __builtin_popcount(mask);
            }
        }
        for(int mask = 0;mask < MASK(MAX_C);++mask){
            for(int j = 0;j < MAX_C;++j){
                if(BIT(mask,j)){
                    maximize(f[mask],f[mask ^ MASK(j)]);
                }
            }
        }
        for(int mask = 0;mask < MASK(MAX_C);++mask){
            if(f[mask] == __builtin_popcount(mask)){
                int not_mask = ~mask & (MASK(MAX_C) - 1);
                maximize(ans,f[mask] + f[not_mask]);
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