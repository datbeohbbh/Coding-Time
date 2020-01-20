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
    return ((x % MOD) + (k % MOD))%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x % MOD) - (k % MOD) + MOD) % MOD;
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

	const int N = 130;
	const ll base = 1e9 + 9;
	ll pw[N],f[N][N][N<<3];
	int k,b;

    void solve(){
    	cin>>k>>b;
    	pw[0] = 1 % k;
    	for(int i = 1;i <= b;++i){
    		pw[i] = mul(pw[i - 1],2LL,k);
    	}
    	f[0][0][0] = 1;
    	f[0][1][pw[0]] = 1;
    	for(int len = 1;len < b;++len){
    		for(int nb = 0;nb <= b;++nb){
    			for(int r = 0;r < k;++r){
    				f[len][nb][r] = addmod(f[len][nb][r],f[len - 1][nb][r],base);
    				if(nb){
    					f[len][nb][r] = addmod(f[len][nb][r],f[len - 1][nb - 1][submod(r,pw[len],k)],base);
    				}
    			}
    		}
    	}
    	ll ans = 0;
    	for(int i = 0;i <= b;++i){
    		ll m = mul(f[b - 1][i][0],i,base);
    		ans = addmod(ans,m,base);
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
