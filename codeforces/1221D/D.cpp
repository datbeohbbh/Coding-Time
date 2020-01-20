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
#define BIT(x,i) (((x)>>(i))&1LL)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int N = 3e5 + 5;
	const ll inf = 1e18;
	int a[N],b[N];
	ll dp[N][3];
	int n,q;

	ll calc(){
		for(int i = 0;i <= n;++i){
			for(int j = 0;j < 3;++j){
				dp[i][j] = inf;
			}
		}
		dp[1][0] = 0,dp[1][1] = b[1],dp[1][2] = (b[1] << 1LL);
		for(int i = 2;i <= n;++i){
			for(int j = 0;j < 3;++j){
				for(int k = 0;k < 3;++k){
					if(a[i - 1] + k != a[i] + j){
						minimize(dp[i][j],dp[i - 1][k] + 1LL*j*1LL*b[i]);
					}
				}
			}
		}
		return min(dp[n][0],min(dp[n][1],dp[n][2]));
	}

    void solve(){
    	cin>>q;
    	while(q--){
    		cin>>n;
    		for(int i = 1;i <= n;++i){
    			cin>>a[i]>>b[i];
    		}
    		cout<<calc()<<'\n';
    	}
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
