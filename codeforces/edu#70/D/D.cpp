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

	ll c(int x){
		return 1LL*x*1LL*(x - 1) / 2LL;
	}

    void solve(){
    	int t;
    	cin>>t;
    	while(t--){
    		ll n;
    		cin>>n;
    		int y = 1;
    		for(;y + 2 <= 100000;++y){
    			if(c(y) > n){
    				break;
    			}
    		}
    		ll d = n - c(--y);
    		string s = " 1";
    		for(int i = 1;i <= y;++i){
    			s.pb('3');
    		}
    		s.pb('7');
    		vector <int> pos;
    		int po = 1;
    		int pt = y + 1;
    		while(d > 0 and pt + 1 <= 100000){
    			while(c(pt - po) > d){
    				++po;
    			}
    			d -= c(pt - po);
    			pos.emp(++po);
    			++pt;
    		}
    		for(int i = 0;i < sz(pos);++i){
    			s.insert(pos[i],"1");
    		}
    		s.erase(0,1);
    		cout<<s<<'\n';
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
