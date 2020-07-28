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

	const int N = 5e2 + 5;
	const int tx[] = {-1,1,0,0};
	const int ty[] = {0,0,1,-1};
	char a[N][N];
	pii par[N][N];
	int cnt[N][N];
	bool vis[N][N];
	vector <pii> changes;
	int n,k,ans = 0;

	bool insize(int u,int v){
		return 1 <= u and u <= n and 1 <= v and v <= n;
	}

	pii findp(pii u){
		return (u == par[u.fir][u.sec] ? u : par[u.fir][u.sec] = findp(par[u.fir][u.sec]));
	}

	void join(pii u,pii v){
		u = findp(u),v = findp(v);
		if(u == v)return ;
		par[v.fir][v.sec] = u;
		cnt[u.fir][u.sec] += cnt[v.fir][v.sec];
		maximize(ans,cnt[u.fir][u.sec]);
	}

	int calc(int u,int v){
    	pii p = findp(par[u][v]);
    	if(!vis[p.fir][p.sec]){
    		vis[p.fir][p.sec] = true;
    		changes.emp(p);
    		return cnt[p.fir][p.sec];
    	}
    	return 0;
	}

    void solve(){
    	cin>>n>>k;
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= n;++j){
    			cin>>a[i][j];
    		}
    	}
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= n;++j){
    			par[i][j] = {i,j};
    			cnt[i][j] = 1;
    		}
    	}
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= n;++j){
                if(a[i][j] == 'X')continue;
    			for(int t = 0;t < 4;++t){
    				if(insize(i + tx[t],j + ty[t]) and a[i + tx[t]][j + ty[t]] == '.'){
    					join({i,j},{i + tx[t],j + ty[t]});
    				}
    			}
    		}
    	}
    	for(int i = 1;i + k - 1 <= n;++i){
    		for(int j = 1;j + k - 1 <= n;++j){
    			int cur_ans = 0;
    			changes.clear();
    			for(int t = j;t <= j + k - 1;++t){
    				if(insize(i - 1,t) and a[i - 1][t] == '.'){
    					cur_ans += calc(i - 1,t);
    				}
    				if(insize(i + k,t) and a[i + k][t] == '.'){
    					cur_ans += calc(i + k,t);
    				}
    			}
    			for(int t = i;t <= i + k - 1;++t){
    				if(insize(t,j - 1) and a[t][j - 1] == '.'){
    					cur_ans += calc(t,j - 1);
    				}
    				if(insize(t,j + k) and a[t][j + k] == '.'){
    					cur_ans += calc(t,j + k);
    				}
    			}
    			for(int t = 0;t < sz(changes);++t){
    				pii p = changes[t];
    				vis[p.fir][p.sec] = false;
    			}
    			maximize(ans,cur_ans);
    		}
    	}
    	cout<<ans;
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
