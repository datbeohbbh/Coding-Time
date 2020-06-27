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

	const int N = 5e5 + 5;
	int ord[N],l[N],r[N],f[N];
	vector <int> compress;
	int n;

	struct FenwickTree{
		vector <int> ft;
		FenwickTree(){
			ft.resize((N<<2) + 2,0);
		}
		void upd(int node,int val){
			for(;node <= (N<<2);node += node & (-node)){
				maximize(ft[node],val);
			}
		}
		int rmq(int node){
			int ret = 0;
			for(;node > 0;node -= node & (-node)){
				maximize(ret,ft[node]);
			}
			return ret;
		}
	}fen;

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>l[i]>>r[i];
    		ord[i] = i;
    		compress.emp(l[i] - 1);
    		compress.emp(l[i]);
    		compress.emp(r[i]);
    		compress.emp(r[i] + 1);
    	}
    	sort(all(compress));
    	for(int i = 1;i <= n;++i){
    		l[i] = lower_bound(all(compress),l[i]) - compress.begin() + 1;
    		r[i] = lower_bound(all(compress),r[i]) - compress.begin() + 1;
    	}
    	sort(ord + 1,ord + 1 + n,[](const int &i,const int &j){
    		return (l[i] < l[j]) or (l[i] == l[j] and r[i] < r[j]);
    	});
    	int ans = 1;
    	for(int i = 1;i <= n;++i){
    		int j = ord[i];
    		maximize(f[j],fen.rmq(l[j] - 1) + 1);
    		fen.upd(r[j],f[j]);
    		maximize(ans,f[j]);
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
