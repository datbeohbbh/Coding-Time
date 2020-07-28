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
void maximize(T &x,U y) {
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y) {
    if(x > y)x=y;
}
template <class T>
T Abs(T x) {
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x) {
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD) {
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD) {
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD) {
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

namespace task {

const int N = 1e5 + 5;
string s;
int n,br = 0;
ll open[N],pref[N],cnt[N];
ll ans = 0;

ll calc(int l,int r) {
    if(l > r)return 0;
    return open[r] - open[l - 1] - (cnt[r] - cnt[l - 1])*pref[l - 1];
}

void solve() {
    cin>>s;
    n = sz(s);
    s = " " + s;
    stack <int> stk;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') {
            stk.push(i);
        } else {
            if(!stk.empty()) {
                pref[i] = open[stk.top()] = 1;
                stk.pop();
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1] + (open[i] == 1);
        pref[i] += pref[i - 1];
    }
    for(int i = 1; i <= n; ++i) {
        if(open[i]) {
            open[i] = pref[i - 1];
        }
    }
    for(int i = 1; i <= n; ++i) {
        open[i] += open[i - 1];
    }
    while(!stk.empty()) {
        stk.pop();
    }
    vector <pair <pll,ll> > ve;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') {
            stk.push(i);
        } else {
            if(!stk.empty()) {
                int l = stk.top() + 1,r = i - 1;
                ll t = 0;
                if(calc(l,r) > 0) {
                    ve.emp(mp(mp(l,r),calc(l,r)));
                }
            }
            stk.pop();
        }
    }
    for(int j = 1; j < sz(ve); ++j) {
        int ly = ve[j].fir.fir - 1,ry = ve[j].fir.sec + 1;
        for(int k = j - 1;~k;--k){
            int lx = ve[k].fir.fir - 1,rx = ve[k].fir.sec + 1;
            if(ly <= lx and rx <= ry){
                ve[j].sec -= ve[k].sec;
            }
        }
    }
    //above this is algorithm with complexity in worst case O(n ^ 2) . i can do it faster by excute algorithm mergesort tree so the new comlexity is O(n * log(n) * log(n))
    for(int j = 0; j < sz(ve); ++j) {
        int l = ve[j].fir.fir,r = ve[j].fir.sec;
        ans += 1LL*(r - l + 3) * ve[j].sec;
    }
    ve.clear();
    cout<<ans;
}}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}
