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
	const int inf = -1e9;
	typedef struct node {
		int sum,val,max_pref,max_suff;
		int lazy,ans,prior,szt;
		node *l,*r;
		node(){}
		node(int _sum,int _val,int _max_pref,int _max_suff,int _lazy,int _ans,int _prior,int _szt){
			sum = _sum,val = _val,max_pref = _max_pref,max_suff = _max_suff;
			lazy = _lazy,ans = _ans,prior = _prior,szt = _szt;
			l = r = NULL;
		}
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
			if(t and t -> lazy){
				t -> val += t -> lazy;
				t -> sum += (t -> lazy) * cnt_size(t);
				if(t -> l){
					t -> l -> lazy += t -> lazy;
				}
				if(t -> r){
					t -> r -> lazy += t -> lazy;
				}
				t -> lazy = 0;
			}
		}

		void combine(pnode &t){
			pushdown(t -> l),pushdown(t -> r);
			if(t){
				t -> sum = t -> val;
				if(t -> l)t -> sum += t -> l -> sum;
				if(t -> r)t -> sum += t -> r -> sum;
				t -> ans = max((t -> l ? t -> l -> ans : t -> val),(t -> r ? t -> r -> ans : t -> val));
				maximize(t -> ans,(t -> l ? t -> l -> max_suff : 0) + t -> val + (t -> r ? t -> r -> max_pref : 0));
				t -> max_pref = max(0,(t -> l ? t -> l -> sum : 0) + t -> val + max((t -> r ? t -> r -> max_pref : 0),0));
				maximize(t -> max_pref,(t -> l ? t -> l -> max_pref : 0));
				t -> max_suff = max(0,(t -> r ? t -> r -> sum : 0) + t -> val + max((t -> l ? t -> l -> max_suff : 0),0));
				maximize(t -> max_suff,(t -> r ? t -> r -> max_suff : 0));
			}
		}

		void split(pnode t,pnode &l,pnode &r,int pos,int add = 0){
			if(!t){
				return (void) (l = r = NULL);
			}
            pushdown(t);
			int cur_pos = add + cnt_size(t -> l);
			if(cur_pos < pos){
				split(t -> r,t -> r,r,pos,cur_pos + 1);
				l = t;
			} else {
				split(t -> l,l,t -> l,pos,add);
				r = t;
			}
			upd_size(t);
			combine(t);
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
			combine(t);
		}

		void ins(int pos,int val){
			pnode cur = new node;
			cur -> sum = cur -> val = cur -> max_pref = cur -> max_suff = cur -> ans = val;
			cur -> lazy = 0;
			cur -> szt = 1;
			cur -> prior = rand() % PRIORITY;
			pnode l,r;
			split(tree,l,r,pos - 1);
			merge(tree,l,cur);
			merge(tree,tree,r);
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

		void modify(int l,int r,int val){ //update range
			pnode x,y,z,cur;
			split(tree,x,y,l - 1);
			split(y,cur,z,r - l + 1);
			if(cur){
				cur -> lazy += val;
			}
			merge(tree,x,cur);
			merge(tree,tree,z);
		}

		void modify(int pos,int val){
			modify(pos,pos,-get(pos));
			modify(pos,pos,val);
		}

		int rmq(int l,int r){
			int ret = 0;
			pnode x,y,z,cur;
			split(tree,x,y,l - 1);
			split(y,cur,z,r - l + 1);
			if(cur){
				ret = cur -> ans;
			}
			merge(tree,x,cur);
			merge(tree,tree,z);
			return ret;
		}

		void del(int pos){
			modify(pos,0);
			pnode x,y,z,cur;
			split(tree,x,y,pos - 1);
			split(y,cur,z,1);
			merge(tree,x,z);
		}

	}treap;

    const int N = 1e5 + 5;
    int a[N];
    int n,m;

    void solve(){
    	srand(time(NULL));
    	cin>>n;
    	for(int i = 1;i <= n;++i){
    		cin>>a[i];
    	}
    	for(int i = 1;i <= n;++i){
    		treap.ins(i,a[i]);
    	}
    	cin>>m;
    	while(m--){
    		char op;
    		cin>>op;
    		if(op == 'I'){
    			int x,y;
    			cin>>x>>y;
    			treap.ins(x,y);
    		}
    		else if(op == 'D'){
    			int x;
    			cin>>x;
    			treap.del(x);
    		}
    		else if(op == 'R'){
    			int x,y;
    			cin>>x>>y;
    			treap.modify(x,y);
    		}
    		else {
    			int x,y;
    			cin>>x>>y;
    			cout<<treap.rmq(x,y)<<'\n';
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
