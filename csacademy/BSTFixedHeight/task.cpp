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

	const int N = 5e2 + 5;
	const int base = 1e9 + 7;
	int f[N][N],dp[N][N];
	int n,h;

	int calc(int node,int cur){
        if(!node)return 0;
		if(cur == h){
			return (node == 1);
		}
		if(~f[node][cur])return f[node][cur];
		int ret = 0;
		for(int used = 0;used < node;++used){
			int x = calc(used,cur + 1);
			int y = calc(node - 1 - used,cur + 1);
            ret|=x|y;
//			ret |= calc(used,cur + 1)|calc(node - 1 - used,cur + 1);
		}
		return f[node][cur] = ret;
	}

	int sol(int node,int cur){
		if(!node){
			return 1;
		}
		if(cur == h){
			return (node == 1);
		}
		if(~dp[node][cur])return dp[node][cur];
		int ret = 0;
		for(int used = 0;used < node;++used){
			int x = calc(used,cur + 1) % base;
			int y = calc(node - 1 - used,cur + 1) % base;
			ret = addmod(ret,mul(x,y,base),base);
		}
		if(f[node][cur]){
			dp[node][cur] = ret;
		}
		return 0;
	}

    void solve(){
    	cin>>n>>h;
    	memset(f,-1,sizeof(f));
    	memset(dp,-1,sizeof(dp));
    	calc(n,1);
    	cout<<sol(n,1);
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
