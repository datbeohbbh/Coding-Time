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

	const int maxN = 1e4 + 4;
	ll smaller[maxN >> 1],dp[maxN],cnt[maxN >> 1];
	bool has[maxN];
	int a[maxN >> 2];
	ll ans = 0;
	int n;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= n;++j){
    			smaller[a[i]] += (a[j] < a[i]);
    		}
    	}
    	int lim = 0;
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= n;++j){
    			dp[a[i] + a[j]] += smaller[a[i]] * smaller[a[j]];
    			maximize(lim,a[i] + a[j]);
    			has[a[i] + a[j]] = true;
    		}
    	}
    	for(int i = 1;i <= lim;++i){
    		dp[i] += dp[i - 1];
    	}
    	int llim = 0;
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= n;++j){
    			if(a[j] > a[i]){
    				++cnt[a[j] - a[i]];
    				maximize(llim,a[j] - a[i]);
    			}
    		}
    	}
    	for(int sJ = 1;sJ <= lim;++sJ){
    		if(!has[sJ])continue;
    		for(int diff = 1;diff <= llim;++diff){
    			ans += cnt[diff] * (dp[sJ + diff - 1] - dp[sJ]);
    		}
    	}
    	cout<<setprecision(20)<<fixed<<(double)ans / pow(n,3);
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
