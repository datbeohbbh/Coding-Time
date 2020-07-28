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

	const int N = 3e5 + 5;
	vector <pii> h;
	int n;

    void solve(){
    	cin>>n;
    	n>>=1;
    	for(int i = 1;i <= n;++i){
    		int x,y;
    		cin>>x>>y;
    		if(x > y){
    			swap(x,y);
    		}
    		h.emp(mp(x,y));
    	}
    	sort(all(h));
    	vector <int> one,two;
    	for(int i = 0;i < sz(h);++i){
    		if(one.empty() or h[one.back()].sec <= h[i].fir){
    			one.emp(i);
    		} else if(two.empty() or h[two.back()].sec <= h[i].fir){
    			two.emp(i);
    		} else {
    			cout<<-1,exit(0);
    		}
    	}
    	for(int i = 0;i < sz(one);++i){
            int j = one[i];
    		cout<<h[j].fir<<' '<<h[j].sec<<' ';
    	}
    	for(int i = sz(two) - 1;~i;--i){
            int j = two[i];
    		cout<<h[j].sec<<' '<<h[j].fir<<' ';
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
