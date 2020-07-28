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
    return (x % MOD + k % MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return (x % MOD - k % MOD + MOD)%MOD;
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

	const int N = 5e2 + 2;
	const ll base = 1e9 + 7;
	const int tx[] = {1,0,-1,0};
	const int ty[] = {0,1,0,-1};
	vector <pii> f[2][N][27];
	char a[N][N];
	ll dp[N],coef[N<<1][N<<1];
	int n,m;

	bool insize(int u,int v){
		return 1 <= u and u <= n and 1 <= v and v <= m;
	}

	ll calc(int u,int v,int z,int t){
		return coef[z - u + t - v][t - v];
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			cin>>a[i][j];
    		}
    	}
    	if(a[1][1] != a[n][m])cout<<0,exit(0);
    	int len = ((n + m - 2) >> 1) - ((n + m - 1) & 1);
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			if(i + j - 2 <= len){
    				f[0][i + j - 2][a[i][j] - 'a'].emp(mp(i,j));
    			}
    			if(n - i + m - j <= len){
    				f[1][n - i + m - j][a[i][j] - 'a'].emp(mp(i,j));
    			}
    		}
    	}
    	for(int i = 0;i <= n + m;++i){
    		for(int j = 0;j <= i;++j){
    			coef[i][j] = (!j or j == i ? 1LL : (coef[i - 1][j - 1] + coef[i - 1][j]) % base);
    		}
    	}
    	dp[0] = calc(1,1,n,m);
    	for(int l = 1;l <= len;++l){
    		for(int cl = 0;cl < 26;++cl){
    			if(!f[0][l][cl].empty()){
    				for(int il = 0;il < sz(f[0][l][cl]);++il){
    					for(int cr = 0;cr < 26;++cr){
    						if(cr != cl and !f[1][l][cr].empty()){
    							for(int ir = 0;ir < sz(f[1][l][cr]);++ir){
    								pii u = f[0][l][cl][il];
    								pii v = f[1][l][cr][ir];
    								if(u.fir <= v.fir and u.sec <= v.sec){
    									ll x = calc(1,1,u.fir,u.sec);
    									ll y = calc(u.fir,u.sec,v.fir,v.sec);
    									ll z = calc(v.fir,v.sec,n,m);
    									x = mul(x,y,base);
    									x = mul(x,z,base);
    									dp[l] = addmod(dp[l],x,base);
    								}
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    	for(int l = len;l > 1;--l){
    		for(int cl = 0;cl < 26;++cl){
    			if(!f[0][l][cl].empty()){
    				for(int il = 0;il < sz(f[0][l][cl]);++il){
    					for(int cr = 0;cr < 26;++cr){
    						if(cr != cl and !f[1][l][cr].empty()){
    							for(int ir = 0;ir < sz(f[1][l][cr]);++ir){
    								pii u = f[0][l][cl][il];
    								pii v = f[1][l][cr][ir];
    								if(u.fir <= v.fir and u.sec <= v.sec){
    									for(int kk = 2;kk < 4;++kk)
    									  if(insize(u.fir + tx[kk],u.sec + ty[kk])){
    									  	int uf = u.fir + tx[kk];
    									  	int us = u.sec + ty[kk];
    										for(int k = 0;k < 2;++k){
    											if(insize(v.fir + tx[k],v.sec + ty[k])){
    												if(a[uf][us] != a[v.fir + tx[k]][v.sec + ty[k]]){
    													ll x = calc(1,1,uf,us);
    													ll y = calc(u.fir,u.sec,v.fir,v.sec);
    													ll z = calc(v.fir + tx[k],v.sec + ty[k],n,m);
    													x = mul(x,y,base);
    													x = mul(x,z,base);
    													dp[l - 1] = submod(dp[l - 1],x,base);
    												}
    											}
    										}
    									}
    								}
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    	for(int i = 1;i <= len;++i){
    		dp[0] = submod(dp[0],dp[i],base);
    	}
    	cout<<dp[0];
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
