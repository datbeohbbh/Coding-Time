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

	const int N = 3e5 + 5;
	vector <pii> adj[N];
	vector <pii> gr[N];
	vector <pii> bct[N];
	int has[N];
	bool ok[N];
	int vis[2][N];
	int low[N];
	int num[N];
	int scc_idx[N];
	int n,m,src,des,TIME = 0,num_scc = 0;
	bool flag = false;

	void dfs(int u){
		vis[0][u] = true;
		for(int i = 0;i < sz(adj[u]);++i){
			int v = adj[u][i].fir;
			int e_idx = adj[u][i].sec;
			if(!vis[1][e_idx]){
				vis[1][e_idx] = true;
				gr[u].pb({v,e_idx});
			}
			if(!vis[0][v]){
				dfs(v);
			}
		}
	}

	stack <int> stk;
	void tarjan(int u,int par){
		vis[0][u] = 1;
		low[u] = num[u] = ++TIME;
		stk.push(u);
		for(int i = 0;i < sz(gr[u]);++i){
            int v = gr[u][i].fir;
			int e_idx = gr[u][i].sec;
			if(v == par)continue;
			if(!vis[0][v]){
				tarjan(v,u);
				minimize(low[u],low[v]);
			} else if(vis[0][v] == 1){
				minimize(low[u],num[v]);
			}
		}
		if(low[u] == num[u]){
			++num_scc;
			while(true){
				int t = stk.top();
				stk.pop();
				vis[0][t] = 2;
				scc_idx[t] = num_scc;
				if(t == u){
					break;
				}
			}
		}
	}

	void make_tree(int u){
		vis[0][u] = true;
		for(int i = 0;i < sz(gr[u]);++i){
			int v = gr[u][i].fir;
			int e_idx = gr[u][i].sec;
			if(vis[0][v])continue;
			if(scc_idx[u] ^ scc_idx[v]){
				bct[scc_idx[u]].pb({scc_idx[v],has[e_idx]});
				bct[scc_idx[v]].pb({scc_idx[u],has[e_idx]});
			} else {
				ok[scc_idx[u]] |= has[e_idx];
			}
			make_tree(v);
		}
	}

	void can(int u,int par,bool f){
		if(u == scc_idx[des]){
			flag |= (f | ok[u]);
		}
		for(int i = 0;i < sz(bct[u]);++i){
			int v = bct[u][i].fir;
			int hs = bct[u][i].sec;
			if(v == par)continue;
			can(v,u,f | ok[u] | hs);
		}
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i <= m;++i){
    		int x,y,z;
    		cin>>x>>y>>z;
    		has[i] = z;
    		adj[x].pb({y,i});
    		adj[y].pb({x,i});
    	}
    	cin>>src>>des;
    	dfs(1);
    	fill(vis[0] + 1,vis[0] + 1 + n,0);
    	for(int u = 1;u <= n;++u){
    		if(vis[0][u])continue;
    		tarjan(u,u);
    	}
    	fill(vis[0] + 1,vis[0] + 1 + n,0);
    	for(int u = 1;u <= n;++u){
    		if(vis[0][u])continue;
    		make_tree(u);
    	}
    	can(scc_idx[src],scc_idx[src],ok[scc_idx[src]]);
    	cout<<(flag ? "YES" : "NO");
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
