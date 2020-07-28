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

	const int N = 1e2 + 2;
	vector <int> dp[N][N];
	vector <int> aux[N][N];
	int a[N][N];
	int T,n,m;

	int calc(){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= m;++j){
				cin>>a[i][j];
			}
		}
		for(int i = 0;i < N;++i){
			for(int j = 0;j < N;++j){
				dp[i][j].clear();
				aux[i][j].clear();
			}
		}
		for(int j = 1;j <= m;++j){
			for(int t = 0;t < n;++t){
				dp[j][t].resize(n,0);
			}
		}
		for(int j = 1;j <= m;++j){
			vector <int> sh;
			for(int i = 1;i <= n;++i){
				sh.emp(a[i][j]);
			}
			for(int t = 0;t < n;++t){
				aux[j][t] = sh;
				int x = sh.back();
				sh.insert(sh.begin(),x);
				sh.pop_back();
			}
		}
		for(int t = 0;t < n;++t){
			dp[1][t] = aux[1][t];
		}
		for(int j = 2;j <= m;++j){
			for(int t = 0;t < n;++t){
				for(int k = 0;k < n;++k){
					for(int i = 0;i < n;++i){
						dp[j][t][i] = max(dp[j - 1][k][i],aux[j][t][i]);
					}
				}
			}
		}
		int ans = 0;
		for(int j = 1;j <= m;++j){
			for(int t = 0;t < n;++t){
				int cur = 0;
				for(int i = 0;i < n;++i){
					cur+=dp[j][t][i];
				}
				maximize(ans,cur);
			}
		}
		return ans;
	}

    void solve(){
    	cin>>T;
    	while(T--){
    		cin>>n>>m;
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
