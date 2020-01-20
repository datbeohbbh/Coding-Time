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

	const int N = 1e6 + 6;
	const ll inf = 1e13;
	int a[N],nxt[N];
	bool blocked[N];
	int n,m,k;

	ll calc(int l){
		int cur = 0,r = -1;
		int step = 0;
		while(cur < n){
			if(cur <= r){
				return inf;
			}
			r = nxt[cur];
			cur = nxt[cur] + l;
			++step;
		}
		return step;
	}

    void solve(){
    	cin>>n>>m>>k;
    	for(int i = 1;i <= m;++i){
    		int s;
    		cin>>s;
    		blocked[s] = true;
    	}
    	for(int i = 1;i <= k;++i){
    		cin>>a[i];
    	}
    	if(blocked[0]){
    		cout<<-1,exit(0);
    	}
    	for(int i = 0;i < n;++i){
    		if(!blocked[i]){
    			nxt[i] = i;
    		} else {
    			if(i){
    				nxt[i] = nxt[i - 1];
    			} else {
    				nxt[i] = -1;
    			}
    		}
    	}
    	ll ans = inf;
    	for(int i = 1;i <= k;++i){
    		ll min_step = calc(i);
    		if(min_step != inf){
    			minimize(ans,min_step * 1LL * a[i]);
    		}
    	}
    	cout<<(ans == inf ? -1 : ans);
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
