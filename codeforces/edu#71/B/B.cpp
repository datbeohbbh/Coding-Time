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
#define BIT(x,i) (((x)>>(i))&1LL)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int N = 55;
	int a[N][N],b[N][N];
	int n,m;
	vector <pii> ans;

	int c(int i,int j){
		return a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
	}

    void solve(){
    	cin>>n>>m;
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			cin>>a[i][j];
    		}
    	}
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			if(c(i,j) == 4){
    				b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
    				ans.emp(mp(i,j));
    			}
    		}
    	}
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			if(a[i][j] != b[i][j]){
    				cout<<-1,exit(0);    			}
    		}
    	}
    	cout<<sz(ans)<<'\n';
    	for(int i = 0;i < sz(ans);++i){
    		cout<<ans[i].fir<<' '<<ans[i].sec<<'\n';
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
