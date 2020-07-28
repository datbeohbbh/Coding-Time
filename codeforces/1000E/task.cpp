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

	const int N = 3e5 + 5;
	vector <int> adj[N],edges[N];
	int dad[N],low[N],num[N],lable[N];
	bool vis[N];
	map <pii,bool> is_bridge;
	int n,m,TIME = 0,p = 0;
	pii ans(0,0);

	void dfs(int u){
		vis[u] = true;
		low[u] = num[u] = ++ TIME;
		for(int i = 0;i < sz(adj[u]);++i){
			int v = adj[u][i];
			if(v == dad[u])continue;
			if(!vis[v]){
				dad[v] = u;
				dfs(v);
				minimize(low[u],low[v]);
				if(low[v] >= num[v]){
					is_bridge[mp(u,v)] = is_bridge[mp(v,u)] = true;
				}
			} else {
				minimize(low[u],num[v]);
			}
		}
	}

	void addEdges(int u,int v){
		edges[u].emp(v),edges[v].emp(u);
	}

	void make_tree(int u){
		vis[u] = true;
		for(int i = 0;i < sz(adj[u]);++i){
			int v = adj[u][i];
			if(vis[v])continue;
			if(is_bridge[mp(u,v)]){
				lable[v] = ++p;
				addEdges(lable[u],lable[v]);
			} else {
				lable[v] = lable[u];
			}
			make_tree(v);
		}
	}

	void calc(int u,int par,int deep){
		for(int i = 0;i < sz(edges[u]);++i){
			int v = edges[u][i];
			if(v == par)continue;
			calc(v,u,deep + 1);
		}
		maximize(ans,mp(deep,u));
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i <= m;++i){
    		int u,v;
    		cin>>u>>v;
    		adj[u].emp(v);
    		adj[v].emp(u);
    	}
    	dfs(1);
    	fill(vis + 1,vis + 1 + n,false);
    	make_tree(1);
    	calc(0,0,0);
    	calc(ans.sec,ans.sec,0);
    	cout<<ans.fir;
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
