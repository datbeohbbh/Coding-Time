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
	vector <ll> w[4];
	int n,m;
	ll ans = 0;

	ll f(int i,int t){
		return w[2][i] + w[3][(t - (i << 1)) / 3];
	}

	ll ts(int t){
		ll pos = -1;
		int l = 0,r = (t >> 1);
		int lim = 0;
		ll ret = 0;
		while(l <= r and lim <= 600){
			int fl_y = l + (r - l) / 3;
			int fr_y = r - (r - l) / 3;
			maximize(ret,f(fl_y,t));
			maximize(ret,f(fr_y,t));
			if(f(fl_y,t) < f(fr_y,t)){
				l = fl_y;
			} else {
				r = fr_y;
			}
			++lim;
		}
		for(int i = max(0,l - 600);i <= min(t >> 1,r + 600);++i){
			maximize(ret,f(i,t));
		}
		return ret;
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i <= 3;++i){
    		w[i].emp(0);
    	}
    	for(int i = 1;i <= n;++i){
    		int x,c;
    		cin>>x>>c;
    		w[x].emp(c);
    	}
    	for(int i = 1;i <= 3;++i){
    		sort(w[i].begin() + 1,w[i].end(),[](const int &x,const int &y){
    			return x > y;
    		});
    		while(sz(w[i]) <= m){
    			w[i].emp(0);
    		}
    		for(int j = 1;j < sz(w[i]);++j){
    			w[i][j] += w[i][j - 1];
    		}
    	}
    	for(int t = 0;t <= m;++t){
    		ll val = ts(t);
    		maximize(ans,w[1][m - t] + val);
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
