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
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int N = 1e3 + 3;
	int a[N][N];
	int n,fr = -1,fl = -1;
	ll w;
	vector <vector <ll> > sumRi,sumLe;
	int posRi[N][N],posLe[N][N],idxRi[N][N],idxLe[N][N];

	void clr(){
		sumRi.clear();
		sumLe.clear();
		fr = fl = -1;
		memset(posRi,0,sizeof(posRi));
		memset(posLe,0,sizeof(posLe));
		memset(idxRi,0,sizeof(idxRi));
		memset(idxLe,0,sizeof(idxLe));
	}

	void precalcRi(int k,int j){
		if(posRi[k][j])return ;
		int t = 0;
		sumRi[++fr].emp(0);
		while(k <= n and j <= n){
			posRi[k][j] = ++t;
			idxRi[k][j] = fr;
			sumRi[fr].emp(1LL*a[k][j]);
			++k,++j;
		}
		for(int p = 1;p < sz(sumRi[fr]);++p){
			sumRi[fr][p] += sumRi[fr][p - 1];
		}
	}

	void precalcLe(int k,int j){
		if(posLe[k][j])return ;
		int t = 0;
		sumLe[++fl].emp(0);
		while(k > 0 and j <= n){
			posLe[k][j] = ++t;
			idxLe[k][j] = fl;
			sumLe[fl].emp(1LL*a[k][j]);
			--k,++j;
		}
		for(int p = 1;p < sz(sumLe[fl]);++p){
			sumLe[fl][p] += sumLe[fl][p - 1];
		}
	}

	void precalc(){
		sumRi.assign((n<<1) - 1,vector <ll> ());
		sumLe.assign((n<<1) - 1,vector <ll> ());
		for(int i = 1;i <= n;++i){
			precalcRi(i,1);
			precalcRi(1,i);
		}
		for(int i = 1;i <= n;++i){
			precalcLe(i,1);
			precalcLe(n,i);
		}
	}

	ll calc(int i,int j,int k){
		return (sumRi[idxRi[i][j]][posRi[i][j]] - sumRi[idxRi[i - k + 1][j - k + 1]][posRi[i - k + 1][j - k + 1] - 1])
			+  (sumLe[idxLe[i - k + 1][j]][posLe[i - k + 1][j]] - sumLe[idxLe[i][j - k + 1]][posLe[i][j - k + 1] - 1])
			-  (k & 1 ? 1LL*a[i - (k >> 1)][j - (k >> 1)] : 0);
	}

	bool ok(int k){
		for(int i = k;i <= n;++i){
			for(int j = k;j <= n;++j){
//                ll x = calc(i,j,k);
				if(calc(i,j,k) <= w){
					return true;
				}
			}
		}
		return false;
	}

    void solve(){
    	int T;
    	cin>>T;
    	while(T--){
    		cin>>n>>w;
    		for(int i = 1;i <= n;++i){
    			for(int j = 1;j <= n;++j){
    				cin>>a[i][j];
    			}
    		}
    		precalc();
    		int ans = 0;
    		for(int l = 1,r = n,mid = (l + r)>>1;l <= r;mid = (l + r)>>1){
    			if(ok(mid)){
    				l = mid + 1;
    				ans = mid;
    			} else {
    				r = mid - 1;
    			}
    		}
    		clr();
    		cout<<ans<<'\n';
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
