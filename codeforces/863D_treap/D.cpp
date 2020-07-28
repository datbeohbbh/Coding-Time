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

	const int PRIORITY = 2e9;

	typedef struct node {
		int val,prior,szt;
		bool rev;
		node *l,*r;
		node(){}
		node(int _val,int _szt,int _prior,bool _rev):val(_val),szt(_szt),prior(_prior),rev(_rev),l(NULL),r(NULL){}
	}node;
	typedef node* pnode;

	struct ImplicitTreap{
		pnode tree;
		ImplicitTreap(){
			tree = NULL;
		}

		int cnt_size(pnode t){
			return (t ? t -> szt : 0);
		}

		void upd_size(pnode &t){
			if(t){
				t -> szt = cnt_size(t -> l) + 1 + cnt_size(t -> r);
			}
		}

		void pushdown(pnode &t){
			if(t and t -> rev){
				swap(t -> l,t -> r);
				if(t -> l)t -> l -> rev ^= t -> rev;
				if(t -> r)t -> r -> rev ^= t -> rev;
				t -> rev = false;
			}
		}

		void split(pnode t,pnode &l,pnode &r,int pos,int add = 0){
			pushdown(t);
			if(!t){
				return (void)(l = r = NULL);
			}
			int cur_pos = add + cnt_size(t -> l);
			if(cur_pos < pos){
				split(t -> r,t -> r,r,pos,cur_pos + 1);
				l = t;
			} else {
				split(t -> l,l,t -> l,pos,add);
				r = t;
			}
			upd_size(t);
		}

		void merge(pnode &t,pnode l,pnode r){
			pushdown(l);
			pushdown(r);
			if(!l or !r){
				t = (l ? l : r);
			} else if(l -> prior > r -> prior){
				merge(l -> r,l -> r,r);
				t = l;
			} else {
				merge(r -> l,l,r -> l);
				t = r;
			}
			upd_size(t);
		}

		int get(int pos){
			pnode x,y,z,cur;
			split(tree,x,y,pos - 1);
			split(y,cur,z,1);
			int ret = (cur ? cur -> val : 0);
			merge(tree,x,cur);
			merge(tree,tree,z);
			return ret;
		}

		void ins(int pos,int val){
			pnode x,y,cur;
			cur = new node;
			cur -> val = val,cur -> szt = 1,cur -> prior = rand() % PRIORITY,cur -> rev = false;
			cur -> l = cur -> r = NULL;
			split(tree,x,y,pos - 1);
			merge(tree,x,cur);
			merge(tree,tree,y);
		}

		void modify(int l,int r){
			pnode t1,t2,t3,t4,t5,t6;
			split(tree,t1,t2,l - 1);
			split(t2,t3,t4,r - l);
			split(t4,t5,t6,1);
			merge(tree,t1,t5);
			merge(tree,tree,t3);
			merge(tree,tree,t6);
		}

		void reverse(int l,int r){
			pnode x,y,z,cur;
			split(tree,x,y,l - 1);
			split(y,cur,z,r - l + 1);
			if(cur){
				cur -> rev ^= true;
			}
			merge(tree,x,cur);
			merge(tree,tree,z);
		}
	}treap;

	const int N = 2e5 + 5;
	int n,q,m;
	int a[N];

    void solve(){
    	srand(time(NULL));
    	cin>>n>>q>>m;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	for(int i = 1;i <= n;++i){
    		treap.ins(i,a[i]);
    	}
    	while(q--){
    		int op,l,r;
    		cin>>op>>l>>r; --op;
    		if(op){
    			treap.reverse(l,r);
    		} else {
    			treap.modify(l,r);
    		}
    	}
    	for(int i = 1;i <= m;++i){
    		int p;
    		cin>>p;
    		cout<<treap.get(p)<<' ';
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
