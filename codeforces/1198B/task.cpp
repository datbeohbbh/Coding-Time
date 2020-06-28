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

	const int N = 2e5 + 5;
	int a[N],ans[N];
	int n,q;
	multiset <pii> ms[2];

    void solve(){
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    		ms[1].insert(mp(a[i],i));
    	}
    	ms[0].insert(mp(-1,0));
    	cin>>q;
    	while(q--){
    		int op,p,x;
    		cin>>op; --op;
    		if(!op){
    			cin>>p>>x;
    			if(ms[0].find(mp(a[p],p)) != ms[0].end()){
    				ms[0].erase(mp(a[p],p));
    			} else {
    				ms[1].erase(mp(a[p],p));
    			}
    			a[p] = x;
    			ms[1].insert(mp(a[p],p));
    		} else {
    			cin>>x;
    			if(ms[0].rbegin() -> fir < x){
    				ms[0].erase(*ms[0].rbegin());
    				ms[0].insert(mp(x,0));
    			}
    			while(!ms[1].empty() and ms[1].begin() -> fir < x){
    				ms[0].insert(*ms[1].begin());
    				ms[1].erase(ms[1].begin());
    			}
    		}
    	}
        for(multiset <pii> :: iterator it = ms[0].begin();it != ms[0].end();++it){
            ans[it -> sec] = ms[0].rbegin() -> fir;
        }
        for(multiset <pii> :: iterator it = ms[1].begin();it != ms[1].end();++it){
            ans[it -> sec] = it -> fir;
        }
    	for(int i = 1;i <= n;++i){
    		cout<<ans[i]<<' ';
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
