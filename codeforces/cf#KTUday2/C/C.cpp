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

	const int N = 1e5 + 5;
	ll a[N];
	int n;
	ll d;

	bool ok(ll t){
        ll pre = a[1] + t*d;
        ll cur = t;
        for(int i = 2;i <= n;++i){
            ll x = (pre - a[i]  + t*d) / (2LL*d);
            ll l = max(0LL,min(x,t) - 2),r = min(x,t);
            ll ret = -1;
            for(ll mid = (l + r)/2;l <= r;mid = (l + r) / 2){
                if(pre > a[i] + (2LL*mid - t)*d){
                    ret = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if(~ret){
                pre = a[i] + (2LL*ret - t)*d;
                cur = ret;
            } else {
                return false;
            }
        }
        return true;
	}

    void solve(){
    	cin>>n>>d;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	ll l = 0,r = 2e9,ans = 0;
    	for(ll mid = (l + r)/ 2;l <= r;mid = (l + r) / 2){
    		if(ok(mid)){
    			ans = mid;
    			r = mid - 1;
    		} else {
    			l = mid + 1;
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
