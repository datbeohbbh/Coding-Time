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
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int N = 2e5 + 5;
	const int M = 3e3 + 3;
	const ll base = 1e9 + 7;
	ll fact[N],inv_fact[N],dp[N];
	int r[M],c[M],ord[M];
	int h,w,n;

	ll fastExp(ll x,int h){
		ll res = 1;
		for(;h > 0;h >>= 1,x = mul(x,x,base)){
			if(h & 1){
				res = mul(res,x,base);
			}
		}
		return res;
	}

	ll coef(int num,int k){
		return mul(fact[num],mul(inv_fact[k],inv_fact[num - k],base),base);
	}

    void solve(){
    	cin>>h>>w>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>r[i]>>c[i];
    		ord[i] = i;
    	}
    	sort(ord + 1,ord + 1 + n,[&](const int &i,const int &j){
    		return (r[i] < r[j]) or (r[i] == r[j] and c[i] < c[j]);
    	});
    	fact[0] = inv_fact[0] = 1;
    	for(int i = 1;i <= h + w;++i){
    		fact[i] = mul(fact[i - 1],i,base);
    		inv_fact[i] = fastExp(fact[i],base - 2);
    	}
    	r[n + 1] = h,c[n + 1] = w;
    	ord[n + 1] = n + 1;
    	for(int i = 1;i <= n + 1;++i){
    		dp[i] = coef(r[ord[i]] + c[ord[i]] - 2,c[ord[i]] - 1);
    	}
        for(int i = 1;i <= n;++i){
            for(int j = i + 1;j <= n + 1;++j){
                if(r[ord[j]] >= r[ord[i]] and c[ord[j]] >= c[ord[i]]){
                    ll x = coef(r[ord[j]] - r[ord[i]] + c[ord[j]] - c[ord[i]],c[ord[j]] - c[ord[i]]);
                    dp[j] = submod(dp[j],mul(dp[i],x,base),base);
                    // remove all path that go from cell (1,1) to cell i-th to cell j-th,that means there are only paths go through empty cell to get to cell j-th
                }
            }
        }
    	cout<<dp[n + 1];
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
