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
    return (x % MOD + k % MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return (x % MOD - k % MOD + MOD)%MOD;
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

	const int N = 1e6 + 3;
	const int base = 1e9 + 7;
	int dp[N][21][2];
	int n;

	int f(int x,int y){
		return n / (MASK(x) * (y ? 3 : 1));
	}

    void solve(){
        cin>>n;
    	int p = 0;
    	while(MASK(p) <= n){
    		++p;
    	}
        --p;
    	dp[1][p][0] = 1;
    	if(MASK(p - 1) * 3 <= n){
    		dp[1][p - 1][1] = 1;
    	}
    	for(int i = 1;i < n;++i){
    		for(int x = 0;x <= p;++x){
    			for(int y = 0;y < 2;++y){
    				dp[i + 1][x][y] = (dp[i + 1][x][y] + 1LL*dp[i][x][y]*(f(x,y) - i)) % base;
    				if(x){
    					dp[i + 1][x - 1][y] = (dp[i + 1][x - 1][y] + 1LL*dp[i][x][y]*(f(x - 1,y) - f(x,y))) % base;
    				}
    				if(y){
    					dp[i + 1][x][y - 1] = (dp[i + 1][x][y - 1] + 1LL*dp[i][x][y]*(f(x,y - 1) - f(x,y))) % base;
    				}
    		}
    	}}
    	cout<<dp[n][0][0];
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
