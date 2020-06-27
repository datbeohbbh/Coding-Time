
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
	int a[N / 5],que_l[N],que_r[N],que_k[N];
	int n,q;

	class PersistentSegmentTree{
	public:
		PersistentSegmentTree *left,*right;
		int sum;
		PersistentSegmentTree(int _sum):sum(_sum),left(nullptr),right(nullptr){};
		PersistentSegmentTree(PersistentSegmentTree *_left,PersistentSegmentTree *_right):left(_left),right(_right),sum(0){
			if(_left)sum += _left -> sum;
			if(_right)sum += _right -> sum;
		}
	public:
		PersistentSegmentTree* build(int l,int r){
			if(l == r){
				return new PersistentSegmentTree(0);
			}
			int mid = (l + r) >> 1;
			return new PersistentSegmentTree(build(l,mid),build(mid + 1,r));
		}
		PersistentSegmentTree* updateNode(PersistentSegmentTree *cur,int pos,int l,int r){
			if(l > r or r < pos or l > pos){
				return nullptr;
			}
			if(l == r){
				return new PersistentSegmentTree(cur -> sum + 1);	
			}
			int mid = (l + r) >> 1;
			if(pos <= mid){
				return new PersistentSegmentTree(updateNode(cur -> left,pos,l,mid),cur -> right);
			} else {
				return new PersistentSegmentTree(cur -> left,updateNode(cur -> right,pos,mid + 1,r));
			}
		}
		int f(PersistentSegmentTree *tleft,PersistentSegmentTree *tright,int tl,int tr,int l,int r){
			if(l > r or r < tl or l > tr){
				return 0;
			}
			if(tl <= l and r <= tr){
				return tright -> sum - tleft -> sum;
			}
			int mid = (l + r) >> 1;
			return f(tleft -> left,tright -> left,tl,tr,l,mid) + f(tleft -> right,tright -> right,tl,tr,mid + 1,r);
		}
	};
	PersistentSegmentTree* *root;

void solve(){
	vector <int> ve;
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>a[i];
		ve.emplace_back(a[i]);
	}
	cin>>q;
	for(int i = 1;i <= q;++i){
		cin>>que_l[i]>>que_r[i]>>que_k[i];
		ve.emplace_back(que_k[i]);
	}
	sort(all(ve));
	ve.erase(unique(all(ve)),ve.end());
	for(int i = 1;i <= n;++i){
		a[i] = lower_bound(all(ve),a[i]) - ve.begin();
	}
	for(int i = 1;i <= q;++i){
		que_k[i] = lower_bound(all(ve),que_k[i]) - ve.begin();
	}
	int len = n + q;
	root = new PersistentSegmentTree* [n + 1];
	PersistentSegmentTree *ans = new PersistentSegmentTree(0);
	root[0] = root[0] -> build(0,len);
	for(int i = 1;i <= n;++i){
		root[i] = root[i] -> updateNode(root[i - 1],a[i],0,len);
	}
	for(int i = 1;i <= q;++i){
		--que_l[i];
		cout<<que_r[i] - que_l[i] - ans -> f(root[que_l[i]],root[que_r[i]],0,que_k[i],0,len)<<'\n';
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
