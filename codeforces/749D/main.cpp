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
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

	const int N = 2e5 + 5;
	int a[N],b[N];
	vector <int> t[N];
	vector <int> idx;
	int n,q;

void solve(){
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>a[i]>>b[i];
		t[a[i]].emplace_back(i);
		idx.emplace_back(a[i]);
	}
	sort(all(idx));
	idx.erase(unique(all(idx)),idx.end());
	set <pii> ms;
	ms.insert(make_pair(0,0));
	for(int next_idx : idx){
		if(!t[next_idx].empty()){
			ms.insert(make_pair(t[next_idx].back(),next_idx));
		}
	}
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		vector <int> li;
		for(int i = 1;i <= k;++i){
			int val;
			cin>>val;
			li.emplace_back(val);
		}
		for(int val : li){
			if(!t[val].empty()){
				ms.erase(make_pair(t[val].back(),val));
			}
		}
		int pos = 0;
		if(ms.size() > 1){
			pii rear = *ms.rbegin();
			ms.erase(ms.find(rear));
			pii next_rear = *ms.rbegin();
			for(int l = 0,r = t[rear.second].size() - 1,mid = (l +r) >> 1;l <= r;mid = (l + r) >> 1){
				if(next_rear.first <= t[rear.second][mid]){
					pos = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			ms.insert(rear);
			pos = t[rear.second][pos];
		}
        for(int val : li){
            if(!t[val].empty()){
                ms.insert(make_pair(t[val].back(),val));
            }
        }
		cout<<a[pos]<<' '<<b[pos]<<'\n';
	}
}}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
