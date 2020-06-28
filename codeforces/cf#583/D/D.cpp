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
 
	const ll base = 1000048453LL;
	vector < vector <char> > a;
    vector < vector <ll> > dp[2];
	int n,m;
 
	bool insize(int u,int v){
		return 1 <= u and u <= n and 1 <= v and v <= m and a[u][v] == '.';
	}
 
    void solve(){
    	cin>>n>>m;
    	a.resize(n + 1,vector <char> (m + 1));
    	for(int i = 1;i <= n;++i){
    		for(int j = 1;j <= m;++j){
    			cin>>a[i][j];
    		}
    	}
    	for(int i = 0;i < 2;++i){
            dp[i].resize(n + 1,vector <ll> (m + 1,0LL));
        }
        dp[0][1][1] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(!(i == 1 and j == 1)){
                    if(a[i][j] == '.'){
                        dp[0][i][j] = addmod(insize(i - 1,j) ? dp[0][i - 1][j] : 0LL,insize(i,j - 1) ? dp[0][i][j - 1] : 0LL,base);
                    }
                }
            }
        }
        if(!dp[0][n][m]){
            cout<<0,exit(0);
        }
        dp[1][n][m] = 1;
        for(int i = n;i >= 1;--i){
            for(int j = m;j >= 1;--j){
                if(!(i == n and j == m)){
                    if(a[i][j] == '.'){
                        dp[1][i][j] = addmod(insize(i + 1,j) ? dp[1][i + 1][j] : 0LL,insize(i,j + 1) ? dp[1][i][j + 1] : 0LL,base);
                    }
                }
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if((i == 1 and j == 1) or (i == n and j == m)){
                    continue;
                }
                if(mul(dp[0][i][j],dp[1][i][j],base) == dp[0][n][m]){
                    cout<<1,exit(0);
                }
            }
        }
        cout<<2;
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