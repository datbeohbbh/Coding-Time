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

	const int inf = 1e9;
	const int N = 11;
	string s;
	int f[N][N][N][N];
	int ans[N][N];

    void solve(){
    	cin>>s;

    	for(int d = 0;d < 10;++d){
    		for(int sum = 0;sum < 10;++sum){
    			for(int tx = 0;tx < 10;++tx){
    				for(int ty = 0;ty < 10;++ty){
    					for(int i = 0;i < 10;++i){
    						for(int j = 0;j < 10;++j){
    							f[d][sum][tx][ty] = inf;
    						}
    					}
    				}
    			}
    		}
    	}

    	for(int d = 0;d < 10;++d){
    		for(int sum = 0;sum < 10;++sum){
    			for(int tx = 0;tx < 10;++tx){
    				for(int ty = 0;ty < 10;++ty){
    					for(int i = 0;i < 10;++i){
    						for(int j = 0;j < 10;++j){
    						  if(i == 0 and j == 0)continue;
    							if(d == ((sum % 10) + (tx * i) % 10 + (ty * j) % 10) % 10){
    								if(f[d][sum][tx][ty] > i + j){
    									f[d][sum][tx][ty] = i + j;
    								}
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    	for(int x = 0;x < 10;++x){
    		for(int y = 0;y < 10;++y){
    			for(int i = 0;i < sz(s) - 1;++i){
    				if(f[s[i + 1] - '0'][s[i] - '0'][x][y] == inf){
    					ans[x][y] = -1;
    					break;
    				}
    				ans[x][y] += max(0,f[s[i + 1] - '0'][s[i] - '0'][x][y] - 1);
    			}
    		}
    	}
    	for(int i = 0;i < 10;++i){
    		for(int j = 0;j < 10;++j){
    			cout<<ans[i][j]<<' ';
    		}
    		cout<<'\n';
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
