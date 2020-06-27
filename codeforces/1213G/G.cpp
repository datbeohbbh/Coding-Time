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
	vector <pair <int,pii>> edges;
	pii q[N];
	int par[N],cnt[N];
	ll ans[N];
	ll cur_ans = 0;
	int n,m;

	int findp(int u){
		return (par[u] == u ? u : par[u] = findp(par[u]));
	}

	void join(int u,int v){
		u = findp(u),v = findp(v);
		if(u == v)return ;
		cur_ans -= 1LL * cnt[u] * 1LL * (cnt[u] - 1) / 2LL;
		cur_ans -= 1LL * cnt[v] * 1LL * (cnt[v] - 1) / 2LL;
		par[v] = u;
		cnt[u] += cnt[v];
		cur_ans += 1LL * cnt[u] * 1LL * (cnt[u] - 1) / 2LL;
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i < n;++i){
    		int u,v,w;
    		cin>>u>>v>>w;
    		edges.emp(mp(w,mp(u,v)));
    	}
    	sort(all(edges));
    	for(int i = 1;i <= m;++i){
    		cin>>q[i].fir;
    		q[i].sec = i;
    	}
    	sort(q + 1,q + 1 + m);
    	for(int i = 1;i <= n;++i){
    		par[i] = i;
    		cnt[i] = 1;
    	}
    	int j = 0;
    	for(int i = 1;i <= m;++i){
    		while(j < sz(edges) and edges[j].fir <= q[i].fir){
    			join(edges[j].sec.fir,edges[j].sec.sec);
    			++j;
    		}
    		ans[q[i].sec] = cur_ans;
    	}
    	for(int i = 1;i <= m;++i){
    		cout<<ans[i]<<' ';
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
