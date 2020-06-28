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

	const int N = 1e5 + 5;
	const int lg = 23;
	int a[N],b[N],c[2][lg + 2][lg + 2];
	int cnt[lg + 2][3],tmp[lg + 2][3];
	ll r[lg];
	int n;
	ll ans = 0;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	for(int i = 1;i <= n;++i){
    		cin>>b[i];
    	}
    	for(int i = 0;i <= lg;++i){
    		for(int j = 1;j <= n;++j){
    			++cnt[i][(b[j] >> i) & 1];
    			++tmp[i][(b[j] >> i) & 1];
    		}
    	}
    	for(int i = 0;i < lg;++i){
    		for(int j = 1;j <= n;++j){
    			if(BIT(a[j],i) and !BIT(a[j],i + 1)){
    				++c[0][i][i + 1];
    			} 
    			if(BIT(a[j],i) and BIT(a[j],i + 1)){
    				++c[1][i][i + 1];
    			}
    		}
    	}
    	for(int j = 1;j <= n;++j){
    		for(int i = 0;i <= lg;++i){
    			ll t = 0;
    			int x = (a[j] >> i) & 1;
    			t += 1LL*cnt[i][x ^ 1];
    			if(x){
    				t += 1LL*cnt[i][2];
    				cnt[i + 1][1] += c[0][i][i + 1];
    				cnt[i + 1][0] -= c[0][i][i + 1];
    				cnt[i + 1][2] += c[1][i][i + 1];
    				cnt[i + 1][1] -= c[1][i][i + 1];
    			}
    			r[i] += t;
    		}
    		for(int i = 0;i <= lg;++i){
    			cnt[i][0] = tmp[i][0];
    			cnt[i][1] = tmp[i][1];
    			cnt[i][2] = tmp[i][2];
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
