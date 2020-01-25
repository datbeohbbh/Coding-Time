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

	const int N = 1e2 + 2;
	int a[N],ord[N];
	int n,s = 0;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    		ord[i] = i;
    		s += a[i];
    	}
    	sort(ord + 2,ord + 1 + n,[](const int &i,const int &j){
    		return a[i] < a[j];
    	});
    	int t = a[1];
    	vector <int> ve;
    	ve.emp(1);
    	bool f = false;
    	for(int i = 2;i <= n;++i){
    		if(2*t > s){
    			f = true;
    			break;
    		}
    		if(a[1] >= 2*a[ord[i]]){
    			ve.emp(ord[i]);
    			t += a[ord[i]];
    		}
    	}
    	if(f){
    		cout<<sz(ve)<<'\n';
    		for(int i = 0;i < sz(ve);++i){
    			cout<<ve[i]<<' ';
    		}
    	} else {
    		cout<<0;
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
