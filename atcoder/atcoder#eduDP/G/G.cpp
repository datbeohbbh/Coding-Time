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
	vector <int> adj[N];
	vector <int> topo;
	int f[N];
	bool vis[N];
	int n,m;

	void dfs(int u){
		vis[u] = true;
		for(int i = 0;i < sz(adj[u]);++i){
			int v = adj[u][i];
			if(vis[v])continue;
			dfs(v);
		}
		topo.emp(u);
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i <= m;++i){
    		int u,v;
    		cin>>u>>v;
    		adj[u].emp(v);
    	}
    	for(int i = 1;i <= n;++i){
    		if(!vis[i]){
    			dfs(i);
    		}
    	}
    	for(int i = sz(topo) - 1;~i;--i){
    		int u = topo[i];
    		for(auto v : adj[u]){
    			maximize(f[v],f[u] + 1);
    		}
    	}
    	cout<<*max_element(f + 1,f + 1 + n);
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
