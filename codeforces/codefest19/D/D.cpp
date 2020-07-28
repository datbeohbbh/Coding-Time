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

	const int N = 2e5 + 5;
	ll s[N];
	int n;
	int p[N];

	struct FenwickTree{
		vector <ll> tree;
		FenwickTree(){
			tree.resize(N + 4,0);
		}
		void update(int node,ll val){
			for(;node <= N;node += node & (-node)){
				tree[node] += val;
			}
		}
		ll rsq(int node){
			ll ret = 0;
			for(;node > 0;node -= node & (-node)){
				ret += tree[node];
			}
			return ret;
		}
	}ft;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>s[i];
    		ft.update(i,i);
    	}
    	for(int i = n;i >= 1;--i){
    		int l = 1,r = n;
    		for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
    			if(ft.rsq(mid) <= s[i]){
    				p[i] = mid;
    				l = mid + 1;
    			} else {
    				r = mid - 1;
    			}
    		}
    		++p[i];
    		ft.update(p[i],-p[i]);
    	}
    	for(int i = 1;i <= n;++i){
    		cout<<p[i]<<' ';
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
