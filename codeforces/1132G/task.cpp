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

	const int N = 1e6 + 3;
	vector <int> adj[N];
	int a[N],tin[N],tout[N];
	int n,k,TIME = 0;

	struct SegmentTree{
		vector <int> tree,lazy;
		SegmentTree(){
			tree.resize((N + 1)<<2,0);
			lazy.resize((N + 1)<<2,0);
		}
		void pushdown(int l,int r,int node){
			if(!lazy[node])return ;
			tree[node] += lazy[node];
			if(l ^ r){
				lazy[node<<1] += lazy[node];
				lazy[node<<1|1] += lazy[node];
			}
			lazy[node] = 0;
		}

		void updateRange(int tl,int tr,int val,int l = 1,int r = n + 1,int node = 1){
			pushdown(l,r,node);
			if(l > r or r < tl or l > tr){
				return ;
			}
			if(tl <= l and r <= tr){
				tree[node] += val;
				if(l ^ r){
					lazy[node<<1] += val;
					lazy[node<<1|1] += val;
				}
				return;
			}
			int mid = (l + r) >> 1;
			updateRange(tl,tr,val,l,mid,node<<1);
			updateRange(tl,tr,val,mid + 1,r,node<<1|1);
			tree[node] = max(tree[node<<1],tree[node<<1|1]);
		}
	}seg;

	void dfs(int u){
		tin[u] = ++TIME;
		for(int i = 0;i < sz(adj[u]);++i){
			int v = adj[u][i];
			dfs(v);
		}
		tout[u] = TIME;
	}

    void solve(){
    	cin>>n>>k;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	a[n + 1] = n + 1;
    	stack <int> stk;
    	stk.push(n + 1);
    	for(int i = n;i >= 1;--i){
    		while(!stk.empty() and a[stk.top()] <= a[i]){
    			stk.pop();
    		}
    		adj[stk.top()].emp(i);
    		stk.push(i);
    	}
    	dfs(n + 1);
    	for(int i = 1;i < k;++i){
    		seg.updateRange(tin[i],tout[i],1);
    	}
    	for(int cur = 1;cur <= n - k + 1;++cur){
    		seg.updateRange(tin[cur + k - 1],tout[cur + k - 1],1);
    		cout<<seg.tree[1] + seg.lazy[1]<<' ';
    		seg.updateRange(tin[cur],tout[cur],-1);
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
