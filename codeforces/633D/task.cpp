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
    return (long long)x*y%MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task {

const ll lim = 1e13;
const int N = 1005;
ll fa[N],fb[N];
int a[N];
map <ll,int> ma;
int n,ans = 2,z = 0;

bool ok(ll val) {
    return -1e9 <= val and val <= 1e9;
}

int calc(int i,int j) {
    vector <ll> vec;
    int k;
    for(k = 1; k <= 100; ++k) {
        if(!ok(fa[k] * 1LL * a[i]) or !ok(fb[k] * 1LL * a[j])) {
            break;
        } else {
            ll f = fa[k] * 1LL * a[i] + fb[k] * 1LL * a[j];
            if(!ma[f]) {
                break;
            }
            vec.pb(f);
            --ma[f];
        }
    }
    for(int k = 0; k < sz(vec); ++k)
        ++ma[vec[k]];
    if(!a[i] and !a[j])
        return z;
    else if(!a[i] and a[j]){
        return z + k - 2;
    }
    else return k - 1;
}

void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        ++ma[a[i]];
        z += (a[i] == 0);
    }
    fa[1] = 1,fa[2] = 0,fa[3] = 1,fa[4] = 1;
    fb[1] = 0,fb[2] = 1,fb[3] = 1,fb[4] = 2;
    int cur_a = 5,cur_b = 5;
    while(fa[cur_a - 1] + fa[cur_a - 2] <= lim) {
        fa[cur_a] = fa[cur_a - 1] + fa[cur_a - 2];
        ++cur_a;
    }
    while(fb[cur_b - 1] + fb[cur_b - 2] <= lim) {
        fb[cur_b] = fb[cur_b - 1] + fb[cur_b - 2];
        ++cur_b;
    }
    --cur_a,--cur_b;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            maximize(ans,calc(i,j));
            maximize(ans,calc(j,i));
        }
    }
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
