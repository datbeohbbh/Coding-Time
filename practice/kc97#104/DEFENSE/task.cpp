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
	const ll inf = 1e18;
	int p[N],lo[N],ri[N],lim[N];
	int n,L,rr;
	ll ans = 0;

	ll calc(int step){
		ll ret = 0;
		for(int i = 1;i <= n;++i){
			lo[i] = p[i] - rr + 1;
			ri[i] = p[i] + rr - 1;
			lim[i] = step;
		}
		int j = 0,cur = p[1];
		for(int i = 1;i <= n;++i){
			while(i <= n and p[i] < cur){
				++i;
			}
			cur = p[i];
			if(lo[i] <= ri[j] + 1){
				while(j <= n and lo[i] <= ri[j] + 1 and lim[i] >= ri[j] + 1 - lo[i]){
					lim[i] -= (ri[j] + 1 - lo[i]);
					lo[i] += (ri[j] + 1 - lo[i]);
					ri[i] += (ri[j] + 1 - lo[i]);
					cur += (ri[j] + 1 - lo[i]);
					++j;
				}
				j = i;
			} else {
				if(step < lo[i] - ri[i - 1] - 1){
					return inf;
				} else {
					ll mv = min(lo[i] - ri[i - 1] - 1,step);
					lo[i] -= mv;
					ri[i] -= mv;
					ret += 1LL*mv;
				}
			}
		}
		return (ri[n] >= L ? ret : inf);
	}

    void solve(){
    	cin>>n>>L>>rr;
    	for(int i = 1;i <= n;++i){
    		cin>>p[i];
    	}
    	sort(p + 1,p + 1 + n);
    	int l = 0,r = 1e8;
    	for(int mid = (l + r) >> 1;l <= r;mid = (l + r)>>1){
    		ll min_step = calc(mid);
    		if(min_step <= 1LL*n*1LL*mid){
    			ans = min_step;
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
