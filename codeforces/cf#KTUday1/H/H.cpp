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

	const int N = 122;
	const int inf = 1e9;
	vector <int> adj[N];
	int pairU[N],pairV[N],dist[N];
	bool f[N][27];
	string s;
	int n,ans = 0,len;


	bool bfs(){
		queue <int> q;
		for(int u = 1;u <= len;++u){
			if(!pairU[u]){
				dist[u] = 0;
				q.push(u);
			} else {
				dist[u] = inf;
			}
		}
		dist[0] = inf;
		for(;sz(q);q.pop()){
			int u = q.front();
			if(dist[u] >= dist[0])continue;
			for(int i = 0;i < sz(adj[u]);++i){
				int v = adj[u][i];
				if(dist[pairV[v]] == inf){
					dist[pairV[v]] = dist[u] + 1;
					q.push(pairV[v]);
				}
			}
		}
		return (dist[0] != inf);
	}

	bool dfs(int u){
		if(u){
			for(int i = 0;i < sz(adj[u]);++i){
				int v = adj[u][i];
				if(dist[pairV[v]] == dist[u] + 1){
					if(dfs(pairV[v])){
						pairV[v] = u;
						pairU[u] = v;
						return true;
					}
				}
			}
			dist[u] = inf;
			return false;
		}
		return true;
	}

	int HopcroftKarp(){
		while(bfs()){
			for(int u = 1;u <= len;++u){
				if(!pairU[u] and dfs(u)){
					++ans;
				}
			}
		}
		return ans;
	}

	void addEdges(int u,int v){
		adj[u].emp(v),adj[v].emp(u);
	}
    void solve(){
    	cin>>s>>n;
    	len = sz(s);
    	s = " " + s;
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= 6;++j){
    			char c;
    			cin>>c;
    			if(isalpha(c)){
    				f[i][c - 'a'] = true;
    			}
    		}
    	}
    	for(int i = 1;i <= len;++i){
    		for(int j = 1;j <= n;++j){
    			if(f[j][s[i] - 'a']){
    				addEdges(i,j + len);
    			}
    		}
    	}
    	cout<<(HopcroftKarp() == len ? "YES" : "NO");
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
