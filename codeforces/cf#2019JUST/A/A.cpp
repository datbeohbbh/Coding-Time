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
	vector <pii> adj[N];
	vector <int> pos[2];
	map <pii,bool> interesting;
	int low[N],num[N],dad[N];
	int n,b,T,TIME = 0;
	bool vis[N];
	string s;

	void clr(){
		for(int u = 1;u <= n;++u){
			adj[u].clear();
		}
		interesting.clear();
		pos[0].clear();
		pos[1].clear();
		fill(low,low + 1 + n,0);
		fill(num,num + 1 + n,0);
		fill(vis,vis + 1 + n,0);
		TIME = 0;
	}

	void dfs(int u,int par){
		low[u] = num[u] = ++TIME;
		for(int i = 0;i < sz(adj[u]);++i){
			int v = adj[u][i].fir;
			if(v == par)continue;
			if(!vis[v]){
				dad[v] = u;
				dfs(v,u);
				minimize(low[u],low[v]);
			} else {
				minimize(low[u],num[v]);
			}
		}
	}

    void solve(){
    	cin>>T;
    	while(T--){
    		cin>>n>>b>>s; 			
    		for(int i = 1;i <= b;++i){
    			int u,v,c;
    			cin>>u>>v>>c;
    			adj[u].emp(mp(v,c));
    			adj[v].emp(mp(u,c));
    		}

    		for(int u = 1;u <= n;++u){
    			if(!vis[u]){
    				dfs(u,u);
    			}
    		}

    		for(int v = 1;v <= n;++v){
    			int u = dad[v];
    			if(u and low[v] >= num[v]){
    				interesting[mp(u,v)] = interesting[mp(v,u)] = true;
    			}
    		}

    		for(int u = 1;u <= n;++u){
    			for(int i = 0;i < sz(adj[u]);++i){
    				int v = adj[u][i].fir;
    				int &c = adj[u][i].sec;
    				if(interesting[mp(u,v)] or interesting[mp(v,u)]){
    					c = 0;
    				}
    			}
    		}

    		for(int i = 0;i < n;++i){
    			if(s[i] != 'A' or s[i] != 'H')continue;
    			pos[s[i] == 'A'].emp(i);
    		}

    		

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
