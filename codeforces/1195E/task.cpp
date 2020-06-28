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

	const int N = 3e3 + 3;
	vector <ll> minVal[N];
	ll g[N * N],h[N][N];
	int n,m,a,b;
	ll x,y,z;
	ll ans = 0;

    void solve(){
    	cin>>n>>m>>a>>b;
    	cin>>g[0]>>x>>y>>z;
    	for(int i = 1;i <= m*n;++i){
    		g[i] = ((g[i - 1] * x) % z + y % z) % z;
    	}
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			h[i][j] = g[(i - 1) * m + j - 1];
    		}
    	}
    	for(int i = 1;i <= n;++i){
    		minVal[i].emp(0);
    		deque <int> dq;
    		for(int j = 1;j <= m;++j){
    			while(!dq.empty() and h[i][dq.back()] >= h[i][j]){
    				dq.pop_back();
    			}
    			while(!dq.empty() and dq.front() + b - 1 < j){
    				dq.pop_front();
    			}
    			dq.push_back(j);
                if(j >= b){
                    minVal[i].emp(h[i][dq.front()]);
                }
    		}
    	}
    	for(int j = 1;j <= m - b + 1;++j){
    		deque <int> dq;
    		for(int i = 1;i <= n;++i){
    			while(!dq.empty() and minVal[dq.back()][j] >= minVal[i][j]){
    				dq.pop_back();
    			}
    			while(!dq.empty() and dq.front() + a - 1 < i){
    				dq.pop_front();
    			}
    			dq.push_back(i);
                if(i >= a){
                    ans += minVal[dq.front()][j];
    			}
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
