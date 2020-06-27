
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
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int N = 3e5 + 5;
	int a[N][9];
	int n,m;
	int mask[1 << 9];
void solve(){
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			cin>>a[i][j];
		}
	}
	int l = 0,r = 1e9;
	int ans_i = -1,ans_j = -1;
	for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
		for(int msk = 0;msk < MASK(m);++msk){
			mask[msk] = 0;
		}
		for(int i = 1;i <= n;++i){
			int x = 0;
			for(int j = 1;j <= m;++j){
				x |= (a[i][j] >= mid) * MASK(j - 1);
			}
			mask[x] = i;
		}
		bool ok = false;
		int has_i = -1,has_j = -1;
		for(int mask_i = 0;mask_i < MASK(m);++mask_i){
			for(int mask_j = 0;mask_j < MASK(m);++mask_j){
				if(__builtin_popcount(mask_i | mask_j) == m){
					if(mask[mask_i] > 0 and mask[mask_j] > 0){
						ok = true;
						has_i = mask[mask_i];
						has_j = mask[mask_j];
					}
				}
			}
		}
		if(ok){
			l = mid + 1;
			ans_i = has_i;
			ans_j = has_j;
		} else {
			r = mid - 1;
		}
	}
	cout<<ans_i<<' '<<ans_j;
}}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
//    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
