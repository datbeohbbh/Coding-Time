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
	int f[N],g[N],t[N],a[N];
	int bad[N],cnt[N];
	int n,q;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	f[n] = g[n] = t[n] = 1;
    	for(int i = n - 1;i >= 1;--i){
    		f[i] = (a[i] > a[i + 1] ? f[i + 1] + 1 : 1);
    		g[i] = (a[i] <= a[i + 1] ? g[i + 1] + 1 : 1);
    		t[i] = max(f[i],g[i]);
    	}
    	for(int minrun = 1;minrun <= n;++minrun){
    		int cur = 1;
    		while(cur <= n){
    			if(t[cur] >= minrun){
    				cur += t[cur];
    			} else {
    				bad[minrun] += min(cur + minrun - 1,n) - min(cur + t[cur] - 1,n);
    				cur += minrun;
    			}
    			++cnt[minrun];
    		}
    	}
    	cin>>q;
    	while(q--){
    		int minrun;
    		cin>>minrun;
    		cout<<cnt[minrun]<<' '<<bad[minrun]<<'\n';
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
