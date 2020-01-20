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

	const ll inf = 1e18;
	const int N = 2e5 + 5;
	int rows[N][2];
	int l[N][2];
	int r[N][2];
	int cols[N];
	int n,m,q,k;

	struct opt	{
		int x,y;
		ll z;
		opt(){}
		opt(int _x,int _y,ll _z):x(_x),y(_y),z(_z){}
	};
	vector <opt> dp[2];

	int bs_left(int val){
		int pos = -1;
		for(int lx = 1,rx = q,mid = (lx + rx) >> 1;lx <= rx;mid = (lx + rx) >> 1){
			if(cols[mid] <= val){
				lx = mid + 1;
				pos = cols[mid];
			} else {
				rx = mid - 1;
			}
		}
		return pos;
	}

	int bs_right(int val){
		int pos = -1;
		for(int lx = 1,rx = q,mid = (lx + rx) >> 1;lx <= rx;mid = (lx + rx) >> 1){
			if(cols[mid] >= val){
				rx = mid - 1;
				pos = cols[mid];
			} else {
				lx = mid + 1;
			}
		}
		return pos;
	}

    void sw(int cur){
        dp[cur].clear();
        dp[cur].insert(dp[cur].begin(),all(dp[cur ^ 1]));
	}

    void solve(){
    	cin>>n>>m>>k>>q;
    	for(int i = 1;i <= n;++i){
    		rows[i][0] = 1e9;
    	}
    	for(int i = 1;i <= k;++i){
    		int u,v;
    		cin>>u>>v;
    		maximize(rows[u][1],v);
    		minimize(rows[u][0],v);
    	}
    	for(int i = 1;i <= q;++i){
    		cin>>cols[i];
    	}
    	sort(cols + 1,cols + 1 + q);

    	for(int i = 1;i <= n;++i){
    		l[i][0] = l[i][1] = r[i][0] = r[i][1] = -1;
    		if(!rows[i][1])continue;
    		for(int j = 0;j < 2;++j){
    			l[i][j] = bs_left(rows[i][j]);
    			r[i][j] = bs_right(rows[i][j]);
    		}
    	}
    	int pp = 1;
    	for(int i = n;i >= 1;--i){
            if(rows[i][1]){
                pp = i;
                break;
            }
    	}
    	if(!rows[1][1]){
            dp[1].emp(opt(1,cols[1],cols[1] - 1));
    	} else {
    		for(int i = 0;i < 2;++i){
    			if(~l[1][i]){
    				dp[1].emp(opt(1,l[1][i],rows[1][i ^ 1] - 1 + rows[1][1] - rows[1][0] + 1LL * (i != pp) *Abs(rows[1][i] - l[1][i])));
    			}
    			if(~r[1][i]){
    				dp[1].emp(opt(1,r[1][i],rows[1][i ^ 1] - 1 + rows[1][1] - rows[1][0] + 1LL * (i != pp) *Abs(rows[1][i] - r[1][i])));
    			}
    		}
    	}
    	int cur = 0;
    	for(int i = 2;i <= n;++i){
    		cur = i & 1;
    		if(!rows[i][1]){
                sw(cur);
    		}
    		for(int j = 0;j < 2;++j){
    			if(~l[i][j]){
    				ll w = 1LL * (i != pp) * Abs(rows[i][j] - l[i][j]) + rows[i][1] - rows[i][0];
    				ll g = inf;
    				for(int jj = 0;jj < 2;++jj){
    					if(~l[i][j ^ 1]){
    					  for(int v = 0;v < sz(dp[cur ^ 1]);++v){
    					  	opt cc = dp[cur ^ 1][v];
    						minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(rows[i][j ^ 1] - l[i][j ^ 1]) + 1LL*Abs(cc.y - l[i][j ^ 1]) + w);
    						minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(cc.y - rows[i][j ^ 1]) + w);
    					  }
    					}
    					if(~r[i][j ^ 1]){
    						for(int v = 0;v < sz(dp[cur ^ 1]);++v){
    							opt cc = dp[cur ^ 1][v];
    							minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(rows[i][j ^ 1] - r[i][j ^ 1]) + 1LL*Abs(cc.y - r[i][j ^ 1]) + w);
    							minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(cc.y - rows[i][j ^ 1]) + w);
    						}
    					}
    				}
    				if(g != inf){
    					dp[cur].emp(opt(i,l[i][j],g));
    				}
    			}
    			if(~r[i][j]){
    				ll w = 1LL * (i != pp) * Abs(rows[i][j] - r[i][j]) + rows[i][1] - rows[i][0];
    				ll g = inf;
    				for(int jj = 0;jj < 2;++jj){
    					if(~l[i][j ^ 1]){
    					  for(int v = 0;v < sz(dp[cur ^ 1]);++v){
    					  	opt cc = dp[cur ^ 1][v];
    						minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(rows[i][j ^ 1] - l[i][j ^ 1]) + 1LL*Abs(cc.y - l[i][j ^ 1]) + w);
    						minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(cc.y - rows[i][j ^ 1]) + w);
    					  }
    					}
    					if(~r[i][j ^ 1]){
    						for(int v = 0;v < sz(dp[cur ^ 1]);++v){
    							opt cc = dp[cur ^ 1][v];
    							minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(rows[i][j ^ 1] - r[i][j ^ 1]) + 1LL*Abs(cc.y - r[i][j ^ 1]) + w);
    							minimize(g,1LL*(i - cc.x) + cc.z + 1LL*Abs(cc.y - rows[i][j ^ 1]) + w);
    						}
    					}
    				}
    				if(g != inf){
    					dp[cur].emp(opt(i,r[i][j],g));
    				}
    			}
    		}
    		dp[cur ^ 1].clear();
    	}
    	ll ans = inf;
    	for(int i = 0;i < sz(dp[cur]);++i){
    		minimize(ans,dp[cur][i].z);
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
