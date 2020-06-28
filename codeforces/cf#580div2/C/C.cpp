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

const int N = 2e5 + 5;
ll sum[N];
vector <int> ans;
map <int,int> ma;
int n;

bool check(ll a,ll b) {
    ans.clear();
    ll x = 1;
    ans.emp(1);
    for(int i = 2; i + (n >> 1) - 2 <= n; ++i) {
        if(1 + sum[i + (n>>1) - 2] - sum[i - 1] == a or 1 + sum[i + (n>>1) - 2] - sum[i - 1] == b) {
            for(int j = i; j <= i + (n >> 1) - 2; ++j) {
                ans.emp(j);
                x += 1LL*j;
            }
            for(int j = 2; j < i; ++j) {
                ma[j] = true;
            }
            for(int j = i + (n >> 1) - 1; j <= n; ++j) {
                ma[j] = true;
            }
            break;
        }
    }
    if(sz(ans) == 1)return false;
    int cur = 0;
    while(sz(ans) < n) {
        x -= 1LL*ans[cur++];
        if(!ma[b - x] and !ma[a - x]) {
            return false;
        } else {
            if(x + ans[cur - 1] == b and ma[a - x]) {
                ans.emp(a - x);
                ma[a - x] = false;
                x += (a - x);
            } else if(x + ans[cur - 1] == a and ma[b - x]) {
                ans.emp(b - x);
                ma[b - x] = false;
                x += (b - x);
            } else {
                return false;
            }
        }
    }
    x -= ans[cur++];
    x += ans[0];
    return (x == a or x == b);
}

void solve() {
    cin>>n;
    n<<=1;
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + 1LL*i;
    }
    ll s = 1LL*n*1LL*(n + 1) / 2LL;
    s /= 2LL;
    for(int i = max(2LL,s - 100LL);i <= min(2LL*s,s + 100LL);++i){
    	if(check(i,i + 1)){
    		cout<<"YES\n";
    		for(int i = 0; i < sz(ans); ++i) {
        		cout<<ans[i]<<' ';
    		}
    		exit(0);
    	}
    }
    cout<<"NO";
}}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}
