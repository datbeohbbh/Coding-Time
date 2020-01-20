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
	const int inf =1e9;
	int a[N],b[N];
	int n,TEST;
	set <int> heap[N];

	struct SegmentTree{
		vector <int> tree;
		void init(int _size){
			tree.assign((_size + 1)<<2,inf);
		}
		void update(int pos,int val,int l = 1,int r = n,int node = 1){
			if(l > r or r < pos or l > pos){
				return ;
			}
			if(l == r){
				return (void)(tree[node] = val);
			}
			int mid = (l + r) >> 1;
			if(pos <= mid){
				update(pos,val,l,mid,node<<1);
			} else {
				update(pos,val,mid + 1,r,node<<1|1);
			}
			tree[node] = min(tree[node<<1],tree[node<<1|1]);
		}
		int rmq(int tl,int tr,int l = 1,int r = n,int node = 1){
			if(l > r or r < tl or l > tr){
				return inf;
			}
			if(tl <= l and r <= tr){
				return tree[node];
			}
			int mid = (l + r)>>1;
			return min(rmq(tl,tr,l,mid,node<<1),rmq(tl,tr,mid + 1,r,node<<1|1));
		}
	}seg;

    void solve(){
    	cin>>TEST;
    	while(TEST--){
    		cin>>n;
    		seg.init(n);
    		for(int i = 1;i <= n;++i){
    			cin>>a[i];
    			seg.update(i,a[i]);
    		}
    		for(int i = 1;i <= n;++i){
    			cin>>b[i];
    		}
    		for(int i = 1;i <= n;++i){
    			heap[a[i]].insert(i);
    		}
    		bool flag = true;
    		for(int i = 1;i <= n;++i){
    			if(heap[b[i]].empty()){
    				flag = false;
    				break;
    			}
    			int r = *heap[b[i]].begin();
    			if(seg.rmq(1,r) != b[i]){
    				flag = false;
    				break;
    			}
    			seg.update(r,inf);
    			heap[b[i]].erase(heap[b[i]].find(r));
    		}
    		cout<<(flag ? "YES\n" : "NO\n");
    		for(int i = 1;i <= n;++i){
    			heap[a[i]].clear();
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
