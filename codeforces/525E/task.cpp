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

	const int N = 14;
	ll S,ans = 0;
	ll f[MASK(N)],g[MASK(N)],ft[20];
	int a[N<<1];
	int n,k;
	vector <int> vec;
	map <ll,ll> ways[N<<1][2];

	void calc(int p){
		int m = sz(vec);
		memset(f,0,sizeof(f));
		memset(g,-1,sizeof(g));
		for(int mask = 0;mask < MASK(m);++mask){
			bool ok = true;
			for(int i = 0;i < m;++i){
				if(!BIT(mask,i))continue;
				f[mask] += 1LL*vec[i];
				if(vec[i] >= 20 or ft[vec[i]] > S){
					ok = false;
				}
			}
			if(!ok)continue;
			g[mask] = -f[mask];
			for(int i = 0;i < m;++i){
				if(!BIT(mask,i))continue;
				g[mask] += ft[vec[i]];
			}
		}
		for(int mask = 0;mask < MASK(m);++mask){
			++ways[0][p][f[mask]];
		}
		for(int mask = 0;mask < MASK(m);++mask){
			for(int submask = mask;submask > 0;submask = (submask - 1) & mask){
				if(~g[submask]){
					if(__builtin_popcount(submask) > k)continue;
					++ways[__builtin_popcount(submask)][p][g[submask] + f[mask]];
				}
			}
		}
	}

    void solve(){
    	cin>>n>>k>>S;
    	ft[0] = 1LL;
    	for(int i = 1;i < 20;++i){
    		ft[i] = ft[i - 1]*1LL*i;
    	}
    	for(int i = 0;i < n;++i){
    		cin>>a[i];
    	}
    	for(int i = 0;i < n / 2;++i){
    		vec.emp(a[i]);
    	}
    	calc(0);
    	vec.clear();
    	for(int i = (n / 2);i < n;++i){
    		vec.emp(a[i]);
    	}
    	calc(1);
    	for(int i = 0;i <= k;++i){
    		for(map <ll,ll> :: iterator it = ways[i][0].begin();it != ways[i][0].end();++it){
    			ll sum_left = it -> fir;
    			ll way_left = it -> sec;
    			if(sum_left <= S){
    				for(int j = 0;j <= k - i;++j){
    					ans += way_left * ways[j][1][S - sum_left];
    				}
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
