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
	const ll base[] = {1000000007,1000000087};
	const ll c[] = {67,71};
	ll hs[10*N][2],pw[10*N][2];
	string s[N];
	string ans = "";
	int n,len;

	int index(char ch){
		if('A' <= ch and ch <= 'Z'){
			return ch - 'A' + 1;
		}
		else if('a' <= ch and ch <= 'z'){
			return ch - 'a' + 27;
		} else {
			return ch - '0' + 53;
		}
	}

	pll get_hash(int l,int r){
		vector <ll> ve;
		for(int i = 0;i < 2;++i){
			ve.emp((hs[r][i] - hs[l - 1][i] * pw[r - l + 1][i] + base[i] * base[i]) % base[i]);
		}
		return mp(ve[0],ve[1]);
	}

	void upd(int pos){
		for(int i = pos;i < sz(ans);++i){
    		for(int j = 0;j < 2;++j){
    			hs[i][j] = (hs[i - 1][j] * c[j] + 1LL*index(ans[i])) % base[j];
    			pw[i][j] = (pw[i - 1][j] * c[j]) % base[j];
    		}
    	}
	}

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>s[i];
    	}
    	len = sz(s[1]);
    	ans = " " + s[1];
    	pw[0][0] = pw[0][1] = 1;
    	upd(1);
    	for(int i = 2;i <= n;++i){
    		int cur = 1,t = 0;
    		pll hs_cur = mp(index(s[i][0]),index(s[i][0]));
    		while(cur <= min(len,sz(s[i]))){
    			if(get_hash(len - cur + 1,len) == hs_cur){
    				t = cur;
    			}
    			++cur;
    			hs_cur.fir = (hs_cur.fir * c[0] + index(s[i][cur - 1])) % base[0];
    			hs_cur.sec = (hs_cur.sec * c[1] + index(s[i][cur - 1])) % base[1];
    		}
    		--cur;
    		for(int j = t;j < sz(s[i]);++j){
    			ans.pb(s[i][j]);
    		}
    		upd(len + 1);
    		len = sz(ans) - 1;
    	}
    	ans.erase(0,1);
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
