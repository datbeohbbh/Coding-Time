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
 
	const int N = 3e5 + 5;
	const ll base = 998244353LL;
	map <pii,int> ma;
	int cnt[2][N];
	int a[N],b[N];
	ll f[N],ft[N];
	ll ans = 0;
	int n;
 
    void solve(){
    	cin>>n;
    	if(n == 1){
            cout<<1,exit(0);
    	}
    	for(int i = 1;i <= n;++i){
    		cin>>a[i]>>b[i];
    		++cnt[0][a[i]];
    		++cnt[1][b[i]];
    		++ma[mp(a[i],b[i])];
    	}
    	ft[0] = 1LL;
    	for(int i = 1;i <= n;++i){
    		ft[i] = mul(ft[i - 1],1LL*i,base);
    	}
    	for(int j = 0;j < 2;++j){
    		f[j] = 1LL;
    		for(int i = 1;i <= n;++i){
    			if(cnt[j][i] > 0){
    				f[j] = mul(f[j],ft[cnt[j][i]],base);
    			}
    		}
    	}
    	vector <pair <pii,int> > vec;
    	for(map <pii,int> :: iterator it = ma.begin();it != ma.end();++it){
    		vec.emp(mp(it -> fir,it -> sec));
    	}
    	int c = 0;
    	for(int i = 1;i < sz(vec);++i){
    		if(vec[i - 1].fir.fir <= vec[i].fir.fir and vec[i - 1].fir.sec <= vec[i].fir.sec){
    			++c;
    		}
    	}
    	ll sub = 0;
    	if(c == sz(vec) - 1){
            sub = 1;
    		for(int i = 0;i < sz(vec);++i){
    			sub = mul(sub,ft[vec[i].sec],base);
    		}
    	}
    	ll ans = ft[n];
    	ll k = addmod(f[0],f[1],base);
    	k = submod(k,sub,base);
    	cout<<submod(ans,k,base);
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