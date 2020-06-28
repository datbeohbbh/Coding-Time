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
	int p[N],pos[N],aux[N];
	int n,k;

    void solve(){
    	cin>>n>>k;
    	int cur = k;
    	for(int i = 1;i <= k;++i){
    		cin>>p[i];
    		pos[p[i]] = i;
    	}
    	int maxperm = *max_element(p + 1,p + 1 + k);
    	for(int i = 1;i <= maxperm;++i){
    		if(!pos[i]){
    			p[++cur] = i;
    			pos[i] = cur;
    		}
    	}
    	stack <int> stk;
    	int j = 1;
    	for(int i = 1;i <= maxperm;++i){
    		if(aux[i]){
    			if(stk.empty()){
    				cout<<-1,exit(0);
    			}
    			if(p[stk.top()] != i){
    				cout<<-1,exit(0);
    			}
    			stk.pop();
    			continue;
    		}
    		while(j <= cur and p[j] != i){
    			stk.push(j);
    			aux[p[j]] = true;
    			++j;
    		}
    		if(p[j] == i){
    			++j;
    		} else {
    			cout<<-1,exit(0);
    		}
    	}
    	for(int i = k + 1;i < maxperm;++i){
            if(p[i] + 1 == p[i + 1]){
                swap(p[i],p[i + 1]);
            }
    	}
    	for(int i = 1;i <= maxperm;++i){
    		cout<<p[i]<<' ';
    	}
    	for(int i = n;i >= 1;--i){
    		if(!pos[i]){
    			cout<<i<<' ';
    		}
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
