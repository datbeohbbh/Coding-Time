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

	const int N = 1e5 + 3;
	const int base = 1e9 + 7;
	int a[N],f[102][N],sum[102][N];
	int n,k;

	int calc(int i,int j){
		int l = max(0,j - a[i]);
		int r = j;
		return submod(sum[i - 1][r],l - 1 < 0 ? 0 : sum[i - 1][l - 1],base);
	}

    void solve(){
    	cin>>n>>k;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	for(int i = 0;i <= a[1];++i){
    		f[1][i] = 1;
    		sum[1][i] = f[1][i];
    	}
    	for(int i = 0;i <= k;++i){
    		sum[1][i] = addmod(sum[1][i],sum[1][i - 1],base);
    	}
    	for(int i = 2;i <= n;++i){
    		for(int j = 0;j <= k;++j){
    			f[i][j] = addmod(f[i][j],calc(i,j),base);
    			sum[i][j] = f[i][j];
    		}
    		for(int j = 1;j <= k;++j){
    			sum[i][j] = addmod(sum[i][j],sum[i][j - 1],base);
    		}
    	}
    	cout<<f[n][k];
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
