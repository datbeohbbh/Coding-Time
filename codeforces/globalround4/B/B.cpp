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

	const int N = 1e6 + 6;
	string s;
	int l[N],r[N];

    void solve(){
    	cin>>s;
    	int t = 0;
    	for(int i = 0;i < sz(s);++i){
    		if(s[i] == 'o'){
    			l[i] = max(0,t - 1);
    			t = 0;
    		} else {
    			int cur = i;
    			while(cur < sz(s) and s[cur] == 'v'){
    				++cur;
    				++t;
    			}
    			i = cur - 1;
    		}
    	}
    	for(int i = 1;i < sz(s);++i){
    		l[i] += l[i - 1];
    	}
    	t = 0;
    	for(int i = sz(s) - 1;i > 0;--i){
    		if(s[i] == 'o'){
    			r[i] = max(0,t - 1);
    			t = 0;
    		} else {
    			int cur = i;
    			while(cur >= 0 and s[cur] == 'v'){
    				--cur;
    				++t;
    			}
    			i = cur + 1;
    		}
    	}
    	for(int i = sz(s) - 1;i > 0;--i){
    		r[i] += r[i + 1];
    	}
    	ll ans = 0;
    	for(int i = 0;i < sz(s);++i){
    		ans += 1LL*(s[i] == 'o')*1LL*l[i]*1LL*r[i];
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
